#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define RED 	"\e[31m"
#define GREEN 	"\e[32m"
#define YELLOW 	"\e[33m"
#define BLUE 	"\e[34m"
#define PURPLE 	"\e[35m"
#define CYAN 	"\e[36m"
#define WHITE 	"\e[37m"
#define CLEAR 	"\e[39m"

#define REDB 	"\e[41m"
#define GREENB	"\e[42m"
#define YELLOWB	"\e[43m"
#define BLUEB	"\e[44m"
#define PURPLEB	"\e[45m"
#define CYANB	"\e[46m"
#define WHITEB	"\e[47m"
#define CLEARB	"\e[49m"

#define UNDER	"\e[4m"
#define UUNDER	"\e[24m"

#define INVERSE	"\e[7m"
#define UINVER	"\e[27m"

#define BOLD	"\e[1m"
#define UNBOLD	"\e[21m"

#define LOC(y,x)	"\e["#y";"#x"H"

//#define MIDDLE(len)	"\e["#((COLUMNS-len)/2)"G"
//#define CENTER(

#define COLUMNS atoi(getenv("COLUMNS"))
#define LINES	atoi(getenv("LINES"))

#define CLEARSCR system("clear")
#define FFOUT 	fflush(stdout)

void print64(unsigned char a){
	switch(a){
	case 11:
		printf(
	"****************************************************************"CYANB" "PURPLEB
		);
		break;
	case 12:
		printf(
	"**                                                            **"CYANB" "PURPLEB
		);
		break;
	case 10:
		printf(
	"**********************    "GREEN""BOLD"MAIN    MENU"UNBOLD""CLEAR"    **********************"CYANB" "PURPLEB
		);
		break;
	case 1:
		printf(
	"**     1. "UNDER"C"UUNDER"reate a contact "WHITE""REDB"(Already Exist)"PURPLEB""CLEAR"                    **"CYANB" "PURPLEB
		);
		break;
	case 2:
		printf(
	"**     2. "UNDER"L"UUNDER"ist the contact                                    **"CYANB" "PURPLEB
		);
		break;
	case 3:
		printf(
	"**     3. "UNDER"A"UUNDER"dd a member to the contacts                        **"CYANB" "PURPLEB
		);
		break;
	case 4:
		printf(
	"**     4. "UNDER"D"UUNDER"elete a member form the contact                    **"CYANB" "PURPLEB
		);
		break;
	case 5:
		printf(
	"**     5. "UNDER"F"UUNDER"ind and Edit a member from the contacts            **"CYANB" "PURPLEB
		);
		break;
	case 6:
		printf(
	"**     6: "UNDER"S"UUNDER"ort your contacts                                  **"CYANB" "PURPLEB
		);
		break;
	case 7:
		printf(
	"**     7: S"UNDER"t"UUNDER"atistics                                          **"CYANB" "PURPLEB
		);
		break;
	case 8:
		printf(
	"**     8: Sa"UNDER"v"UUNDER"e your contacts                                  **"CYANB" "PURPLEB
		);
		break;
	case 9:
		printf(
	"**     9: C"UNDER"h"UUNDER"ange user password                                **"CYANB" "PURPLEB
		);
		break;
	case 0:
		printf(
	"**     0: "UNDER"E"UUNDER"xit                                                **"CYANB" "PURPLEB
		);
		break;
	case 13:
		printf(
	"**    Please select the number or enter "UNDER"underlined"UUNDER" letter     **"CYANB" "PURPLEB
		);
		break;
	case 14:
		printf(
	"                                                                "
		);
		break;
	case 15:
		printf(
	"**     1. Create a contact                                    **"CYANB" "PURPLEB
		);
		break;
	case 16:
		printf(
	BLUEB" "CYANB"                                                                "CLEAR
		);
		break;
	case 17:
		printf(
	"**                           "YELLOW""BOLD"About:"CLEAR""UNBOLD"                           **"CYANB" "PURPLEB
		);
		break;
	case 18:
		printf(
	"**          "GREEN"Thanks for using contacts manage system!"CLEAR"          **"CYANB" "PURPLEB
		);
		break;
	case 19:
		printf(
	"**                "YELLOW"Contacts Manage System V1.00"CLEAR"                **"CYANB" "PURPLEB
		);
		break;
	case 20:
		printf(
	"**                     "BLUE"Made by Ruilx Alxa"CLEAR"                     **"CYANB" "PURPLEB
		);
		break;
	case 21:
		printf(
	"**     "CYAN"in Xian University of Posts and Telecommunications"CLEAR"     **"CYANB" "PURPLEB
		);
		break;
	case 22:
		printf(
	"** "WHITE"Copyright (C) 2010-2013 GT-Soft Studio All Rights Reserved"CLEAR" **"CYANB" "PURPLEB
		);
		break;
	case 23:
		printf(
	"**          "GREEN"Please E-mail bugs to: "BLUE""UNDER"zrrabbit@gmail.com"UUNDER""CLEAR"         **"CYANB" "PURPLEB
		);
		break;
	case 24:
		printf(
	"**     "GREEN"Please visit our Homepage: "BLUE""UNDER"http://gtsoft.cwsurf.de"UUNDER""CLEAR"     **"CYANB" "PURPLEB
		);
		break;
	case 25:
		printf(
	"**      You haven't save your contact yet, if you still       **"CYANB" "REDB
		);
		break;
	case 26:
		printf(
	"**         exit, you may lost all your changes, Sure?         **"CYANB" "REDB
		);
		break;
	case 27:
		printf(
	"**  "YELLOW"1. "UNDER"S"UUNDER"ave & Exit"CLEAR"  **  "GREEN"2. "UNDER"M"UUNDER"ain Menu"CLEAR"  **  "PURPLE"3. "UNDER"D"UUNDER"iscard Exit"CLEAR"  ** **"CYANB" "REDB
		);
		break;
	case 28:
		printf(
	"****************************************************************"CYANB" "REDB
		);
		break;
	default:
		return;
	}
}

