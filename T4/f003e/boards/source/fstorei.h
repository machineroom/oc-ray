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
-- File:	fstorei.h
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Internal constants for the device independent frame store library.
-- This defines a common set of constants and macros for use by each of
-- the device dependent frame store libraries.
--
-- Define _B419 for the IMS-B419 graphics TRAM.
-- Define _B437 for the IMS-B437 compact display TRAM.
--
-- **************************************************************************
--
-- History:	
--
-- (28-NOV-91) Bob Wipfel, Created file.
-- (06-JAN-92) Bob Wipfel, 
--             + Added FRAME_SYNC macro.
-- (21-OCT-92) Bob Wipfel,
--             + Added support for the new IMS-B438 graphics TRAM.
--               Define _B438.
-- (19-JAN-93) Bob Wipfel,
--             + Preparation for IMS-F003D product build.
--
-- **************************************************************************
--
*/
/*}}}*/

#ifndef _fstorei_h
#define _fstorei_h

/*{{{  Include */
#include "cgitypes.h"
#include <channel.h>
/*}}}*/

/*{{{  Supported Graphics TRAMs */
#ifdef _B419
/*{{{  Video RAM layout */
/* Video RAM available. The number of banks available
   (which are mapped to screens) depends on the display
   resolution and the amount of VRAM present. */

#define VRAM_BASE	0x80200000  /* With jumper JP4 fitted */
#define VRAM_TOP	0x80400000
/*}}}*/
/*{{{  Board control registers */
/* Board control register base address */

#define BOARD_REG_BASE	0x000000f0

/* Board control register offsets. These are word
   offsets from the control register base address. */

#define CVC_RESET	0
#define CLOCK_SELECT	1
/*}}}*/
/*{{{  IMS-G300B CVC and palette */
/* CVC base addess. All registers are accessed
   at positive offsets from this address, including
   the colour look up table. */

#define CVC_REG_BASE	0x40000000

/* Register offsets. These are word offsets from
   the CVC base address. */

#define BOOT_LOCATION	0x1A0

/* Line timing parameters */

#define LINE_TIME	0x129
#define HALF_SYNC	0x121
#define BACK_PORCH	0x122
#define DISPLAY		0x123
#define SHORT_DISPLAY	0x124

/* Frame timing parameters */

#define V_DISPLAY	0x128
#define V_BLANK		0x127
#define V_SYNC		0x126
#define BROAD_PULSE	0x125

/* Frame store management */

#define TOP_OF_SCREEN	0x180
#define CONTROL_REG	0x160
#define MASK_REGISTER	0x140
#define LINE_START	0x12A
#define MEM_INIT	0x12B
#define TRANSFER_DELAY	0x12C

/* Colour palette base address. There are 256 locations,
   each 24 bits wide, located at word offsets from the base
   address. The high order 8 bits should be ignored. */

#define PALETTE_BASE	CVC_REG_BASE
/*}}}*/
#endif

#ifdef _B437
/*{{{  Video RAM layout */
/* Video RAM available. The number of banks available
   (which are mapped to screens) depends on the display
   resolution and the amount of VRAM present. */

#define VRAM_BASE	0x80001000
#define VRAM_TOP	0x80101000
/*}}}*/
/*{{{  Board control registers */
/* Board control register base address */

#define BOARD_REG_BASE	0x40000000

/* Board control register offsets. These are word
   offsets from the control register base address. */

#define CLOCK_SELECT_0	0
#define CLOCK_SELECT_1	1
#define CLOCK_SELECT_2	2
#define CLOCK_SELECT_3	3
#define CLOCK_SELECT_4	4
#define COLOUR_MODE	5
#define CLOCK_STROBE	6
#define CVC_RESET	7
/*}}}*/
/*{{{  IMS-G332 CVC and palette */
/* CVC base addess. All registers are accessed
   at positive offsets from this address, including
   the colour look up table. */

#define CVC_REG_BASE	0x0

