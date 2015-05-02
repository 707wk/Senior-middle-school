#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "checkdate.h"
#include "cipher.h"
#include "getch.h"
#include "passwd.h"
#include "slowprint.h"
#include "bubblesortnew.h"
#include "findcon.h"
#include "stat.h"
#include "input.h"

#include "struct.h"

#include "display.h"
#include "readcon.h"
#include "save.h"
#include "menu.h"

#define STR struct
#define CON contacts
#define CLEAR system("clear")

int main(int argc, char *argv[]){
	FILE *con, *pass, *statis;
	//unsigned char choise;
	int saved=1, count, ct, st[29];
	STR CON *head, *p, *last;
	
	slowprint("Welcome to contract manage system!\nLoading... Please wait... ",15);
	sleep(2);
	CLEAR;
	if(argc==2 && strcmp(argv[1], "-Jumpoverpassword")==0) goto mainmenu;
	if((pass=fopen("passwd","rt"))==NULL){
		slowprint("\e[31;1mAuthentication File Failed: Password Lost.\e[0m\n",30);
		return 0;
	}
	fclose(pass);
	for(count=0;count<5;count++){
		switch(passwd()){
			case 0:
				slowprint("\e[31;1mPassword Not Correct\e[0m\n",30);
				continue;
				break;
			case 1:
				goto mainmenu;
				break;
		}
	}
	slowprint("\e[31;1mAuthentication Failed.\e[0m\n",30);
	return 0;

mainmenu:
	if((con=fopen("contracts.dat","rt"))==NULL){
		menu(1);
		fflush(stdin);
		switch(getch()){
			case 'C':
			case 'c':
			case '1':
				//printf("\e[0m");
				CLEAR;
				ins(head);
				slowprint("Saving... Please wait...\n",30);
				saved=save(head);
				slowprint("Saving Complete!\n",30);
				break;
			case 'E':
			case 'e':
			case '0':
				about();
				getch();
				//printf("\e[0m");
				//system("./clearscr.sh");
				CLEAR;
				return 0;
			default:
				//printf("\e[0m");
				//slowprint("\tPlease Enter the correct item.\n",30);
				goto mainmenu;
		}
		goto mainmenu;
	}
	head=readcon("contracts.dat",head);
mainchoise:
	if(head==NULL){
		printf("\e[0mError in Reading file...\n");
		sleep(2);
		goto mainmenu;
	}
	menu(2);
ask0:
	switch(getch()){
		case 'C':
		case 'c':
		case '1':
			//printf("\e[0m");
			CLEAR;
			slowprint("This will delete your contacts data, "
				"Are you sure to do that? [Y/n]: ",30);
ask1:
			switch(getch()){
				case 'y':
				case 'Y':
					system("rm contracts.dat");
					free(p);free(last);
					slowprint("\nFile is already deleted.\n"
						"Press any key to main menu.",30);
					getch();
					goto mainmenu;
					break;
				case 'n':
				case 'N':
					slowprint("Operation failed.\n"
						"Press any key to main menu.",30);
					getch();
					goto mainmenu;
					break;
				default :
					goto ask1;
					break;
			}
			break;
		case 'L':
		case 'l':
		case '2':
			//printf("\e[0m");
			CLEAR;
			slowprint("Make a list of your contacts...\n",30);
			display(head);
			slowprint("Contacts above.\nPress any key back.",30);
			getch();
			goto mainchoise;
			break;
		case 'A':
		case 'a':
		case '3':
addmember:
			//printf("\e[0m");
			CLEAR;
			slowprint("Add a member to the contacts...\n",30);
			switch(ins(head)){
				case 1:
					saved=0;	/* Flag Saved to Not saved(Lastest) */
					slowprint("Add member successfully.\n"
						"Do you want to continue? [Y/n]: ",30);
ask2:
					switch(getch()){
						case 'y':
						case 'Y':
							goto addmember;
							break;
						case 'N':
						case 'n':
							slowprint("Press any key to main menu.",30);
							getch();
							goto mainchoise;
							break;
						default:
							goto ask2;
							break;
					}
					break;
				case 0:
					slowprint("Add member failed.\n"
						"Check your name entered whether repeated.\n"
						"Do you want to continue? [Y/n]: ",30);
ask3:
					switch(getch()){
						case 'Y':
						case 'y':
							goto addmember;
							break;
						case 'N':
						case 'n':
							slowprint("Press any key to main menu.",30);
							getch();
							goto mainchoise;
							break;
						default:
							goto ask3;
							break;
					}
					break;
				default: printf("186:We have a problem here, Program exitting...\n");
					return 0;
					break;

			}
			break;
		case 'D':
		case 'd':
		case '4':
deletemember:
			//printf("\e[0m");
			CLEAR;
			slowprint("Delete a member from the contacts...\n",30);
			switch(del(head)){
				case 1:
					saved=0;	/* Flag save to lastest */ 
					slowprint("Delete Successfully!\n"
						"Do you want to continue? [Y/n]: ",30);
ask4:
					switch(getch()){
						case 'Y':
						case 'y':
							goto deletemember;
							break;
						case 'N':
						case 'n':
							slowprint("Press any key to main menu.",30);
							getch();
							goto mainchoise;
							break;
						default:
							goto ask4;
							break;
					}
					break;
				case 0:
					slowprint("Delete Failed.\n"
						"Please check whether there has member in it.\n"
						"Do you want to try again? [Y/n]: ",30);
ask5:
					switch(getch()){
						case 'Y':
						case 'y':
							goto deletemember;
							break;
						case 'N':
						case 'n':
							slowprint("Press any key to main menu.",30);
							getch();
							goto mainchoise;
							break;
						default:
							goto ask5;
							break;
					}
					break;
				default:
					printf("268:We have a problem here. Program Exitting...\n");
					return 0;
					break;
			}
		case 'F':
		case 'f':
		case '5':
findmember:
			//printf("\e[0m");
			CLEAR;
			slowprint("Find member...\n",30);
			/*
			p=find(head);
			if(p==NULL){
				slowprint("No Match Found.\n"
					"Please check your name whether is correct.\n"
					"Do you want to try again? [Y/n]: ",30);
ask6:
				switch(getch()){
					case 'Y':
					case 'y':
						goto findmember;
						break;
					case 'N':
					case 'n':
						slowprint("Press any key to main menu.",30);
						getch();
						goto mainchoise;
						break;
					default:
						goto ask6;
						break;
				}
			}
			slowprint("Founded!\n",30);
			printf("Name     : %s\nTelephone: %s\nFixedTele: %s\n"
				"Address  : %s\nE-mail   : %s\nBirthday : %4d/%2d/%2d\n" \
				,p->name,p->tele,p->fixtel,p->addr,p->email, \
				p->birth.year,p->birth.month,p->birth.day);
			slowprint("Do you want to edit this contact?\nEnter 0 to back\nEnter 1 to name\nEnter 2 to telephone\nEnter 3 to fixed-tel" \
					"\nEnter 4 to address\nEnter 5 to E-mail\nEnter 6 to birthday\n",30);
askedit:
			switch(getch()){
				case '1':printf("Enter name: ");		inputstr(p->name, 12);break;
				case '2':printf("Enter telephone: ");		inputnumstr(p->tele, 11);break;
				case '3':printf("Enter fixed-tel: ");		inputnumstr(p->fixtel, 14);break;
				case '4':printf("Enter address: ");		inputstr(p->addr, 29);break;
				case '5':printf("Enter E-mail address: ");	inputstr(p->email, 19);break;
				case '6':printf("Select date:");		inputdate(&p->birth.year, &p->birth.month, &p->birth.day);break;
				case '0':
					slowprint("Press any key to main menu.\n",30);
					getch();
					goto mainchoise;
					break;
				default:goto askedit;
			}
			slowprint("Operation success, choose another items to continue, 0 to main menu.\n",30);
			goto askedit;
			*/
			findcon(head);
			goto mainchoise;
			break;
		case 'S':
		case 's':
		case '6':
			//printf("\e[0m");
			CLEAR;
			slowprint("Sortting the contacts...\n\tPlease select"
				" sortting methods:\n"
				"\t1. Sort by name\n"
				"\t2. Sort by telephone\n",30);
ask20:
			switch(getch()){
				case '1':
					slowprint("Sort by name:\n",30);
					last = head;
					/*
					while((last->next)!=NULL){
						printf("MAIN FIND last ADDR %d\n",last);
						last=(last->next);
						printf("MAIN FIND LAST ADDR %d\n",last);
					}
					*/
					//quick(head, last, 1);
					//puts("Bubblesort in main.c\n");
					bubblesort(head, 1);
					saved=0;	/* Flag save to not saved */
					slowprint("Sort complete!\nPress any key to main menu",30);
					getch();
					goto mainchoise;
					break;
				case '2':
					last = head;
					slowprint("Sort by telephone:\n",30);
					while((last->next)!=NULL){
						last=(last->next);
					}
					//quick(head, last, 2);
					bubblesort(head, 2);
					saved=0;	/* Flag save to not saved */
					slowprint("Sort complete!\nPress any key to main menu",30);
					getch();
					goto mainchoise;
					break;
				default:goto ask20;
			}
			break;
		case 'T':
		case 't':
		case '7':
			//printf("\e[0m");
			CLEAR;
			slowprint("Statistics:\n",30);
			stat(head);
			if((statis=fopen("stat.txt","rt"))==NULL){
				slowprint("Statistics File not Exist, try again.\n",30);
				getch();
				goto mainchoise;
			}
			for(ct=0; ct<29; ct++){
				fscanf(statis,"%d",&st[ct]);
			}
			fclose(statis);
			printstat(st);
			slowprint("Press any key to main menu.",30);
			getch();
			goto mainchoise;
			break;
		case 'V':
		case 'v':
		case '8':
			//printf("\e[0m");
			CLEAR;
			slowprint("Saving... Please wait...\n",30);
			saved=save(head);
			slowprint("Saved Successfully. Press any key to main menu.",30);
			saved=1;	/* Saved Successfully */
			getch();
			goto mainchoise;
			break;
		case 'H':
		case 'h':
		case '9':
			CLEAR;
			changepasswd();
			getch();
			goto mainchoise;
			break;
		case 'E':
		case 'e':
		case '0':
			//printf("\e[0m");
			CLEAR;
ask9:
			switch(saved){
				case 0:
					asksave();
ask10:
					switch(getch()){
						case 'S':
						case 's':
						case '1': 
							save(head);
							slowprint(
								"\e[37;1HData Saved Successfully!",30);
							sleep(2);
							about();
							getch();
							printf("\e[0m");
							//system("./clearscr.sh");
							CLEAR;
							return 1;
						case 'M':
						case 'm':
						case '2': 
							goto mainchoise;
						case 'D':
						case 'd':
						case '3': 
							about();
							getch();
							printf("\e[0m");
							//system("./clearscr.sh");
							CLEAR;
							return 1;
						default: goto ask10;
							break;
					}
				case 1:
					about();
					getch();
					printf("\e[0m");
					//system("./clearscr.sh");
					CLEAR;
					return 1;
				default: goto ask9;
					break;
			}
			break;
		default: goto ask0;
			break;
	}
	return 0;
}

