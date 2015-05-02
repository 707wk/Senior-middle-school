#!/bin/bash

gcc -Wall -o main_i386 	main.c 		cipher.c 	readcon.c 	slowprint.c \
			checkdate.c 	passwd.c 	save.c 		display.c \
			getch.c 	menu.c 		bubblesortnew.c	findcon.c \
			stat.c		input.c		-g

exit 0