/* Register offsets. These are word offsets from
   the CVC base address. */

#define BOOT_LOCATION	0x0

/* Line timing parameters */

#define LINE_TIME     0x02b
#define HALF_SYNC     0x021
#define BACK_PORCH    0x022
#define DISPLAY       0x023
#define SHORT_DISPLAY 0x024

/* Frame timing parameters */

#define V_DISPLAY      0x02a
#define V_BLANK        0x029
#define V_SYNC         0x026
#define V_PREEQUALISE  0x027
#define V_POSTEQUALISE 0x028
#define BROAD_PULSE    0x025

/* Frame store management */

#define TOP_OF_SCREEN  0x080
#define CONTROL_REG    0x060
#define MASK_REGISTER  0x040
#define LINE_START     0x02c
#define MEM_INIT       0x02d
#define TRANSFER_DELAY 0x02e

/* Colour palette base address. There are 256 locations,
   each 24 bits wide, located at word offsets from the base
   address. The high order 8 bits should be ignored. */

#define PALETTE_BASE	(CVC_REG_BASE+0x400)
/*}}}*/
#endif

#ifdef _B438
/*{{{  Video RAM layout */
/* Video RAM available. The number of banks available
   (which are mapped to screens) depends on the display
   resolution and the amount of VRAM present. */

#define VRAM_BASE	0x80400000
#define VRAM_TOP	0x80600000
/*}}}*/
/*{{{  Board control registers */
/* Board control register base address */

#define BOARD_REG_BASE	0x200000

/* Board control register offsets. These are word
   offsets from the control register base address. */

#define CVC_RESET	0
/*}}}*/
/*{{{  IMS-G335 CVC and palette */
/* CVC base addess. All registers are accessed
   at positive offsets from this address, including
   the colour look up table. */

#define CVC_REG_BASE	0x0

/* Register offsets. These are word offsets from
   the CVC base address. */

#define BOOT_LOCATION	0x0

/* Line timing parameters */

#define LINE_TIME     0x02b
#define HALF_SYNC     0x021
#define BACK_PORCH    0x022
#define DISPLAY       0x023
#define SHORT_DISPLAY 0x024

/* Frame timing parameters */

#define V_DISPLAY      0x02a
#define V_BLANK        0x029
#define V_SYNC         0x026
#define V_PREEQUALISE  0x027
#define V_POSTEQUALISE 0x028
#define BROAD_PULSE    0x025

/* Frame store management */

#define TOP_OF_SCREEN  0x080
#define CONTROL_REG    0x060
#define CONTROL_REG_B  0x070
#define MASK_REGISTER  0x040
#define LINE_START     0x02c
#define MEM_INIT       0x02d
#define TRANSFER_DELAY 0x02e

/* Colour palette base address. There are 256 locations,
   each 24 bits wide, located at word offsets from the base
   address. The high order 8 bits should be ignored. */

#define PALETTE_BASE	(CVC_REG_BASE+0x400)
/*}}}*/
#endif

/*}}}*/

static VTG vtg;		/* VTG setup values */

#define X_RES			(vtg.display<<2)
#define Y_RES			(vtg.v_display>>1)
#define POKE_CVC(reg,val)	*(int*)(CVC_REG_BASE+(reg*4))=val
#define POKE_BOARD(reg,val)	*(int*)(BOARD_REG_BASE+(reg*4))=val
#define POKE_CLUT(c,val)	*(int*)(PALETTE_BASE+(c*4))=val
#define BANK_ADDRESS(bank)	( VRAM_TOP - ((bank+1)*X_RES*Y_RES) )

/* Frame flyback is signalled by EventReq. When synchronisation
   is required this macro will consume any outstanding Event and
   then synchronise with flyback by waiting for the next one. */
   
#define FRAME_SYNC { char a; a = ChanInChar(EVENT); a = ChanInChar(EVENT); }

#endif /* _fstorei_h */
