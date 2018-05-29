#include "Instrument.h"
#include<string.h>


Instrument::Instrument()
{
	memset(&c_market, 0, sizeof(st_market));
}


Instrument::~Instrument()
{
	c_list_mkt.clear();
}


void Instrument::AddMkt(st_market *pmkt)
{
	//留存最新行情,当新连接上来时可以做及时推送
	memcpy(&c_market, pmkt, sizeof(st_market));


	st_market tmpmkt;
	memcpy(&tmpmkt, pmkt, sizeof(st_market));
	c_list_mkt.push_back(tmpmkt);
}