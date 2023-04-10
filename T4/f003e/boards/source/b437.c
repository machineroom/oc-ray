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
-- File:	b437.c
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Device dependent frame store library for the IMS-B437 Graphics TRAM.
--
-- **************************************************************************
--
-- History:	
--
-- (04-DEC-91) Bob Wipfel, Created file.
-- (06-JAN-91) Bob Wipfel,
--             + Added frame flyback synchronisation for FS_DISPLAYBANK.
--             + Added termination function FS_CLOSEBOARD().
-- (13-FEB-92) Bob Wipfel,
--             + Changed FS_OPENBOARD() to initialise VTG properly.
-- (22-APR-92) Bob Wipfel,
--             + Sense of IMS G332 reset bit is now inverted. When `0'
--             the G332 is held reset, when `1' reset is removed. After
--             a transputer reset the bit will be `0'.
-- (18-OCT-92) Bob Wipfel,
--             + Incorporated Gareth Jones' changes in fs_openboard().
--             This adds delays when programming the G332. Also removed
--             the redundant FRAME_SYNC when programming the palette.
--
-- **************************************************************************
*/
/*}}}*/

/*{{{  Include */
#include <process.h>

#include "fstore.h"
#include "fstorei.h"
#include "cgitypes.h"
/*}}}*/

/*{{{  FS_SCREENADDR */
char *FS_SCREENADDR( int bank )
{
  /* Return the address of a bank. Banks are mapped to VRAM from
     the top down. If the bank number would cause an address below
     the minimum VRAM address to be returned then return the address
     of bank 0.
  */

  if ( BANK_ADDRESS(bank) < VRAM_BASE )
    return( (char*) BANK_ADDRESS(0) );
  else
    return( (char*) BANK_ADDRESS(bank) );
}
/*}}}*/
/*{{{  FS_DISPLAYBANK */
void FS_DISPLAYBANK( int bank )
{
  FRAME_SYNC;
  /* Monitor now in flyback */
  POKE_CVC( TOP_OF_SCREEN, BANK_ADDRESS(bank) & 0x7fffffff );
}
/*}}}*/
/*{{{  FS_INITSCREEN */
void FS_INITSCREEN( screenptr s, int bank )
{
  /* Map a screen structure to a bank. This associates a screen with
     one of many possible VRAM banks, given by bank. The number of
     banks available depends on the VRAM size and display resolution.
     If there is no VRAM available for bank then map screen to bank 0
     (always available) and render it harmless.
  */

  if ( BANK_ADDRESS(bank) < VRAM_BASE )
  {
    s->stride = 0;
    s->xsize  = 0;  /* Screen of 0 by 0 is harmless */
    s->ysize  = 0;
    s->raster = (char*) BANK_ADDRESS(0);
  }
  else
  {
    s->stride = X_RES;
    s->xsize  = X_RES;
    s->ysize  = Y_RES;
    s->raster = (char*) BANK_ADDRESS( bank );
  }
}
/*}}}*/
/*{{{  FS_SETPALETTE */
void FS_SETPALETTE( int clutno, int red, int green, int blue )
{
  POKE_CLUT( clutno, blue + (green << 8) + (red << 16) );
}
/*}}}*/
/*{{{  FS_OPENBOARD */
void FS_OPENBOARD( VTG v )
{
  int i;

  vtg = v;  /* Save VTG setup */

  /* Setup board control registers and reset the G332.
     Will be the using 5MHz TRAM clock and G332's PLL. */

  POKE_BOARD( COLOUR_MODE,  0 );
  POKE_BOARD( CVC_RESET,    0 );	/* Assert G332 reset */

  POKE_BOARD( CLOCK_STROBE, 0 );	/* Ensure notStrobe */
  for ( i = 0; i < 5; i++ )
    POKE_BOARD( i, (2>>i) & 1 );	/* CLOCK_SELECT_0,1,2,3,4 */

  POKE_BOARD( CLOCK_STROBE, 1 );
  POKE_BOARD( CLOCK_STROBE, 0 );	/* Strobe clock select register */

  POKE_BOARD( CVC_RESET,    1 );
  POKE_BOARD( CVC_RESET,    0 );
  ProcWait(10);				/* Minimum G332 reset time */

  POKE_BOARD( CVC_RESET,    1 );	/* Release G332 from reset */

  /* First access to the G332 must be the boot location,
     write the PLL multiplication factor and enable PLL mode. */
  
  POKE_CVC( BOOT_LOCATION, (0x20 | vtg.pll) );
  ProcWait(15);

  POKE_CVC( CONTROL_REG, 0 );		/* Disable the VTG */
  ProcWait(15);
  
  POKE_CVC( MASK_REGISTER, 0xffffffff );
  ProcWait(15);

  POKE_CVC( 0xc7, 0 );		/* CURSOR_POS_REG */
  ProcWait(15);
  
  POKE_CVC( 0xa1, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);
  POKE_CVC( 0xa2, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);
  POKE_CVC( 0xa3, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);

  for ( i = 255; i < 768; i++ )
  {
    POKE_CVC( i, 0 );		/* CLUT_PALETTE */
    ProcWait(15);
  }
  
  POKE_CVC( 0xc0, 0 );		/* CHECKSUM_0 */
  ProcWait(15);
  POKE_CVC( 0xc1, 0 );		/* CHECKSUM_1 */
  ProcWait(15);
  POKE_CVC( 0xc2, 0 );		/* CHECKSUM_2 */
  ProcWait(15);
  
  /* Write the other display parameters to the G332 */

  POKE_CVC( LINE_TIME,      vtg.line_time );	/* Line timing */
  ProcWait(15);
  POKE_CVC( HALF_SYNC,      vtg.half_sync );
  ProcWait(15);
  POKE_CVC( BACK_PORCH,     vtg.back_porch );
  ProcWait(15);
  POKE_CVC( DISPLAY,        vtg.display );
  ProcWait(15);
  POKE_CVC( SHORT_DISPLAY,  vtg.short_display );
  ProcWait(15);
  POKE_CVC( V_DISPLAY,      vtg.v_display );	/* Frame timing */
  ProcWait(15);
  POKE_CVC( V_BLANK,        vtg.v_blank );
  ProcWait(15);
  POKE_CVC( V_SYNC,         vtg.v_sync );
  ProcWait(15);
  POKE_CVC( V_PREEQUALISE,  vtg.v_preequalise );
  ProcWait(15);
  POKE_CVC( V_POSTEQUALISE, vtg.v_postequalise );
  ProcWait(15);
  POKE_CVC( BROAD_PULSE,    vtg.broad_pulse );
  ProcWait(15);
  POKE_CVC( MEM_INIT,       vtg.mem_init );	/* VRAM cycles */
  ProcWait(15);
  POKE_CVC( TRANSFER_DELAY, vtg.transfer_delay );
  ProcWait(15);
  POKE_CVC( MASK_REGISTER,  vtg.mask_register );
  ProcWait(15);
  POKE_CVC( LINE_START,     BANK_ADDRESS(0) & 0x7fffffff );
  ProcWait(15);

  /* Program the CVC control register and start the VTG */

  if ( vtg.control != 0 )
    POKE_CVC( CONTROL_REG, vtg.control );
  else
    POKE_CVC( CONTROL_REG, 0xb42011 );
  ProcWait(15);
}
/*}}}*/
/*{{{  FS_CLOSEBOARD */
void FS_CLOSEBOARD( void )
{
  return;
}
/*}}}*/
/*{{{  FS_WRITEREGS */
void FS_WRITEREGS( int n, int *registers, int *contents )
{
  int i;

  for ( i = 0; i < n; i++ )
    *(int*)registers[i] = contents[i];
}
/*}}}*/

