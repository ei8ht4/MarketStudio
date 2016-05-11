#include "DataEngine.h"

#ifndef NULL
#define NULL 0
#endif

namespace DataEngine
{
	ILiveDataManager* CreateLiveDataManager()
	{
		return NULL;
	}

	IHistoryDataManager* CreateHistoryDataManager()
	{
		return NULL;
	}

	IContractManager* CreateContractManager()
	{
		return NULL;
	}

	void ReleaseLiveDataManager(ILiveDataManager *pInst)
	{
		if(pInst)
			delete pInst;
	}

	void ReleaseHistoryDataManager(IHistoryDataManager *pInst)
	{
		if(pInst)
			delete pInst;
	}

	void ReleaseContractManager(IContractManager *pInst)
	{
		if (pInst)
			delete pInst;
	}
}