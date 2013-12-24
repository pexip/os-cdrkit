/*
 * This file has been modified for the cdrkit suite.
 *
 * The behaviour and appearence of the program code below can differ to a major
 * extent from the version distributed by the original author(s).
 *
 * For details, see Changelog file distributed with the cdrkit package. If you
 * received this file from another source then ask the distributing person for
 * a log of modifications.
 *
 */

/* @(#)libport.h	1.9 03/06/15 Copyright 1995 J. Schilling */
/*
 *	Copyright (c) 1995 J. Schilling
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; see the file COPYING.  If not, write to the Free Software
 * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef _LIBPORT_H
#define	_LIBPORT_H

#ifndef	_MCONFIG_H
#include <mconfig.h>
#endif
#ifndef	_PROTOTYP_H
#include <prototyp.h>
#endif
#ifndef _STANDARD_H
#include <standard.h>
#endif

/*
 * Try to get HOST_NAME_MAX for gethostname()
 */
#ifndef _UNIXSTD_H
#include <unixstd.h>
#endif

#ifndef HOST_NAME_MAX
#if	defined(HAVE_NETDB_H) && !defined(HOST_NOT_FOUND) && \
				!defined(_INCL_NETDB_H)
#include <netdb.h>
#define	_INCL_NETDB_H
#endif
#ifdef	MAXHOSTNAMELEN
#define	HOST_NAME_MAX	MAXHOSTNAMELEN
#endif
#endif

#ifndef HOST_NAME_MAX
#ifdef	HAVE_SYS_PARAM_H
#include <sys/param.h>	/* Include various defs needed with some OS */
			/* Linux MAXHOSTNAMELEN */
#endif
#ifdef	MAXHOSTNAMELEN
#ifndef HOST_NAME_MAX
#define	HOST_NAME_MAX	MAXHOSTNAMELEN
#endif
#endif
#endif

#ifndef HOST_NAME_MAX
#define	HOST_NAME_MAX	255
#endif

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	OPENSERVER
/*
 * Don't use the usleep() from libc on SCO's OPENSERVER.
 * It will kill our processes with SIGALRM.
 */
/*
 * Don't #undef HAVE_USLEEP in this file, SCO has a
 * usleep() prototype in unistd.h
 */
/*#undef	HAVE_USLEEP*/
#endif

#ifndef	HAVE_GETHOSTID
extern	long		gethostid(void);
#endif
#ifndef	HAVE_GETHOSTNAME
extern	int		gethostname(char *name, int namelen);
#endif
#ifndef	HAVE_GETDOMAINNAME
extern	int		getdomainname(char *name, int namelen);
#endif
#ifndef	HAVE_GETPAGESIZE
int		getpagesize(void);
#endif
#ifndef	HAVE_USLEEP
extern	int		usleep(int usec);
#endif

#if	!defined(HAVE_STRDUP) || defined(__SVR4)
extern	char		*strdup(const char *s);
#endif

#ifndef	HAVE_RENAME
extern	int		rename(const char *old, const char *new);
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBPORT_H */
