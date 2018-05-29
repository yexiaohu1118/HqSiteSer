#include <cstdio>
#include "Instrument.h"
#include<stdio.h>
#include "unistd.h"
#include "CFunc.h"
#include "CGlobal.h"
#include <string.h>
#include "Log.h"




//��ȡ��ǰ����·��
bool getOwnerPath()
{
	char path[1024];
	const char *file_name = "HqSiteSer.out";
	char abs_path_buff[1024];

	//��ȡ�ļ�·��, ��䵽abs_path_buff
	//realpath��������: null��ʾ��ȡʧ��; ���򷵻�ָ��abs_path_buff��ָ��
	if (!realpath(file_name, abs_path_buff))
	{
		return false;
	} 
	char* p = abs_path_buff;
	char*a = abs_path_buff;
	
	string outpath = abs_path_buff;
	int ned = outpath.find("HqSiteSer.out");
	G_CurPath = outpath.substr(0, ned);
	//������
	G_CurPath = "/root/projects/HqSiteSer/";
	return true;
}


int main()
{
	//��ʼ����־��Ϣ
	
	//
	if (!getOwnerPath())
	{
		Log::get_instance()->init("./mylog.log", 512, 2000000, 10);
		const char *str = "Get cureent path faild";
		WriteLog(1, str);
		Log::get_instance()->flush();
		return 0;
	}
	else
	{
		G_ConfigPath = G_CurPath + "config/config.xml";
		G_LogPath = G_CurPath + "log/";
		G_DatePath = G_CurPath + "date/";
		time_t t;
		time(&t);
		struct tm *t1;
		t1 = localtime(&t);

		G_nToday = (t1->tm_year + 1900) * 10000 + (t1->tm_mon + 1) * 100 + t1->tm_mday;
		FILE *fp;
		char filename[256] = {};
		sprintf(filename, "%s%d.txt", G_LogPath.c_str(), G_nToday);
		Log::get_instance()->init(filename, 512, 2000000, 10);

	
		const char *str = "Get absolute path sucess:";
		string path = str;
		path += G_CurPath;
		WriteLog(1, path.c_str());
		
		
		int ret = access(G_ConfigPath.c_str(), F_OK);

		if (ret == 0)
		{
			if (PreInitSystem())
			{
				//
				WriteLog(1, "Init config file complete");
				Login_Ksd();
				sleep(10);
			}
		}
		else
		{
			WriteLog(1, "Not fund config file");
		}
	}
	getchar();
	

	WriteLog(1, "Exit progress");
	UnInitSystem();
	Log::get_instance()->flush();
    return 0;
}
