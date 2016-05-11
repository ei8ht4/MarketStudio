#pragma once

#ifndef interface
#define interface __interface
#endif

// ���ݷ��ʵĴ�����Ϣ
enum DataAccess_Error
{
	DataAccess_Error_OK = 0,
	DataAccess_Error_Unknown = 0xFFFF,
};

// ���ݷ��ʻص�
interface IDataAccessCallback
{
	virtual void DataAccess_OnData(const char *pszContent) {}
	virtual void DataAccess_OnError(DataAccess_Error err) {}
};

// ���ݷ��ʽӿ�
interface IDataAccess
{
	virtual bool		Init(const char *pszToken) = 0;
	virtual bool		GetData(const char *pszUrl, IDataAccessCallback *pCallback) = 0;
};
