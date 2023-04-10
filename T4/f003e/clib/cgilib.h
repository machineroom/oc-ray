/*{{{  Header */
/*
-- Copyright INMOS Limited 1991
--
-- **************************************************************************
--
-- Group:	Iq Software
--
-- Product:	IMS-F003
--
-- File:	cgilib.h
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Function prototypes for the CGI library. This defines the programmers
-- interface to the CGI display server.
--
-- **************************************************************************
--
-- History:	
--
-- (DD-MMM-90) Phil Atkin, Andy Hamilton, DIVISION Limited.
--             + Originated.
-- (29-NOV-91) Bob Wipfel.
--             + Added INMOS header.
--             + Added channel parameters to make RPC version of library.
--
-- **************************************************************************
*/
/*}}}*/

#ifndef _cgilib_h
#define _cgilib_h

#include <channel.h>
#include <process.h>
#include "cgitypes.h"

/* CGI display server */

extern void CgiServer( Process *, Channel *, Channel * );

/* Device independent frame store functions */

extern char *fs_screenaddr( Channel *, Channel *, int );
extern void fs_displaybank( Channel *, int );
extern void fs_initscreen( Channel *, Channel *, screen *, int );
extern void fs_setpalette( Channel *, int, int, int, int );
extern void fs_openboard( Channel *, VTG );
extern void fs_closeboard( Channel *, Channel * );
extern void fs_writeregs( Channel *, int, int *, int * );

/* CGI functions */

extern void cgi_init( Channel * );
extern int cgi_errstat( Channel *, Channel *, char *, int * );
extern void cgi_terminate ( Channel *, Channel * );

extern void cgi_setdrawmode( Channel *, int, int, int );
extern void cgi_setdrawscreen ( Channel *, screen );
extern int cgi_setfont( Channel *, Channel *, unsigned int *, int, int, int, int );
extern void cgi_setorient( Channel *, int );
extern void cgi_setpelstyle( Channel *, int, int, char *, int, int );
extern void cgi_setlinestyle( Channel *, int, char *, int );
extern void cgi_setfillstyle( Channel *, int, int, char * );
extern void cgi_setfcol( Channel *, int );
extern void cgi_setbcol( Channel *, int );

extern void cgi_line( Channel *, int, int, int, int );
extern void cgi_rect( Channel *, int, int, int, int );
extern void cgi_polyline( Channel *, int, int * );
extern void cgi_disjpolyline( Channel *, int, int * );
extern void cgi_polygon( Channel *, int, int * );
extern void cgi_circle( Channel *, int, int, int, int );

extern void cgi_arc( Channel *, int, int, int, int, int, int, int, int );
extern void cgi_arcc( Channel *, int, int, int, int, int, int, int, int, int );
extern void cgi_strokearc( Channel *, int, int, int, int, int, int, int, int, int );
extern void cgi_dot( Channel *, int, int );

extern void cgi_cls( Channel *, screen, int );
extern void cgi_frect( Channel *, int, int, int, int );
extern void cgi_fcircle( Channel *, int, int, int, int );
extern void cgi_fanfill( Channel *, int, int, int, int, int, int, int, int, int );
extern int cgi_search( Channel *, Channel *, int, int, int, int, int );
extern void cgi_paint( Channel *, int, int, int );
extern void cgi_ftrap( Channel *, int, int, int, int, int, int, int, int, int, int );
extern void cgi_fhline( Channel *, int, int, int * );

extern void cgi_text( Channel *, int, int, int, char * );
extern void cgi_addtext( Channel *, int, char * );
extern void cgi_sptext( Channel *, int, int, int, char *, int *, int * );
extern void cgi_addsptext( Channel *, int, char *, int *, int * );
extern void cgi_chrbegin( Channel *, int, int );
extern void cgi_chrspace( Channel *, int, int );
extern void cgi_chrz( Channel *, char, int, int );

extern void cgi_copy( Channel *, screen, int, int, int, int,
                                      screen, int, int );
extern void cgi_zoom( Channel *, screen, int, int, int, int,
                                      screen, int, int, int, int, int );
extern void cgi_rot( Channel *, screen, int, int, int, int, int, int, float );
extern void cgi_shear( Channel *, screen, int, int, int, int, 
                                               int, int, int, int, int, int );

#endif /* _cgilib_h */
