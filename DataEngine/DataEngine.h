#pragma once
#include "ILiveDataManager.h"
#include "IHistoryDataManager.h"
#include "IContractManager.h"

#ifdef DATAENGINE_LIB
#define DATAENGINE_API extern "C" _declspec(dllexport)
#else
#define DATAENGINE_API extern "C" _declspec(dllimport)
#endif

namespace DataEngine
{
	DATAENGINE_API ILiveDataManager*		CreateLiveDataManager();
	DATAENGINE_API IHistoryDataManager*		CreateHistoryDataManager();
	DATAENGINE_API IContractManager*		CreateContractManager();

	DATAENGINE_API void ReleaseLiveDataManager(ILiveDataManager *pInst);
	DATAENGINE_API void ReleaseHistoryDataManager(IHistoryDataManager *pInst);
	DATAENGINE_API void ReleaseContractManager(IContractManager *pInst);
}
