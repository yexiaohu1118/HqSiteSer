#include "CGlobal.h"


int		G_nToday = 0;
int	G_nType = 0;


string	G_ks_ip="", G_ks_Account="", G_ks_psw="";
int		G_ks_port = 0;
string	G_CurPath="", G_ConfigPath = "", G_LogPath = "", G_DatePath = "";

map<string, Instrument*>G_KStart_Hydm, G_Fix188_Hydm;



pthread_mutex_t G_mutex_Log;



KingstargoldMdAPI::CKSGMdApi*G_ksd_Api = NULL;
KsHq  G_ksSpi;