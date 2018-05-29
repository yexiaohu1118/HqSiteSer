#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct st_market
{
	char	code[16];		//合约代码
	char	jys[8];			//交易所
	int		TradingDay;	//交易日期
	int		QuoteDate;	//行情日期
	int		QuoteTime;	//行情时间
	double	LastPrice;		//最新价
	double	HighPrice;		//最高价
	double	LowPrice;		//最低价
	int		TradeQty;		//成交量
	double	TradeWeight;	//成交重量
	double	Turnover;		//成交金额
	int		OpenInterest;	//持仓量
	double	OpenPrice;		//开盘价
	double	ClosePrice;		//收盘价
	double	ClearPrice;		//结算价
	double	LastClearPrice;	//上日结算价
	double	LastClose;		//上日收盘价
	double	RiseLimit;		//涨停板
	double	FallLimit;		//跌停板
	double	UpDown;			//涨跌
	double	UpDownRate;		//涨跌幅度
	double	AveragePrice;	//均价
	double	BidPrice[5];	//申买价;
	int		BidVolume[5];	//申买量
	double	AskPrice[5];	//申卖价
	int		AskVolume[5];	//申卖量;

};

typedef struct st_kline
{
	char	code[9];
	char	TradingDay[9];	//交易日期
	char	QuoteDate[9];	//行情日期
	char	QuoteTime[13];	//行情时间
	double	Open;
	double	High;
	double	Low;
	double	Close;
	int		Volume;
	double	amount;
};

#endif