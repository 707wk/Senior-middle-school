#include <stdio.h>

#include "struct.h"
#include "stat.h"
#define STR struct
#define CON contacts
void stat(STR CON *p){
	int st[29]={0}, i;
	FILE *fp;
	p=p->next;
	while(p != NULL){
		switch(p->name[0]){
			case 'a': case 'A': st[0]++;break;
                        case 'b': case 'B': st[1]++;break;
                        case 'c': case 'C': st[2]++;break;
                        case 'd': case 'D': st[3]++;break;
                        case 'e': case 'E': st[4]++;break;
                        case 'f': case 'F': st[5]++;break;
                        case 'g': case 'G': st[6]++;break;
                        case 'h': case 'H': st[7]++;break;
                        case 'i': case 'I': st[8]++;break;
                        case 'j': case 'J': st[9]++;break;
                        case 'k': case 'K': st[10]++;break;
                        case 'l': case 'L': st[11]++;break;
                        case 'm': case 'M': st[12]++;break;
                        case 'n': case 'N': st[13]++;break;
                        case 'o': case 'O': st[14]++;break;
                        case 'p': case 'P': st[15]++;break;
                        case 'q': case 'Q': st[16]++;break;
                        case 'r': case 'R': st[17]++;break;
                        case 's': case 'S': st[18]++;break;
                        case 't': case 'T': st[19]++;break;
                        case 'u': case 'U': st[20]++;break;
                        case 'v': case 'V': st[21]++;break;
                        case 'w': case 'W': st[22]++;break;
                        case 'x': case 'X': st[23]++;break;
                        case 'y': case 'Y': st[24]++;break;
                        case 'z': case 'Z': st[25]++;break;
                        case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9': st[26]++;break;
			default: st[27]++;
		}
		st[28]++;
		p=p->next;
	}	
	if((fp=fopen("stat.txt","wt"))==NULL){
		printf("Cannot reslove source file.\n");
		return;
	}
	for(i=0;i<29;i++){
		fprintf(fp,"%d ",st[i]);
	}
	fclose(fp);
}

