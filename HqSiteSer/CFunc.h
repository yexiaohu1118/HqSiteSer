#ifndef CFUNC_H_
#define CFUNC_H_

#include <stdbool.h>
#include "struct.h"
#include <iostream>
#include <vector>
#include <string>
#include "Instrument.h"


extern void string_replace_2(string&s1, const string&s2, const string&s3);
extern bool	PreInitSystem();			//初始化系统
extern void UnInitSystem();				//结束时释放资源
extern bool filepathis(char* filenem);	//判断文件夹是否存在，不存在则创建
extern void WriteLog(int type,const char *msg);	//刷新日志信息

//
 extern	bool LookupInstrument(int type, char* code, Instrument*& pmarket);
 extern void RemoveAt(int type, char* code);
 extern	void RmoveAllIns(int type);
 extern void AddHyToMap(int type, char * code, Instrument *pMkt);
//登录金仕达行情系统
extern bool Login_Ksd();				







#endif
