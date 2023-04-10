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
-- File:	b419.c
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Device dependent frame store library for the IMS-B419 Graphics TRAM.
--
-- Define _G300A for TRAMs with defunct IMS-G300A CVC rather than IMS-G300B.
--
-- **************************************************************************
--
-- History:	
--
-- (04-DEC-91) Bob Wipfel, Created file.
-- (06-JAN-91) Bob Wipfel,
--             + Added frame flyback synchronisation for FS_DISPLAYBANK.
--             + Added termination function FS_CLOSEBOARD().
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
  POKE_CVC( TOP_OF_SCREEN, (BANK_ADDRESS(bank) - VRAM_BASE) / 512 );
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
  FRAME_SYNC;
  /* Monitor now in flyback */
  POKE_CLUT( clutno, red + (green << 8) + (blue << 16) );
}
/*}}}*/
/*{{{  FS_OPENBOARD */
void FS_OPENBOARD( VTG v )
{
  vtg = v;  /* Save VTG setup */

  /* Setup board control registers and reset the G300.
     Will be the using 5MHz TRAM clock and G300's PLL. */

  POKE_BOARD( CLOCK_SELECT, 0 );  /* 5MHz clock */

  POKE_BOARD( CVC_RESET, 1 );  /* Reset the G300 */
  ProcWait(20);
  POKE_BOARD( CVC_RESET, 0 );

  /* First access to the G300 must be the boot location,
     write the PLL multiplication factor and enable PLL mode. */

#ifdef _G300A
  POKE_CVC( BOOT_LOCATION, vtg.pll );
#else
  POKE_CVC( BOOT_LOCATION, vtg.pll | 0x20 );
#endif

  POKE_CVC( CONTROL_REG, 0 );  /* Disable the VTG */

  /* Write the other display parameters to the G300 */

  POKE_CVC( LINE_TIME, vtg.line_time );	/* Line timing */
  POKE_CVC( HALF_SYNC, vtg.half_sync );
  POKE_CVC( BACK_PORCH, vtg.back_porch );
  POKE_CVC( DISPLAY, vtg.display );
  POKE_CVC( SHORT_DISPLAY, vtg.short_display );

  POKE_CVC( V_DISPLAY, vtg.v_display );	/* Frame timing */
  POKE_CVC( V_BLANK, vtg.v_blank );
  POKE_CVC( V_SYNC, vtg.v_sync );
  POKE_CVC( BROAD_PULSE, vtg.broad_pulse );

  POKE_CVC( MEM_INIT, vtg.mem_init );	/* VRAM cycles */
  POKE_CVC( TRANSFER_DELAY, vtg.transfer_delay );
  POKE_CVC( MASK_REGISTER, vtg.mask_register );
  POKE_CVC( LINE_START, (BANK_ADDRESS(0) - VRAM_BASE) / 512 );

  /* Program the CVC control register and start the VTG */

  if ( vtg.control != 0 )
    POKE_CVC( CONTROL_REG, vtg.control );
  else
#ifdef _G300A
    POKE_CVC( CONTROL_REG, 0x1 );
#else
    POKE_CVC( CONTROL_REG, 0x70001 );  /* See the data sheet */
#endif

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

