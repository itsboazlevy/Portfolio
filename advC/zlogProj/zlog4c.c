#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include "zlog4c.h"

typedef struct Log
{
	char m_logName[20];
	char m_logLvl;
}Log;

static Log* myLog;

void Zlog(char* _file, int _line, const char _logLvl, char* _string,...)
{
	time_t curTime;
	char* timeString;
	FILE* logFile;
	va_list var;
	if (myLog->m_logLvl > _logLvl)
	{
		return;
	}
	time(&curTime);
	timeString = ctime(&curTime);
	logFile = fopen(myLog->m_logName,"a+");
	va_start(var,_string);
	fprintf(logFile,"Module: %s  Line:%d Log Level:%d  Time: %s", _file, _line, _logLvl,timeString);
	vfprintf(logFile,_string,var);
	va_end(var);
	fclose(logFile);
	return;
}

void zlog_init (const char* _name,const char _logLvl)
{
	FILE* logConfig;
	myLog = (Log*)malloc(sizeof(Log));
	if (myLog == NULL)
	{
		return;
	}
	logConfig = fopen("logConfig.txt","w+");
	if (logConfig == NULL)
	{
		free(myLog);
		return;
	}
	fprintf(logConfig, "FILE = %s\n", _name);
	fprintf(logConfig, "LEVEL = %d\n", _logLvl);
	fclose(logConfig);
	myLog->m_logLvl = _logLvl;
	strcpy(myLog->m_logName,_name);
	return;	

}

