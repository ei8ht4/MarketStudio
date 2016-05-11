#include "UqerAccessDialog.h"
#include "../DataEngine/TestExport.h"
#include <QtWidgets/QMessageBox>

using namespace DataEnginTest;

CUqerAccessDialog::CUqerAccessDialog(QWidget *parent)
	: QDialog(parent)
	, m_pDataAccess(NULL)
{
	ui.setupUi(this);
}

CUqerAccessDialog::~CUqerAccessDialog()
{
	if (m_pDataAccess)
	{
		ReleaseDataAccess(m_pDataAccess);
		m_pDataAccess = NULL;
	}
}

void CUqerAccessDialog::DataAccess_OnData(const char *pszContent)
{
	ui.m_editReply->setText(pszContent);
}

void CUqerAccessDialog::DataAccess_OnError(DataAccess_Error err)
{
	ui.m_editReply->setText("Some Error!!!!");
}

void CUqerAccessDialog::slot_BtnGetDate()
{
	if (m_pDataAccess == NULL)
		m_pDataAccess = CreateDataAccess();

	QString strToken = ui.m_editToken->text();
	QString strUrl = ui.m_editURL->text();
	if (strToken.isEmpty() || strUrl.isEmpty())
	{
		QMessageBox::warning(this, "getdata", "wrong information");
		return;
	}

	m_pDataAccess->Init(strToken.toUtf8().data());
	m_pDataAccess->GetData(strUrl.toUtf8().data(), this);
}
