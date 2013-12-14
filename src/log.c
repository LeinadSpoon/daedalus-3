/**************************
 * log.c
 * (c) 2013 Daniel Burgener
 * Message log in game
 **************************/

#include <stdio.h>
#include <stdarg.h>

#include "log.h"

// For now, we're just logging to a file
int gamelog(char *msg, ...)
{

	va_list args;

	va_start(args,msg);

	FILE *fd = fopen("log.txt","a");
	if (!fd) {
		return -1;
	}
	vfprintf(fd,msg,args);

	fclose(fd);

	va_end(args);

	return 0;
}
