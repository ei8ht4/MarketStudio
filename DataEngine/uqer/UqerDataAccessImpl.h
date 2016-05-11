#pragma once

#include "IDataAccess.h"
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QNetworkReply>

class QNetworkAccessManager;

class CUqerDataAccessImpl : public QObject
{
	Q_OBJECT
public:
	CUqerDataAccessImpl();
	~CUqerDataAccessImpl();

	bool Init(const char *pszToken);
	bool GetData(const char *pszUrl, IDataAccessCallback *pCallback);

protected slots:
	void slot_httpFinished();
	void slot_httpError(QNetworkReply::NetworkError err);

private:
	QString m_strToken;
	QString m_strResult;
	QNetworkAccessManager	*m_pNAM;
	QNetworkReply			*m_pReply;

	bool m_bReplyIsUtf8;	// 优矿返回的csv内容不是UTF8

	IDataAccessCallback *m_pCallback;
};
