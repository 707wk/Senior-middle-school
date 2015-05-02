/***************************************************************
**  Checkdate Function Made By Ruilx Alxa in GT-Soft Studio   **
****************************************************************
** checkdate.h *************************************************
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

#ifndef _CHECKDATE_H_
#define _CHECKDATE_H_

int Checkleapyear(int year);

int Dayinmonth(int month, int year);

int Checkyear(int year);

int Checkmonth(int month);

int Checkday(int day, int month, int year);

#endif
/***************************************************************
These functions are used to determine if you have entered the 
date is within the specified range, the leap year and each month 
limit, all the number of days may not be the same, except 
Checkmonth return value is the number of days, the other returns
1 of normal, 0 exceeded.
***************************************************************/