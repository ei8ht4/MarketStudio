#include "UqerDataAccessImpl.h"
#include "UqerDataAccess.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>

/////////////////////////////////////// interface /////////////////////////////
CUqerDataAccess::CUqerDataAccess()
{
	m_pImpl = new CUqerDataAccessImpl;
}

CUqerDataAccess::~CUqerDataAccess()
{
	if (m_pImpl)
	{
		delete m_pImpl;
		m_pImpl = NULL;
	}
}

bool CUqerDataAccess::Init(const char *pszToken)
{
	return m_pImpl->Init(pszToken);
}

bool CUqerDataAccess::GetData(const char *pszUrl, IDataAccessCallback *pCallback)
{
	return m_pImpl->GetData(pszUrl, pCallback);
}

/////////////////////////////////////// impl //////////////////////////////////


CUqerDataAccessImpl::CUqerDataAccessImpl()
	: m_pNAM(NULL)
	, m_pReply(NULL)
	, m_bReplyIsUtf8(true)
	, m_pCallback(NULL)
{
}


CUqerDataAccessImpl::~CUqerDataAccessImpl()
{
	if (m_pNAM)
	{
		delete m_pNAM;
		m_pNAM;
	}
}

bool CUqerDataAccessImpl::Init(const char *pszToken)
{
	m_strToken = pszToken;
	if (m_strToken.isEmpty())
		return false;

	return true;
}

static const char* g_NonUtf8Type[] = { ".csv?"};

static bool IsUtf8(const QString &strUrl)
{
	for (int i = 0; i < _countof(g_NonUtf8Type); ++i)
	{
		if (strUrl.indexOf(g_NonUtf8Type[i]) > 0)
			return false;
	}
	return true;
}

bool CUqerDataAccessImpl::GetData(const char *pszUrl, IDataAccessCallback *pCallback)
{
	if (m_strToken.isEmpty())
		return false;

	m_pCallback = pCallback;

	QString strAuthHeader = "Bearer " + m_strToken;

	QString strUrl = pszUrl;
	if (strUrl.compare("Location") != 0)	// 不是重定向
	{
		strUrl.insert(0, "https://api.wmcloud.com/data/v1");
	}
	//if (strUrl.indexOf(".csv?") > 0)
	//{
	//	m_bReplyIsUtf8 = false;
	//}
	m_bReplyIsUtf8 = IsUtf8(strUrl);

	if (m_pNAM == NULL)
		m_pNAM = new QNetworkAccessManager;

	QNetworkRequest oRequest;
	oRequest.setUrl(QUrl(strUrl));
	oRequest.setRawHeader("Authorization", strAuthHeader.toUtf8());
	oRequest.setAttribute(QNetworkRequest::CustomVerbAttribute, "GET");

	m_pReply = m_pNAM->get(oRequest);
	if (m_pReply == NULL)
		return false;

	qRegisterMetaType<QNetworkReply::NetworkError>("QNetworkReply::NetworkError");

	connect(m_pReply, SIGNAL(finished()), this, SLOT(slot_httpFinished()));
	connect(m_pReply, SIGNAL(error(QNetworkReply::NetworkError)), this,
		SLOT(slot_httpError(QNetworkReply::NetworkError)));

	return true;
}

void CUqerDataAccessImpl::slot_httpFinished()
{
	int nHttpStatus = m_pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

	m_pReply->close();
	m_pReply->deleteLater();

	if (nHttpStatus == 302)	// 重定向
	{
		GetData("Location", m_pCallback);
	}
	else
	{
		QString strReply;
		if (m_bReplyIsUtf8)
		{
			strReply = QString::fromUtf8(m_pReply->readAll());
		}
		else
		{
			strReply = QString::fromLocal8Bit(m_pReply->readAll());
		}
		if (m_pCallback)
		{
			if (m_pReply->error() == QNetworkReply::NoError)
			{
				m_pCallback->DataAccess_OnData(strReply.toUtf8().data());
			}
			else
			{
				m_pCallback->DataAccess_OnError(DataAccess_Error_Unknown);
			}
		}
	}
}

void CUqerDataAccessImpl::slot_httpError(QNetworkReply::NetworkError err)
{
	if (m_pCallback)
	{
		m_pCallback->DataAccess_OnError(DataAccess_Error_Unknown);
	}
}