void menu(int mode){
	switch(mode){
		case 2:
	/*
	¨XStart with 8,21 (y,x)                              End with 8,84¨[
	08****************************************************************
	09**********************    MAIN    MENU    **********************#
	10****************************************************************#
	11**                                                            **#
	12**     1. Create a contact (Already Exist)                    **#
	13**     2. List the contact                                    **#
	14**     3. Add a member to the contacts                        **#
	15**     4. Delete a member form the contact                    **#
	16**     5. Find and Edit a member from the contacts            **#
	17**     6: Sort your contacts                                  **#
	18**     7: Statistics                                          **#
	19**     8: Save your contacts                                  **#
	20**     9: Change user password                                **#
	21**     0: Exit                                                **#
	22**                                                            **#
	23****************************************************************#
	24**                                                            **#
	25**    Please select the number or enter underlined letter     **#
	26**                                                            **#
	27****************************************************************#
	   ################################################################
	¨^Start with 27,21                                  End with 27,84¨a
	*/
	printf(BLUEB);		/* set background blue */
	FFOUT;			/* set display immediately */
	CLEARSCR;			/* paint display blue */
	printf(LOC(8,21));	/* set pointer at 8,21 */
	printf(PURPLEB);	/* set background purple */
	printf(CLEAR);		/* set font color to default */
	print64(11);		/* draw line 8 */
	printf(LOC(9,21));
	print64(10);		/* draw line 9 mainmenu */
	printf(LOC(10,21));
	print64(11);		/* draw line 10 */
	printf(LOC(11,21));
	print64(12);
	printf(LOC(12,21));
	print64(1);		/* 1 */
	printf(LOC(13,21));
	print64(2);		/* 2 */
	printf(LOC(14,21));
	print64(3);		/* 3 */
	printf(LOC(15,21));
	print64(4);		/* 4 */
	printf(LOC(16,21));
	print64(5);		/* 5 */
	printf(LOC(17,21));
	print64(6);		/* 6 */
	printf(LOC(18,21));
	print64(7);		/* 7 */
	printf(LOC(19,21));
	print64(8);		/* 8 */
	printf(LOC(20,21));
	print64(9);		/* 9 */
	printf(LOC(21,21));
	print64(0);		/* 0 */
	printf(LOC(22,21));
	print64(12);
	printf(LOC(23,21));
	print64(11);
	printf(LOC(24,21));
	print64(12);
	printf(LOC(25,21));
	print64(13);		/* select */
	printf(LOC(26,21));
	print64(12);
	printf(LOC(27,21));
	print64(11);
	printf(LOC(28,21));	/* shadow line */
	print64(16);
	printf(LOC(8,85));
	printf(BLUEB" ");	/* fix shadow */
	printf(LOC(25,78));	/* Location of enter */
	
		break;
		case 1:
	
	/*
	¨XStart with 12,21 (y,x)                            End with 12,84¨[
	12****************************************************************
	13**********************    MAIN    MENU    **********************#
	14****************************************************************#
	15**                                                            **#
	16**     1. Create a contact (Already Exist)                    **#
	17**     0: Exit                                                **#
	18**                                                            **#
	19****************************************************************#
	20**                                                            **#
	21**    Please select the number or enter underlined letter     **#
	22**                                                            **#
	23****************************************************************#
	   ################################################################
	¨^Start with 23,21                                  End with 23,84¨a
	*/

	printf(BLUEB);		/* set background blue */
	FFOUT;			/* set display immediately */
	CLEARSCR;			/* paint display blue */
	printf(LOC(12,21));	/* set pointer at 12,21 */
	printf(PURPLEB);	/* set background purple */
	printf(CLEAR);		/* set font color default */
	print64(11);		/* draw line 12 */
	printf(LOC(13,21));
	print64(10);		/* draw line 13 mainmenu */
	printf(LOC(14,21));
	print64(11);		/* draw line 14 */
	printf(LOC(15,21));
	print64(12);
	printf(LOC(16,21));
	print64(15);		/* 1 not exist */
	printf(LOC(17,21));
	print64(0);		/* 0 exit */
	printf(LOC(18,21));
	print64(12);
	printf(LOC(19,21));
	print64(11);
	printf(LOC(20,21));
	print64(12);
	printf(LOC(21,21));
	print64(13);		/* select */
	printf(LOC(22,21));
	print64(12);
	printf(LOC(23,21));
	print64(11);
	printf(LOC(24,21));	/* shadow line */
	print64(16);
	printf(LOC(12,85));
	printf(BLUEB" ");	/* fix shadow */
	printf(LOC(21,78));	/* Location of enter */
		break;
	default:
		return;
	}
}	

