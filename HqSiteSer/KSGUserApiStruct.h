#ifndef KSG_FTDCSTRUCT_H
#define KSG_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "KSGUserApiDataType.h"

///��Ӧ��Ϣ
struct CKSG_RspInfoField
{
	///�������
	TKSG_ErrorIDType	ErrCode;
	///������Ϣ
	TKSG_ErrorMsgType	RspMsg;
	//ʱ���
	TKSG_TimestampType TimeStamp;
};

///�û���¼����
struct CKSG_ReqUserLoginField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///����
	TKSG_PasswordType	Pwd;
};

///�û���¼Ӧ��
struct CKSG_RspUserLoginField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///���׺�������
	TKSG_TimeType	Time;
	///���׺���ʱ��
	TKSG_DateType	Date;
	///����ɹ��ύ�ı������
	TKSG_LatestOrderNo	LatestOrderNo;
};

///�û��ǳ�����
struct CKSG_ReqUserLogoutField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
};

///�û��ǳ�Ӧ��
struct CKSG_RspUserLogoutField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
};

///�û��ʽ��ѯ
struct CKSG_ReqTradingAccountField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
};

///�û��ʽ�Ӧ��
struct CKSG_RspTradingAccountField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///�����ʽ�
	TKSG_MoneyType	Available;
	///ί�ж����ʽ�
	TKSG_MoneyType	FrozenMargin;
	///ռ���ʽ�
	TKSG_MoneyType	OccupyMargin;
	///ƽ��ӯ��
	TKSG_MoneyType	CloseProfit;
};

///�û��ʽ�仯֪ͨ
struct CKSG_RtnTradingAccountField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///�����ʽ�
	TKSG_MoneyType	Available;
	///ί�ж����ʽ�
	TKSG_MoneyType	FrozenMargin;
	///ռ���ʽ�
	TKSG_MoneyType	OccupyMargin;
	///ƽ��ӯ��
	TKSG_MoneyType	CloseProfit;
};

//����ѯ����
struct CKSG_ReqStorageField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///����Ʒ�ִ���
	TKSG_VarietyIDType  VarietyID;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
};

///����ѯӦ��
struct CKSG_RspStorageField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///����Ʒ�ִ���
	TKSG_VarietyIDType  VarietyID;            	
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///�������
	TKSG_WeightType     TotalStorage;         	
	///���ÿ��
	TKSG_WeightType	AvailableStorage;
	///�ֻ�������
	TKSG_WeightType	FrozenStorage;
};

///���仯֪ͨ
struct CKSG_RtnStorageField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///����Ʒ�ִ���
	TKSG_VarietyIDType  VarietyID;            	
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///�������
	TKSG_WeightType     TotalStorage;        	
	///���ÿ��
	TKSG_WeightType	AvailableStorage;
	///�ֻ�������
	TKSG_WeightType	FrozenStorage;
};

///�û��ֲֲ�ѯ
struct CKSG_ReqInvestorPositionField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
};

///�û��ֲ�Ӧ��
struct CKSG_RspInvestorPositionField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///���ճֲ���
	TKSG_VolumeType	LastQty;
	///���ճֲ���
	TKSG_VolumeType	Qty;
	///��ƽ��
	TKSG_VolumeType	OffsetLastQty;
	///��ƽ��
	TKSG_VolumeType	OffsetTodayQty;
	///�ֲֶ�
	TKSG_PriceType		Amt;
	///�ֲ־���
	TKSG_PriceType		AvePrice;
	///���¼�
	TKSG_PriceType		LastPrice;
	///�ֲ�ӯ��
	TKSG_PriceType		FloatProfitLoss;

};

