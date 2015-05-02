/*  getch.c & getch.h copied form 
*********club.noahedu.com **********
Copyright (C) 2006-2011 Noahedu.com
All Rights Reserved.              */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "getch.h"

int getch(void){
	struct termios tm, tm_old;
	int fd = STDIN_FILENO, c;
	if(tcgetattr(fd, &tm) < 0){
		return -1;
	}
	tm_old = tm;
	cfmakeraw(&tm);
	if(tcsetattr(fd, TCSANOW, &tm) < 0){
		return -1;
	}
	c = fgetc(stdin);
	if(tcsetattr(fd, TCSANOW, &tm_old) < 0){
		return -1;
	}
	return c;
}

