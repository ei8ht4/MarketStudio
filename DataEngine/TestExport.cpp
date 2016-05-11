#include "TestExport.h"
#include "uqer/UqerDataAccess.h"

namespace DataEnginTest
{
	DATAENGINE_API IDataAccess* DataEnginTest::CreateDataAccess()
	{
		return new CUqerDataAccess;
	}

	DATAENGINE_API void DataEnginTest::ReleaseDataAccess(IDataAccess *pInst)
	{
		if (pInst)
		{
			delete pInst;
		}
	}
}