///�û��ֱֲ仯֪ͨ
struct CKSG_RtnInvestorPositionField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///���ճֲ���
	TKSG_VolumeType	LastQty;
	///���ճֲ���
	TKSG_VolumeType	Qty;
	///��ƽ��
	TKSG_VolumeType	OffsetLastQty;
	///��ƽ��
	TKSG_VolumeType	OffsetTodayQty;
	///�ֲֶ�
	TKSG_PriceType		Amt;
	///��֤��
	TKSG_PriceType		Margin;
	///�ֲ־���
	TKSG_PriceType		AvePrice;
	///���¼�
	TKSG_PriceType		LastPrice;
	///�ֲ�ӯ��
	TKSG_PriceType		FloatProfitLoss;

};

///�г�״̬Ӧ��
struct CKSG_RspMarketStatus
{
	///�г�״̬
	TKSG_MktStatusType   MktStatus;           
	///״̬����ʱ��
	TKSG_TimeType	MktChgTime;
};

///�г�״̬�仯֪ͨ
struct CKSG_RtnMarketStatus
{
	///�г�״̬
	TKSG_MktStatusType   MktStatus;           
	///״̬����ʱ��
	TKSG_TimeType	MktChgTime;
};

///��Լ��ѯӦ��
struct CKSG_RspInstrumentField
{
	///��Լ����
	TKSG_InstrumentIDType	ContractID;        
	///��Լ����
	TKSG_InstrumentNameType	ContractName;
	///����Ʒ�ִ���
	TKSG_VarietyIDType   VarietyID;  
	///��Լ��������
	TKSG_VolumeMultipleType	Unit;
	//�Ƽ۵�λ
	TKSG_MeasureUnit   MeasureUnit;         
	///��С�䶯��λ
	TKSG_PriceType	Tick;
	///�м۵�����µ���
	TKSG_VolumeType	MaxHand;
	///�м۵���С�µ���
	TKSG_VolumeType	MinHand;
	///�޼۵�����µ���
	TKSG_VolumeType	MaxMarketOrderVolume;
	///�޼۵���С�µ���
	TKSG_VolumeType	MinMarketOrderVolume;
	///��ͣ��
	TKSG_PriceType		RiseLimit;
	///��ͣ��
	TKSG_PriceType		FallLimit;
	///���ս����
	TKSG_PriceType		LastClearPrice;
};

///�µ�����
struct CKSG_ReqOrderField
{
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///�۸�
	TKSG_PriceType		Price;
	///����
	TKSG_VolumeType	Qty;
	///��������
	TKSG_ByteType	OrderType;
};

///�µ�Ӧ��
struct CKSG_RspOrderField
{
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///�۸�
	TKSG_PriceType		Price;
	///����
	TKSG_VolumeType	Qty;
	///��������
	TKSG_ByteType	OrderType;
};

///�µ��ر�
struct CKSG_RtnOrderField
{
	///ϵͳί�к�
	TKSG_SysOrderNo SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///�۸�
	TKSG_PriceType		Price;
	///����
	TKSG_VolumeType	Qty;
	///��������
	TKSG_ByteType	OrderType;
	///ί��ʱ��
	TKSG_TimeType	OrderTime;
	///״̬
	TKSG_Status	Status;
	///ʣ������
	TKSG_VolumeType	RemainAmt;
};

///��������
struct CKSG_ReqOrderCancelField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///ϵͳί�к�
	TKSG_SysOrderNo SysOrderNo;
};

///����Ӧ��
struct CKSG_RspOrderCancelField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///ϵͳί�к�
	TKSG_SysOrderNo SysOrderNo;
};

///������Ӧ
struct CKSG_RtnOrderCancelField
{
	///�û�����
	TKSG_UserIDType	TraderNo;
	///ϵͳί�к�
	TKSG_SysOrderNo SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///����ʱ��
	TKSG_TimeType	ActionTime;
	///��������
	TKSG_VolumeType	OrderCancelQty;
	///��������
	TKSG_ByteType	OrderType;
};

///�ɽ��ر�֪ͨ
struct CKSG_RtnTradeField
{
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///�ɽ���
	TKSG_MatchNo	MatchNo;
	///�ɽ�ʱ��
	TKSG_TimeType	MatchTime;
	///�ɽ�����
	TKSG_DateType	MatchDate;
	///�ɽ��۸�
	TKSG_PriceType		Price;
	///�ɽ�����
	TKSG_VolumeType	Qty;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
};

