/*	Copyright (c) 1990 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/


#ident	"@(#)libplot:plot/label.c	1.3"
#include <stdio.h>
label(s)
char *s;
{
	int i;
	putc('t',stdout);
	for(i=0;s[i];)putc(s[i++],stdout);
	putc('\n',stdout);
}
