#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct st_market
{
	char	code[16];		//��Լ����
	char	jys[8];			//������
	int		TradingDay;	//��������
	int		QuoteDate;	//��������
	int		QuoteTime;	//����ʱ��
	double	LastPrice;		//���¼�
	double	HighPrice;		//��߼�
	double	LowPrice;		//��ͼ�
	int		TradeQty;		//�ɽ���
	double	TradeWeight;	//�ɽ�����
	double	Turnover;		//�ɽ����
	int		OpenInterest;	//�ֲ���
	double	OpenPrice;		//���̼�
	double	ClosePrice;		//���̼�
	double	ClearPrice;		//�����
	double	LastClearPrice;	//���ս����
	double	LastClose;		//�������̼�
	double	RiseLimit;		//��ͣ��
	double	FallLimit;		//��ͣ��
	double	UpDown;			//�ǵ�
	double	UpDownRate;		//�ǵ�����
	double	AveragePrice;	//����
	double	BidPrice[5];	//�����;
	int		BidVolume[5];	//������
	double	AskPrice[5];	//������
	int		AskVolume[5];	//������;

};

typedef struct st_kline
{
	char	code[9];
	char	TradingDay[9];	//��������
	char	QuoteDate[9];	//��������
	char	QuoteTime[13];	//����ʱ��
	double	Open;
	double	High;
	double	Low;
	double	Close;
	int		Volume;
	double	amount;
};

#endif