///�������
struct CKSG_DepthMarketDataField
{
	///������
	TKSG_DateType	TradingDay;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///���¼�
	TKSG_PriceType	LastPrice;
	///��߼�
	TKSG_PriceType	HighPrice;
	///��ͼ�
	TKSG_PriceType	LowPrice;
	///�ɽ���
	TKSG_VolumeType	MatchTotQty;
	///�ɽ�����
	TKSG_WeightType	MatchWeight;
	///�ɽ���
	TKSG_MoneyType	Turnover;
	///�ֲ���
	TKSG_VolumeType	OpenInterest;
	///���̼�
	TKSG_PriceType	OpenPrice;
	///���̼�
	TKSG_PriceType	ClosePrice;
	///������
	TKSG_PriceType	ClearPrice;
	///���ս����
	TKSG_PriceType	LastClearPrice;
	///�������̼�
	TKSG_PriceType	LastClose;
	///��ͣ��
	TKSG_PriceType	RiseLimit;
	///��ͣ��
	TKSG_PriceType	FallLimit;
	///�ǵ�
	TKSG_PriceType	UpDown;
	///�ǵ�����
	TKSG_PriceType	UpDownRate;
	///���վ���
	TKSG_PriceType	AveragePrice;
	///�����һ
	TKSG_PriceType	BidPrice1;
	///������һ
	TKSG_VolumeType	BidVolume1;
	///������һ
	TKSG_PriceType	AskPrice1;
	///������һ
	TKSG_VolumeType	AskVolume1;
	///����۶�
	TKSG_PriceType	BidPrice2;
	///��������
	TKSG_VolumeType	BidVolume2;
	///�����۶�
	TKSG_PriceType	AskPrice2;
	///��������
	TKSG_VolumeType	AskVolume2;
	///�������
	TKSG_PriceType	BidPrice3;
	///��������
	TKSG_VolumeType	BidVolume3;
	///��������
	TKSG_PriceType	AskPrice3;
	///��������
	TKSG_VolumeType	AskVolume3;
	///�������
	TKSG_PriceType	BidPrice4;
	///��������
	TKSG_VolumeType	BidVolume4;
	///��������
	TKSG_PriceType	AskPrice4;
	///��������
	TKSG_VolumeType	AskVolume4;
	///�������
	TKSG_PriceType	BidPrice5;
	///��������
	TKSG_VolumeType	BidVolume5;
	///��������
	TKSG_PriceType	AskPrice5;
	///��������
	TKSG_VolumeType	AskVolume5;
	///��������
	TKSG_DateType   QuoteDate;           
	///����ʱ��
	TKSG_TimeType  QuoteTime;           
    
};

//�ɽ���ϸ��ѯ����
struct  CKSG_ReqMatchDtlQry
{
	///����Ա
	TKSG_UserIDType		TraderNo;    
	///��Լ��
	TKSG_InstrumentIDType		ContractID;          
};

//�ɽ���ϸ��ѯӦ��
struct CKSG_RspMatchDtlQry
{
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///�ɽ���
	TKSG_MatchNo	MatchNo;
	///�ɽ�����
	TKSG_DateType	MatchDate;
	///�ɽ��۸�
	TKSG_PriceType		Price;
	///�ɽ�����
	TKSG_VolumeType	Qty;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
};

//�û������걨�����ֶ�������
struct  CKSG_ReqTraderInsertDeliveryOrders
{
	///����ί�к�
	TKSG_LocalOrderNo		 LocalOrderNo;        
	///�û�����
	TKSG_UserIDType	     TraderNo;            
	///��Լ��
	TKSG_InstrumentIDType		 ContractID;  
	///������־
	TKSG_ByteType           BsFlag;             
	///Ͷ����־
	TKSG_ByteType           ShFlag;              
	///����
	TKSG_VolumeType         Qty;                 
	///�Ƿ�������
	TKSG_ByteType			 MidFlag;			  
};

