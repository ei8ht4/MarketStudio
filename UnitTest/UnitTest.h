#ifndef UNITTEST_H
#define UNITTEST_H

#include <QtWidgets/QDialog>
#include "ui_UnitTest.h"

class UnitTest : public QDialog
{
	Q_OBJECT

public:
	UnitTest(QWidget *parent = 0);
	~UnitTest();

protected slots:
	void slot_BtnUqerAccess();

private:
	Ui::UnitTestClass ui;
};

#endif // UNITTEST_H
