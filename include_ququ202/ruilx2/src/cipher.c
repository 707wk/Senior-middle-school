/***************************************************************
**   Cipher Function Made By Ruilx Alxa in GT-Soft Studio     **
****************************************************************
** cipher.c ****************************************************
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
#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"
#include "slowprint.h"

/*
int chaoscipher(int control, char *input, char *output, int key){
	int i, ch;
	char chaos;
	double x=key/1000.0;
	FILE *fp1, *fp2;
	if((fp1=fopen(input,"r"))==0){
		return 10;
	}
	if((fp2=fopen(output,"w"))==0){
		return 20;
	}
	for(i=0;i<100;i++){
		x=4*x*(1-x);
	}
	while((ch = getc(fp1))!=EOF){
		chaos=(char)(x*95);
		ch=ch^chaos;
		putc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
} */

int encryption(char *input, char *foutput, int key){
	/* encryption for passwd */
	/* input a string, output the file, user key.*/
	int i, ch;
	char chaos;
	double x=key/1000.0;
	FILE *fout;
	if((fout=fopen(foutput,"w"))==0){
		slowprint("Cannot open output file.\n",15);
		return 10;
	}
	for(i=0;i<100;i++){
		x=x*4*(1-x);
	}
	while((ch=*input)!='\0'){
		x=x*4*(1-x);
		chaos=(char)(x*95);
		ch=ch^chaos;
		putc(ch, fout);
		input++;
	}
	fclose(fout);
	return 0;
}

char *deciphering(char *finput, char *pass, int key){
	/* deciphering for passwd */
	/* input a encryptied file, output a string, user key. */
	int i, ch;
	char chaos;
	double x=key/1000.0;
	FILE *fin;
	if((fin=fopen(finput,"r"))==0){
		slowprint("Cannot open input file.\n",15);
		return NULL;
	}
	for(i=0;i<100;i++){
		x=x*4*(1-x);
	}
	i=0;
	while((ch=getc(fin))!=EOF && i<19){
		x=x*4*(1-x);
		chaos=(char)(x*95);
		ch=ch^chaos;
		*(pass+i)=(char)ch;
		i++;
	}
	fclose(fin);
	pass[i]='\0';
	return pass;
}

