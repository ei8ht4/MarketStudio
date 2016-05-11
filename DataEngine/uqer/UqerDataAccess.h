#pragma once

#include "IDataAccess.h"

// �ſ����ݷ��� (www.uqer.io)
// ʵ����UqerDataAccessImpl.cpp��

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

