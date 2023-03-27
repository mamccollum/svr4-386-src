/*	Copyright (c) 1990 UNIX System Laboratories, Inc.	*/
/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF     	*/
/*	UNIX System Laboratories, Inc.                     	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989, 1990 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ident	"@(#)libyp:ypupd.c	1.2.1.1"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*	PROPRIETARY NOTICE (Combined)
*
* This source code is unpublished proprietary information
* constituting, or derived under license from AT&T's UNIX(r) System V.
* In addition, portions of such source code were derived from Berkeley
* 4.3 BSD under license from the Regents of the University of
* California.
*
*
*
*	Copyright Notice 
*
* Notice of copyright on this source code product does not indicate 
*  publication.
*
*	(c) 1986,1987,1988.1989  Sun Microsystems, Inc
*	(c) 1983,1984,1985,1986,1987,1988,1989  AT&T.
*          All rights reserved.
*/ 
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <rpc/rpc.h>
#include <rpcsvc/ypupd.h>
/* @(#)ypupdate_prot.x 1.4 88/02/08 Copyr 1986, Sun Micro */

/*
 * Compiled from ypupdate_prot.x using rpcgen
 * This is NOT source code!
 * DO NOT EDIT THIS FILE!
 */

bool_t
xdr_yp_buf(xdrs, objp)
	XDR *xdrs;
	yp_buf *objp;
{
	if (!xdr_bytes(xdrs, (char **)&objp->yp_buf_val, (u_int *)&objp->yp_buf_len, MAXYPDATALEN)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_ypupdate_args(xdrs, objp)
	XDR *xdrs;
	ypupdate_args *objp;
{
	if (!xdr_string(xdrs, &objp->mapname, MAXMAPNAMELEN)) {
		return (FALSE);
	}
	if (!xdr_yp_buf(xdrs, &objp->key)) {
		return (FALSE);
	}
	if (!xdr_yp_buf(xdrs, &objp->datum)) {
		return (FALSE);
	}
	return (TRUE);
}

bool_t
xdr_ypdelete_args(xdrs, objp)
	XDR *xdrs;
	ypdelete_args *objp;
{
	if (!xdr_string(xdrs, &objp->mapname, MAXMAPNAMELEN)) {
		return (FALSE);
	}
	if (!xdr_yp_buf(xdrs, &objp->key)) {
		return (FALSE);
	}
	return (TRUE);
}
