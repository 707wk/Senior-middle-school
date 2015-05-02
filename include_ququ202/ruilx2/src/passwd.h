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

#ifndef _PASSWD_H_
#define _PASSWD_H_

int accept(char *a);

int passwd(void);

int createpass(char *a);

int changepasswd(void);

#endif
/* accept: check a and file are correct
   passwd: Enter password system
   createpass: create a new password */
