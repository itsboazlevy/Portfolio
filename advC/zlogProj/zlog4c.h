/* log levels descriptions */
enum LOG_LEVEL
{
	LOG_TRACE,		/*Trace message usually very detailed*/
    	LOG_DEBUG,		/*A message useful for debugging*/
    	LOG_INFO,		/*Informative message*/ 
    	LOG_WARNING,		/*Warning*/
    	LOG_ERROR,		/*An error occurred*/ 
	LOG_CRITICAL,		/*Critical error*/
    	LOG_SEVERE,		/*Server error requiring immediate intervention*/
    	LOG_FATAL,		/*Fatal error signaling an emergency*/ 
    	LOG_NONE		/*Used only in config file*/
};

/*
Description: will write log line into log file if log lvl is high as log configured lvl, file will be created if not created yet
Input: log lvl, message string with variable length parameters
Output: log line into log file
*/
#define ZLOG(level,message,...) Zlog(__FILE__,__LINE__,level,message,__VA_ARGS__);
void Zlog(char* _file, int _line, const char _logLvl, char* _string,...);


/*
Description: creates a logConfig.txt file with given log name and log lvl
Input: name and log lvl for config file
Output: none
*/
void zlog_init (const char* _name,const char _logLvl);


