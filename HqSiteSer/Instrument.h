#pragma once

#include <stdio.h>
#include <stdlib.h>
#include"struct.h"

#include <list>
#include <string>
using namespace std;
class Instrument
{
public:
	Instrument();
	~Instrument();
	void AddMkt(st_market *pmkt);

public:
	st_market c_market;
	string c_code;			//合约代码
	int		c_type;			//行情类型
	list<st_market>c_list_mkt;

};

