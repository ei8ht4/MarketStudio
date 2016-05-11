#pragma once
#include "IDataAccess.h"

#ifdef DATAENGINE_LIB
#define DATAENGINE_API extern "C" _declspec(dllexport)
#else
#define DATAENGINE_API extern "C" _declspec(dllimport)
#endif

namespace DataEnginTest
{
	DATAENGINE_API IDataAccess* CreateDataAccess();
	DATAENGINE_API void ReleaseDataAccess(IDataAccess *pInst);
}
