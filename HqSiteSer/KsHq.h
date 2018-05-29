#pragma once
#include "KSGMdAPI.h"
class KsHq:KingstargoldMdAPI::CKSGMdSpi
{
public:
	KsHq();
	~KsHq();
	bool InitEnv(KingstargoldMdAPI::CKSGMdApi *api);
	KingstargoldMdAPI::CKSGMdApi *KsApi;
	int		port;
	char	ip[32];
	//已连接
	virtual void OnFrontConnected();
	//未连接
	virtual void OnFrontDisconnected();
	//踢除用户  
	virtual void OnKickOff();
	//登录应答
	virtual void OnRspUserLogin(const CKSG_RspInfoField *pRspMsg, const CKSG_RspUserLoginField *pRspUserLogin, bool bIsLast);
	//登出应答
	virtual void OnRspUserLogout(const CKSG_RspInfoField *pRspMsg, const CKSG_RspUserLogoutField *pRspUserLogout, bool bIsLast);
	//行情服务的深度行情通知
	virtual void OnMarketDataMblQuot(const CKSG_DepthMarketDataField *pfldDepthMarketData);


};

