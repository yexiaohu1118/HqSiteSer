#include "CFunc.h"
#include "CGlobal.h"
#include <ctime>
using namespace std;
#include "tinyxml.h"
#include<stdio.h>
#include<errno.h>
#include "KSGMdAPI.h"
#include "Log.h"
#include <string.h>


#include <cstdio>
#include "unistd.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 


void string_replace_2(string&s1, const string&s2, const string&s3)
{
	string::size_type pos = 0;
	string::size_type a = s2.size();
	string::size_type b = s3.size();
	while ((pos = s1.find(s2, pos)) != string::npos)
	{
		s1.erase(pos, a);
		s1.insert(pos, s3);
		pos += b;
	}
}

bool	PreInitSystem()
{
	//读取配置信息
	TiXmlDocument doc(G_ConfigPath.c_str());
	if (!doc.LoadFile())
	{
		WriteLog(1,"config file load faild!");
		return false;
	}
	//读取金仕达配置文件
	TiXmlNode *proot = doc.FirstChild("root");
	TiXmlNode *pnode = 0;
	TiXmlNode *child = 0;
	TiXmlElement* itemElement = 0;
	//读取金仕达
	pnode = proot->FirstChild("KStart");
	child = pnode->FirstChild("address");
	itemElement = child->ToElement();
	G_ks_ip = itemElement->Attribute("ip");
	G_ks_port = atoi(itemElement->Attribute("port"));
	child = pnode->FirstChild("user");
	itemElement = child->ToElement();
	G_ks_Account = itemElement->Attribute("name");
	G_ks_psw = itemElement->Attribute("psw");

	child = pnode->FirstChild("code");
	itemElement = child->ToElement();
	string hydm = itemElement->Attribute("hydm");
	
	size_t start = 0, index = hydm.find_first_of(",", 0);
	while (index != hydm.npos)
	{
		if (start != index)
		{
			Instrument *pins = new Instrument;
			pins->c_code = hydm.substr(start, index - start);
			pins->c_type = MARKET_KSTART;
			AddHyToMap(MARKET_KSTART,(char*)pins->c_code.c_str(),pins);
		}
		start = index + 1;
		index = hydm.find_first_of(",", start);
	}
	if (!hydm.substr(start).empty())
	{
		Instrument *pins = new Instrument;
		pins->c_code = hydm.substr(start, index - start);
		pins->c_type = MARKET_KSTART;
		AddHyToMap(MARKET_KSTART,(char*)pins->c_code.c_str(), pins);
	}
	

	//金仕达合约信息
	doc.SaveFile();


	//初始化锁
	pthread_mutex_init(&G_mutex_Log, NULL);
	return true;
	
}

void UnInitSystem()
{

	//销毁锁资源
	pthread_mutex_destroy(&G_mutex_Log);

	//释放行情数据占用内存
	RmoveAllIns(MARKET_KSTART);
}

bool filepathis(char* filenem)
{
	if (access(filenem, 0) != 0)
	{
		mkdir(filenem, 0775);
	}
	return true;
}

void WriteLog(int type,const char *msg)
{
	printf("%s\n", msg);
	
	Log::get_instance()->write_log(type, msg);
	Log::get_instance()->flush();
}

bool LookupInstrument(int type, char* code, Instrument*& pins)
{
	map<string, Instrument*>*pmap = NULL;
	if (type == MARKET_KSTART)
	{
		pmap = &G_KStart_Hydm;
	}
	else
	{
		pmap = &G_Fix188_Hydm;
	}
	map< string, Instrument*>::iterator iter;

	iter = pmap->find(code);
	if (iter == pmap->end())
		return false;
	pins = pmap->at(code);
	return true;
}

void RemoveAt(int type, char* code)
{
	map<string, Instrument*>*pmap = NULL;
	if (type == MARKET_KSTART)
	{
		pmap = &G_KStart_Hydm;
	}
	else
	{
		pmap = &G_Fix188_Hydm;
	}
	map< string, Instrument*>::iterator iter;
	
	iter = pmap->find(code);
	if (iter != pmap->end())
	{
		Instrument *pins = pmap->at(code);
		pmap->erase(iter);
		delete(pins);
	}
}

void RmoveAllIns(int type)
{
	map<string, Instrument*>*pmap = NULL;
	if (type == MARKET_KSTART)
	{
		pmap = &G_KStart_Hydm;
	}
	else
	{
		pmap = &G_Fix188_Hydm;
	}
	map< string, Instrument*>::iterator iter;
	Instrument *pins = NULL;
	if (pmap->size() > 0)
	{
		for (iter = pmap->begin(); iter != pmap->end(); iter++)
 		{
			pins = iter->second;
			delete(pins);
 		}
	}
 	pmap->erase(pmap->begin(), pmap->end());
}

void AddHyToMap(int type, char* code, Instrument *pins)
{
	map<string, Instrument*>*pmap = NULL;
	if (type == MARKET_KSTART)
	{
		pmap = &G_KStart_Hydm;
	}
	else
	{
		pmap = &G_Fix188_Hydm;
	}
	string key = code;
	pmap->insert(pair<string, Instrument*>(key, pins));
}
//登录金仕达
bool Login_Ksd()
{
	if (!G_ksd_Api)
	{
		G_ksd_Api = KingstargoldMdAPI::CKSGMdApi::CreateKSGMdApi();
		G_ksSpi.port = G_ks_port;
		strcpy(G_ksSpi.ip ,G_ks_ip.c_str());
		G_ksSpi.InitEnv(G_ksd_Api);
		int ret = G_ksd_Api->RegisterServer("219.140.77.102", 6900);
		if (ret == -8)
		{
		 WriteLog(3, "Address have registed");
		}
		else
		{
			 WriteLog(3, "Address regist sucess");
		}
		 G_ksd_Api->Init();
		 CKSG_ReqUserLoginField loginreq;
		 memset(&loginreq, 0, sizeof(loginreq));
		 strcpy(loginreq.TraderNo, G_ks_Account.c_str());
		 strcpy(loginreq.Pwd, G_ks_psw.c_str());
		 sleep(1);
		 int rcode = G_ksd_Api->ReqUserLogin(&loginreq);
		 if (rcode == -6)
		 {
			 WriteLog(3, "登录请求超时");
			 return false;
		 }
		 return true;
	}
	



	return true;
}
