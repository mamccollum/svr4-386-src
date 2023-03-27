/*	Copyright (c) 1990 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/


#ident	"@(#)ucbplot:libplot/vt0/space.c	1.1.3.1"

/*
 * Copyright (c) 1983, 1984 1985, 1986, 1987, 1988, Sun Microsystems, Inc.
 * All Rights Reserved.
 */

extern float boty;
extern float botx;
extern float oboty;
extern float obotx;
extern float scalex;
extern float scaley;
float deltx = 4095.;
float delty = 4095.;
space(x0,y0,x1,y1){
	botx = -2047.;
	boty = -2047;
	obotx = x0;
	oboty = y0;
	scalex = deltx/(x1-x0);
	scaley = delty/(y1-y0);
}
