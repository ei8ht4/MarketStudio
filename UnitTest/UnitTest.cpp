#include "UnitTest.h"
#include "UqerAccessDialog.h"

UnitTest::UnitTest(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

UnitTest::~UnitTest()
{

}

void UnitTest::slot_BtnUqerAccess()
{
	CUqerAccessDialog dlg;
	dlg.exec();
}
