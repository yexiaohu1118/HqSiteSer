#ifndef CFUNC_H_
#define CFUNC_H_

#include <stdbool.h>
#include "struct.h"
#include <iostream>
#include <vector>
#include <string>
#include "Instrument.h"


extern void string_replace_2(string&s1, const string&s2, const string&s3);
extern bool	PreInitSystem();			//��ʼ��ϵͳ
extern void UnInitSystem();				//����ʱ�ͷ���Դ
extern bool filepathis(char* filenem);	//�ж��ļ����Ƿ���ڣ��������򴴽�
extern void WriteLog(int type,const char *msg);	//ˢ����־��Ϣ

//
 extern	bool LookupInstrument(int type, char* code, Instrument*& pmarket);
 extern void RemoveAt(int type, char* code);
 extern	void RmoveAllIns(int type);
 extern void AddHyToMap(int type, char * code, Instrument *pMkt);
//��¼���˴�����ϵͳ
extern bool Login_Ksd();				







#endif