void about(void){
	/*
	11 22
	****************************************************************
	**                           About:                           **#
	****************************************************************#
	**          Thanks for using contacts manage system!          **#
	**                Contacts Manage System V1.00                **#
	**                     Made by Ruilx Alxa                     **#
	**     in Xian University of Posts and Telecommunications     **#
	**                                                            **#
	** Compright (C) 2010-2013 GT-Soft Studio All Rights Reserved **#
	**                                                            **#
	**          Please E-mail bugs to: zrrabbit@gmail.com         **#
	**     Please visit our Homepage: http://gtsoft.cwsurf.de     **#
	****************************************************************#
         ################################################################
	23 22
	*/
	printf(BLUEB);		/* set background blue */
	FFOUT;			/* set display immediately */
	CLEARSCR;			/* paint display blue */
	printf(LOC(11,22));	/* set pointer at 11,22 */
	printf(PURPLEB);	/* set background purple */
	print64(11);
	printf(LOC(12,22));
	print64(17);
	printf(LOC(13,22));
	print64(11);
	printf(LOC(14,22));
	print64(18);
	printf(LOC(15,22));
	print64(19);
	printf(LOC(16,22));
	print64(20);
	printf(LOC(17,22));
	print64(21);
	printf(LOC(18,22));
	print64(12);
	printf(LOC(19,22));
	print64(22);
	printf(LOC(20,22));
	print64(12);
	printf(LOC(21,22));
	print64(23);
	printf(LOC(22,22));
	print64(24);
	printf(LOC(23,22));
	print64(11);
	printf(LOC(24,22));	/* shadow line */
	print64(16);
	printf(LOC(11,86));
	printf(BLUEB" ");	/* fix shadow */
	printf(LOC(22,79));	/* Location of enter */
}

void asksave(void){
	/*
	15 21    84 15
	****************************************************************
	**      You haven't save your contact yet, if you still       **#
	**         exit, you may lost all your changes, Sure?         **#
	****************************************************************#
	**  1. Save & Exit  **  2. Main Menu  **  3. Discard Exit  ** **#
	****************************************************************#
	 ################################################################
	20 21
	*/
	printf(BLUEB);		/* set background blue */
	FFOUT;			/* set display immediately */
	CLEARSCR;			/* paint display blue */
	printf(LOC(15,21));	/* set pointer at 15,21 */
	printf(REDB);		/* set background red */
	print64(28);
	printf(LOC(16,21));
	print64(25);
	printf(LOC(17,21));
	print64(26);
	printf(LOC(18,21));
	print64(28);
	printf(LOC(19,21));
	print64(27);
	printf(LOC(20,21));
	print64(28);
	printf(LOC(21,21));	/* shadow line */
	print64(16);
	printf(LOC(15,85));
	printf(BLUEB" ");	/* fix shadow */
	printf(LOC(19,82));	/* Location of enter */
}

