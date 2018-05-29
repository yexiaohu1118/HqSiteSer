#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <iostream>
#include "KSGMdAPI.h"
#include "KsHq.h"
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <pthread.h>
#include <map>
#include "struct.h"
#include "Instrument.h"

using namespace std;



#define MARKET_KSTART	1
#define	MARKET_FIX188	2

extern int		G_nToday;
extern int		G_nType;				//��������
extern string	G_CurPath,G_ConfigPath,G_LogPath,G_DatePath;


extern map<string, Instrument*>G_KStart_Hydm,G_Fix188_Hydm; 

extern pthread_mutex_t G_mutex_Log;		//��־��

//
extern	string	G_ks_ip, G_ks_Account, G_ks_psw;
extern int		G_ks_port;
extern  KingstargoldMdAPI::CKSGMdApi*G_ksd_Api;		//���˴�
extern	KsHq  G_ksSpi;		//	


#endif
