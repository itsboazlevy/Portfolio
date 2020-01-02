#include "zlog4c.h"
#include <stdlib.h>
#define LINE_NUM

int main()
{
	zlog_init("testlog.txt",LOG_INFO);
	ZLOG(LOG_WARNING,"this is a log warning with 1 parameter %d",90)
	return 1;
}
