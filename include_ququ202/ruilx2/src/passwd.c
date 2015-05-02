/***************************************************************
**    Passwd Function Made By Ruilx Alxa in GT-Soft Studio    **
****************************************************************
** passwd.c ****************************************************
****************************************************************
** Copyright (C) 2013 GT-Soft Studio and/or                   **
**                 its subsidiary(-ies). All rights reserved. **
** Contact: GT-SOFT Studio <gtsoft.cwsurf.de>                 **
** $General Public License:GPL$                               **
** You may use this file under the terms of the GPL license   **
** as follows:                                                **
** "Redistribution and use in source and binary forms, with   **
** or without modification, are permitted provided that the   **
** following conditions are met:                              **
**                                                            **
** THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT        **
** PERMITTED BY APPLICABLE LAW. EXCEPT WHEN OTHERWISE         **
** STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER       **
** PARTIES PROVIDE THE PROGRAM ¡°AS IS¡± WITHOUT WARRANTY       **
** OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,       **
** BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF              **
** MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.      **
** THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF       **
** THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE          **
** DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY            **
** SERVICING, REPAIR OR CORRECTION.                           **
****************************************************************
*Ruilx Alxa in Xian University of Posts and Telecommunications *
***************************************************************/
/* 2013 05 28 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "passwd.h"
#include "cipher.h"
#include "slowprint.h"
#include "getch.h" /* int getch(void) */


int accept(char *a){
	char *c, pass[20];
	c=deciphering("passwd", pass, 555); /* cipher.h */
	if(strcmp(a,c)){ /* if password not correct...Uh!~ */
		return 0;   /* NOT CORRECT RETURN 0 */
	}		
	return 1;		 /* R~I~G~H~T~! */
}

int passwd(void){
	char a[20], b;
	int i=0;
	slowprint("\e[39mLogin Password: ",20);
	while(((b=getch())!=13) && (i < 20)){
		if(b!=127){		/* It isnot Backspace (8) */
			putchar('*');	/* Give a '*' to screen */
			a[i]=b;			/* Give `b' to `a' */
			i++;			/* Rightway move */
		}else{				/* If IS Backspace */
			if(i>0){		/* if pointoff on time */
				i--;		/* backflush */
			
				putchar('\b');	/* backflush on screen */
				putchar(' ');
				putchar('\b');
			}
		}

	}
	a[i]='\0';				/* Give End to string */
	putchar('\n');
	if(accept(a)){			/* Take a care to your passed */
		return 1;			/* Succeed! Yeah! */
	}else{					/* Otherwise...... */
		return 0;			/* Baka >_<!! */
	}
}

int createpass(char *a){
	return encryption(a, "passwd", 555);
}

int changepasswd(void){
	char a[20], b; int i;
	char a1[20];
	if(passwd()){
enterpasswd:
		slowprint("Enter new password: ",30);
		i=0;
		while(((b=getch())!=13) && (i<20)){
			if(b!=127){
				putchar('*');
				a[i]=b;
				i++;
			}else{
				if(i>0){
					i--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
		}
		a[i]='\0';
		putchar('\n');
		slowprint("Corfirm           : ",30);
		i=0;
		while(((b=getch())!=13) && (i<20)){
			if(b!=127){
				putchar('*');
				a1[i]=b;
				i++;
			}else{
				if(i>0){
					i--;
					putchar('\b');
					putchar(' ');
					putchar('\b');
				}
			}
		}
		a1[i]='\0';
		putchar('\n');
		if(strcmp(a, a1)==0){
			createpass(a);
			slowprint("\e[31mChange password successfully!\e[39m\n",30);
			return 1;
		}else{
			slowprint("\e[31mPassword not Match, Enter again.\e[39m\n",30);
			goto enterpasswd;
		}
	}else{
		slowprint("\e[31mPassword incorrect. Try again.\e[0m\n",30);
		return 0;
	}
	return 0;
}

