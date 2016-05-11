#pragma once

#include "IDataAccess.h"

// 优矿数据访问 (www.uqer.io)
// 实现在UqerDataAccessImpl.cpp中

class CUqerDataAccessImpl;

class CUqerDataAccess : public IDataAccess
{
public:
	CUqerDataAccess();
	virtual ~CUqerDataAccess();
	
	virtual bool Init(const char *pszToken);
	virtual bool GetData(const char *pszUrl, IDataAccessCallback *pCallback);

private:
	CUqerDataAccessImpl *m_pImpl;
};

