#ifndef KSG_MD_API_H
#define KSG_MD_API_H

#include <stdio.h>

#ifdef KSGMDAPI_EXPORTS
#define KSGMDAPI_LIB __declspec(dllexport)
#else
#ifdef WIN32
#define KSGMDAPI_LIB __declspec(dllimport)
#else
#define KSGMDAPI_LIB 
#endif
#endif
#include "KSGUserApiStruct.h"

namespace KingstargoldMdAPI
{
class CKSGMdSpi 
{
public:
	//已连接
	virtual void OnFrontConnected(){};
	//未连接
	virtual void OnFrontDisconnected(){};
	//踢除用户  
	virtual void OnKickOff(){};
	//登录应答
	virtual void OnRspUserLogin(const CKSG_RspInfoField *pRspMsg,const CKSG_RspUserLoginField *pRspUserLogin,bool bIsLast){};
	//登出应答
	virtual void OnRspUserLogout(const CKSG_RspInfoField *pRspMsg,const CKSG_RspUserLogoutField *pRspUserLogout,bool bIsLast){};
	//行情服务的深度行情通知
	virtual void OnMarketDataMblQuot(const CKSG_DepthMarketDataField *pfldDepthMarketData){};
			 
};

class KSGMDAPI_LIB CKSGMdApi
{
public: 
	//创建接口
	static CKSGMdApi *CreateKSGMdApi();
	//释放接口
	virtual void Release()=0;
public:
	//注册回调接口
	virtual void RegisterSpi(CKSGMdSpi *pKSGMdSpi)=0;
	//订阅私有流
	virtual int SubscribePrivateFlow(bool restartflag=false)=0;
	//订阅公共流
	virtual int SubscribePublicFlow(bool restartflag=false)=0;
	//注册前置地址
	virtual int RegisterServer(char *ip,int port)=0;
	//初始化
	virtual void Init(bool logflag=true)=0;
	//等待线程结束
	virtual void Join()=0;
	//登录请求
	virtual int ReqUserLogin(CKSG_ReqUserLoginField *pUserLoginReq)=0;
	//登出请求
	virtual int ReqUserLogout(CKSG_ReqUserLogoutField *pUserLogoutReq)=0;


protected:
	virtual ~CKSGMdApi();
};
}
#endif
