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
-- File:	fstore.h
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Prototype declaration file for functions supported by the device
-- independent frame store library. These are called by the CGI display
-- server and will not be called by user programs.
--
-- **************************************************************************
--
-- History:	
--
-- (29-NOV-91) Bob Wipfel, Created file.
-- (06-JAN-92) Bob Wipfel,
--             + Added prototype for FS_CLOSEBOARD().
--
-- **************************************************************************
--
*/
/*}}}*/

/*{{{  Include */
#include "cgitypes.h"
/*}}}*/

/* Device independent frame store interface */

extern char *FS_SCREENADDR( int );
extern void FS_DISPLAYBANK( int );
extern void FS_INITSCREEN( screen *, int );
extern void FS_SETPALETTE( int, int, int, int );
extern void FS_OPENBOARD( VTG );
extern void FS_CLOSEBOARD( void );
extern void FS_WRITEREGS( int, int *, int * );
