#include "KsHq.h"
#include "KSGMdAPI.h"
#include "CFunc.h"
#include "CGlobal.h"
#include "Instrument.h"
#include "struct.h"
#include <string.h>

KsHq::KsHq()
{
	KsApi = NULL;
}


KsHq::~KsHq()
{
}

bool KsHq::InitEnv(KingstargoldMdAPI::CKSGMdApi *api)
{
	KsApi = api;
	KsApi->RegisterSpi(this);
	return true;
}
//已连接
void KsHq::OnFrontConnected()
{
}
//未连接
void KsHq::OnFrontDisconnected()
{
	WriteLog(2, "KStart diconnect");
	KsApi->RegisterServer(ip, port);
}
//踢除用户  
void KsHq::OnKickOff()
{
	WriteLog(2, "KStart ccount kick off");
}
//登录应答
void KsHq::OnRspUserLogin(const CKSG_RspInfoField *pRspMsg, const CKSG_RspUserLoginField *pRspUserLogin, bool bIsLast)
{
	if (pRspMsg->ErrCode == 0)
	{
		WriteLog(2, "KStart account login sucess");
	}
	else
	{
		WriteLog(2, pRspMsg->RspMsg);
	}
};
//登出应答
void KsHq::OnRspUserLogout(const CKSG_RspInfoField *pRspMsg, const CKSG_RspUserLogoutField *pRspUserLogout, bool bIsLast)
{
	if (0 == pRspMsg->ErrCode)
	{
		WriteLog(2,"KStart account logout ");

	}
	else
	{
		WriteLog(2, pRspMsg->RspMsg);
	}
};
//行情服务的深度行情通知
void KsHq::OnMarketDataMblQuot(const CKSG_DepthMarketDataField *pfldDepthMarketData)
{
// 	char str[1024] = {0};
// 	sprintf(str,"%s  Code:%s		Last%.4f \tHigh%.4f  \tLow%.4f  \tBid1%.4f  \tAsk1%.4f", pfldDepthMarketData->QuoteTime, pfldDepthMarketData->ContractID, pfldDepthMarketData->LastPrice, pfldDepthMarketData->HighPrice, pfldDepthMarketData->LowPrice, pfldDepthMarketData->BidPrice1, pfldDepthMarketData->AskPrice1);
// 	WriteLog(3, str);
	Instrument *pins = NULL;
	if (!LookupInstrument(MARKET_KSTART,(char*)pfldDepthMarketData->ContractID,pins))
	{
		return;
	}
	st_market pmarket;
	pmarket.TradingDay= atoi( pfldDepthMarketData->TradingDay);
	strcpy(pmarket.code, pfldDepthMarketData->ContractID);
	strcpy(pmarket.jys, "");	//交易所
	pmarket.QuoteDate=atoi( pfldDepthMarketData->QuoteDate);
	string str = pfldDepthMarketData->QuoteTime;
	string_replace_2(str, ":", "");
	pmarket.QuoteTime =atoi(str.c_str());
	pmarket.LastPrice = pfldDepthMarketData->LastPrice;
	pmarket.HighPrice = pfldDepthMarketData->HighPrice;
	pmarket.LowPrice = pfldDepthMarketData->LowPrice;
	pmarket.TradeQty = pfldDepthMarketData->MatchTotQty;
	pmarket.TradeWeight = pfldDepthMarketData->MatchWeight;
	pmarket.Turnover = pfldDepthMarketData->Turnover;
	pmarket.OpenInterest = pfldDepthMarketData->OpenInterest;
	pmarket.OpenPrice = pfldDepthMarketData->OpenPrice;
	pmarket.ClosePrice = pfldDepthMarketData->ClosePrice;
	pmarket.ClearPrice = pfldDepthMarketData->ClearPrice;
	pmarket.LastClearPrice = pfldDepthMarketData->LastClearPrice;
	pmarket.LastClose = pfldDepthMarketData->LastClose;
	pmarket.RiseLimit = pfldDepthMarketData->RiseLimit;
	pmarket.FallLimit = pfldDepthMarketData->FallLimit;
	pmarket.UpDown = pfldDepthMarketData->UpDown;
	pmarket.UpDownRate = pfldDepthMarketData->UpDownRate;
	pmarket.AveragePrice = pfldDepthMarketData->AveragePrice;
	pmarket.AskPrice[0] = pfldDepthMarketData->AskPrice1;
	pmarket.AskPrice[1] = pfldDepthMarketData->AskPrice2;
	pmarket.AskPrice[2] = pfldDepthMarketData->AskPrice3;
	pmarket.AskPrice[3] = pfldDepthMarketData->AskPrice4;
	pmarket.AskPrice[4] = pfldDepthMarketData->AskPrice5;

	pmarket.AskVolume[0] = pfldDepthMarketData->AskVolume1;
	pmarket.AskVolume[1] = pfldDepthMarketData->AskVolume2;
	pmarket.AskVolume[2] = pfldDepthMarketData->AskVolume3;
	pmarket.AskVolume[3] = pfldDepthMarketData->AskVolume4;
	pmarket.AskVolume[4] = pfldDepthMarketData->AskVolume5;

	pmarket.BidPrice[0] = pfldDepthMarketData->BidPrice1;
	pmarket.BidPrice[1] = pfldDepthMarketData->BidPrice2;
	pmarket.BidPrice[2] = pfldDepthMarketData->BidPrice3;
	pmarket.BidPrice[3] = pfldDepthMarketData->BidPrice4;
	pmarket.BidPrice[4] = pfldDepthMarketData->BidPrice5;

	pmarket.BidVolume[0] = pfldDepthMarketData->BidVolume1;
	pmarket.BidVolume[1] = pfldDepthMarketData->BidVolume2;
	pmarket.BidVolume[2] = pfldDepthMarketData->BidVolume3;
	pmarket.BidVolume[3] = pfldDepthMarketData->BidVolume4;
	pmarket.BidVolume[4] = pfldDepthMarketData->BidVolume5;

	pins->AddMkt(&pmarket);
};
