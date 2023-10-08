#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <syslog.h>


int main(int argc, char *argv[])
{
    openlog(NULL,0, LOG_USER);
    if (argc < 3)
    {
        syslog(LOG_ERR, "Either the filename or the content is not provided as a command line argument");
        return 1;
    }
    char* writefile = argv[1];
    char* writestr = argv[2];  

    syslog(LOG_DEBUG, "File where data will be added is %s\n", writefile);
    syslog(LOG_DEBUG,"Data to be added is %s\n", writestr);
    FILE *file = fopen(writefile, "a+");
    if (file == NULL)
    {
        syslog(LOG_ERR, "Exception occured while writing to %s file: %s", writefile, strerror(errno));
        fprintf(stderr, "Value of errno attempting to open file %s is %d\n", writefile, errno);
        perror("perror returned");
        fprintf(stderr, "Error opening file %s %s\n", writefile, strerror(errno));
        return 1;
    }
    else
    {
        syslog(LOG_DEBUG, "Writing %s to %s", writefile,writestr);
        fprintf(file, "Data written to file is : %s\n", writestr);
        fclose(file);
    }
    return 0;
}