//�û������걨�����ֶ���Ӧ��
struct  CKSG_RspTraderInsertDeliveryOrders
{
	///����ί�к�
	TKSG_LocalOrderNo		 LocalOrderNo;        
	///�û�����
	TKSG_UserIDType	     TraderNo;            
	///��Լ��
	TKSG_InstrumentIDType		 ContractID;  
	///������־
	TKSG_ByteType           BsFlag;             
	///Ͷ����־
	TKSG_ByteType           ShFlag;              
	///����
	TKSG_VolumeType         Qty;                 
	///�Ƿ�������
	TKSG_ByteType			 MidFlag;			  
};
//�û������걨�����ֶ����ر�
struct CKSG_RtnTraderInsertDeliveryOrders
{
	///ϵͳί�к�
	TKSG_SysOrderNo		SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo	LocalOrderNo;
	///�û�����
	TKSG_UserIDType		TraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///����
	TKSG_VolumeType	Qty;
	///��������
	TKSG_ByteType	OrderType;
	///ί��ʱ��
	TKSG_TimeType	OrderTime;
	///״̬
	TKSG_Status		Status;
	///ʣ������
	TKSG_VolumeType	RemainAmt;
	///�Ƿ�������
	TKSG_ByteType	MidFlag;
};
//���Ӳ�������
struct CKSG_DeferFeeRateByFund
{
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///֧������
	TKSG_ByteType           PayFlag;
	///���ӷ���
	TKSG_PriceType           DeferFee;
	///������
	TKSG_VolumeType         DeliveryQty;    
	///�ջ���
	TKSG_VolumeType         ReceiveQty;          
};
//�û������걨�����ֳɽ�֪ͨ
struct CKSG_NtyTraderDeliveryMatch
{
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///�ɽ���
	TKSG_MatchNo	MatchNo;
	///�ɽ�ʱ��
	TKSG_TimeType	MatchTime;
	///�ɽ�����
	TKSG_DateType	MatchDate;
	///�ɽ��۸�
	TKSG_PriceType		Price;
	///�ɽ�����
	TKSG_VolumeType	Qty;
	///�û�����
	TKSG_UserIDType	TraderNo;
	///������־
	TKSG_ByteType	BsFlag;
	///��ƽ��־
	TKSG_ByteType	EoFlag;
	///����ί�к�
	TKSG_LocalOrderNo LocalOrderNo;
	///�Ƿ�������
	TKSG_ByteType		MidFlag;             
};

//�û������걨�����ֳ�������
struct  CKSG_ReqTraderQuitDeliveryOrder
{
	///ϵͳί�к�
	TKSG_SysOrderNo		SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo	LocalOrderNo;
	///�û�����
	TKSG_UserIDType		TraderNo;
	///�����û�����
	TKSG_UserIDType		CancelTraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;   
	///��������
	TKSG_VolumeType         OrderCancelQty;   
	///�Ƿ�������
	TKSG_ByteType		MidFlag;    
                      
};
//�û������걨�����ֳ���Ӧ��
struct  CKSG_RspTraderQuitDeliveryOrder
{
	///ϵͳί�к�
	TKSG_SysOrderNo		SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo	LocalOrderNo;
	///�û�����
	TKSG_UserIDType		TraderNo;
	///�����û�����
	TKSG_UserIDType		CancelTraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;   
	///��������
	TKSG_VolumeType         OrderCancelQty;   
	
};
//�û������걨�����ֳ����ر�
struct CKSG_RtnTraderQuitDeliveryOrder
{
	///ϵͳί�к�
	TKSG_SysOrderNo		SysOrderNo;
	///����ί�к�
	TKSG_LocalOrderNo	LocalOrderNo;
	///�û�����
	TKSG_UserIDType		TraderNo;
	///�����û�����
	TKSG_UserIDType		CancelTraderNo;
	///��Լ����
	TKSG_InstrumentIDType	ContractID;
	///��������
	TKSG_VolumeType         OrderCancelQty;      

};
#endif
