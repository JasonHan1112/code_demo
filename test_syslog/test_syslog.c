#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

#define IND "TEST_LOG"

int test_syslog(int i)
{
    int ret = 0;
    openlog(IND, LOG_PID | LOG_CONS | LOG_NDELAY, LOG_USER);
    syslog(LOG_DEBUG | LOG_USER, "this is a test %d", i);
    closelog();

    return 0;
}


int main(int argc, char* argv[])
{
    int ret = 0;
    int c = 0;
    while(1)
    {
	c++;
        sleep(1);
	test_syslog(c);
    }

}
