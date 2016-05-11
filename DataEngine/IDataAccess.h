#pragma once

#ifndef interface
#define interface __interface
#endif

// 数据访问的错误信息
enum DataAccess_Error
{
	DataAccess_Error_OK = 0,
	DataAccess_Error_Unknown = 0xFFFF,
};

// 数据访问回调
interface IDataAccessCallback
{
	virtual void DataAccess_OnData(const char *pszContent) {}
	virtual void DataAccess_OnError(DataAccess_Error err) {}
};

// 数据访问接口
interface IDataAccess
{
	virtual bool		Init(const char *pszToken) = 0;
	virtual bool		GetData(const char *pszUrl, IDataAccessCallback *pCallback) = 0;
};
