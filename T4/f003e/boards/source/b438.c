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
-- File:	b438.c
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Device dependent frame store library for the IMS-B438 Graphics TRAM.
--
-- **************************************************************************
--
-- History:	
--
-- (18-OCT-92) Bob Wipfel, Created file.
-- (28-MAR-94) Steve Christian, mofified delay structure to make more reliable
--             in low frequency mode
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

  /* Reset the G335. */

  POKE_BOARD( CVC_RESET, 1 );		/* Assert G335 reset */
  ProcWait(10);				/* Minimum reset time */
  POKE_BOARD( CVC_RESET, 0 );		/* Release G335 from reset */

  /* First access to the G335 must be the boot location,
     write the PLL multiplication factor and enable PLL mode. */
  
  POKE_CVC( BOOT_LOCATION, (0x20 | vtg.pll) );
  ProcWait(15);

  POKE_CVC( CONTROL_REG, 0 );		/* Disable the VTG */
  ProcWait(2);
  
  /*
   * Bit 0  (Pixel sampling mode)   1 = External
   * Bit 1  (DAC Sync pedestals)    1 = Sync on green only
   * Bit 2  (Flyback waveform)      0 = No Hsync during flyback
   * Bit 3  (VRAM SAM style)        1 = Split SAMs
   */
  POKE_CVC( CONTROL_REG_B, 0xb );
  ProcWait(15);
  
  POKE_CVC( MASK_REGISTER, 0xffffffff );
  ProcWait(15);

  /*
   * Reset the cursor stuff, not using it anyway
   */
  POKE_CVC( 0xc7, 0 );		/* CURSOR_POS_REG */
  ProcWait(15);
  
  POKE_CVC( 0xa1, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);
  POKE_CVC( 0xa2, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);
  POKE_CVC( 0xa3, 0 );		/* CURSOR_PALETTE */
  ProcWait(15);

  /*
   * Clear the colour palette and cursor store
   */
  for ( i = 256; i < 768; i++ )
  {
    POKE_CVC( i, 0 );
    ProcWait(15);
  }

  /*
   * Clear the checksum registers
   */
  POKE_CVC( 0xc0, 0 );		/* CHECKSUM_0 */
  ProcWait(15);
  POKE_CVC( 0xc1, 0 );		/* CHECKSUM_1 */
  ProcWait(15);
  POKE_CVC( 0xc2, 0 );		/* CHECKSUM_2 */
  ProcWait(15);
  
  /* Write the other display parameters to the G335 */

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
    POKE_CVC( CONTROL_REG, 0xb43011 );
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

