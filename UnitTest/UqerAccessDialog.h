#ifndef UQERACCESSDIALOG_H
#define UQERACCESSDIALOG_H

#include <QDialog>
#include "ui_UqerAccessDialog.h"
#include "../DataEngine/IDataAccess.h"

class CUqerAccessDialog : public QDialog, public IDataAccessCallback
{
	Q_OBJECT

public:
	CUqerAccessDialog(QWidget *parent = 0);
	~CUqerAccessDialog();

protected:
	virtual void DataAccess_OnData(const char *pszContent) override;
	virtual void DataAccess_OnError(DataAccess_Error err) override;

protected slots:
	void slot_BtnGetDate();

private:
	Ui::CUqerAccessDialog ui;

	IDataAccess *m_pDataAccess;
};

#endif // UQERACCESSDIALOG_H
