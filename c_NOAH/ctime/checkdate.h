/***************************************************************
**  Checkdate Function Made By Ruilx Alxa in GT-Soft Studio   **
****************************************************************
** checkdate.c *************************************************
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
int Checkleapyear(int year){
	if(year % 100 == 0){
		if(year % 400 == 0)
			return 1;
		else
			return 0;
	}
	else{
		if(year % 4 == 0)
			return 1;
	}
	return 0;
}

int Dayinmonth(int month,int year){
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:return 31;break;
		case 4:
		case 6:
		case 9:
		case 11:return 30;break;
		case 2:
			if(Checkleapyear(year))
				return 29;
			else
				return 28;
			break;
		default:return 0;
	}
	return 0;
}

int Checkyear(int year){
	if(year>0){
		if(year<100){
			if(year>50){
				return 191;
			}else{
				return 201;
			}
		}else if(year>2100){
			return 0;
		}
	}else{
		return -1;
	}
	return 1;
}

int Checkmonth(int month){
	if(month< 1 || month>12){
		return 0;
	}
	return 1;
}

int Checkday(int day, int month, int year){
	if(day<1) return 0;
	if(day<=Dayinmonth(month,year)){
		return 1;
	}
	return 0;
}
