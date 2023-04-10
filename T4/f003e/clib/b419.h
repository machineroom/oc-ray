/*{{{  Header */
/*
-- Copyright INMOS Limited 1992
--
-- **************************************************************************
--
-- Group:	Iq Software
--
-- Product:	IMS-F003
--
-- File:	b419.h
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Video timing parameter blocks for different monitors, display resolutions
-- and pixel clock rates.
--
-- **************************************************************************
--
-- History:	
--
-- IMS-B419 specific version.
--
-- **************************************************************************
*/
/*}}}*/

#ifndef _b419_h
#define _b419_h

/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 105 Mhz
 * Display resolution  : 1280 by 1024
 * Suitable monitor    : Hitachi
 *
 *------------------------------------------------------------
 */

#define V_1280_1024_HITACHI	{ 0x15,		/* pll */ \
				  422,		/* line_time */ \
				  0x15,		/* half_sync */ \
				  0x36,		/* back_porch */ \
				  320,		/* display */ \
				  109,		/* short_display */ \
				  2048,		/* v_display */ \
				  56,		/* v_blank */ \
				  6,		/* v_sync */ \
				  8,		/* v_preequalise */ \
				  8,		/* v_postequalise */ \
				  205,		/* broad_pulse */ \
				  489,		/* mem_init */ \
				  0x17,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \

/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 65 Mhz
 * Display resolution  : 1024 by 768
 * Suitable monitor    : NEC Multisync XL
 *
 *------------------------------------------------------------
 */

#define V_1024_768_NEC_XL	{ 0xd,		/* pll */ \
				  0x14a,	/* line_time */ \
				  0x8,		/* half_sync */ \
				  0x2e,		/* back_porch */ \
				  0x100,	/* display */ \
				  0x5b,		/* short_display */ \
				  1536,		/* v_display */ \
				  0x38,		/* v_blank */ \
				  8,		/* v_sync */ \
				  8,		/* v_preequalise */ \
				  8,		/* v_postequalise */ \
				  0x99,		/* broad_pulse */ \
				  0x1eb,	/* mem_init */ \
				  0x15,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \


/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 25 Mhz
 * Display resolution  : 640 by 480
 * Suitable monitor    : IBM VGA 8513002 and 8512002
 *
 *------------------------------------------------------------
 */

#define V_640_480_IBM_VGA	{ 0x5,		/* pll */ \
				  202,		/* line_time */ \
				  8,		/* half_sync */ \
				  20,		/* back_porch */ \
				  160,		/* display */ \
				  61,		/* short_display */ \
				  960,		/* v_display */ \
				  80,		/* v_blank */ \
				  4,		/* v_sync */ \
				  4,		/* v_preequalise */ \
				  4,		/* v_postequalise */ \
				  75,		/* broad_pulse */ \
				  494,		/* mem_init */ \
				  18,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \

/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 35 Mhz
 * Display resolution  : 800 by 600
 * Suitable monitor    : NEC Multisync II or III
 *
 *------------------------------------------------------------
 */

#define V_800_600_NEC_II	{ 0x7,		/* pll */ \
				  250,		/* line_time */ \
				  7,		/* half_sync */ \
				  30,		/* back_porch */ \
				  200,		/* display */ \
				  75,		/* short_display */ \
				  1200,		/* v_display */ \
				  80,		/* v_blank */ \
				  8,		/* v_sync */ \
				  8,		/* v_preequalise */ \
				  8,		/* v_postequalise */ \
				  117,		/* broad_pulse */ \
				  497,		/* mem_init */ \
				  15,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \

/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 65 Mhz
 * Display resolution  : 1024 by 768
 * Suitable monitor    : NEC Multisync XL or 5D
 *
 *------------------------------------------------------------
 */

#define V_1024_768_NEC_5D	{ 0xd,		/* pll */ \
				  332,		/* line_time */ \
				  8,		/* half_sync */ \
				  49,		/* back_porch */ \
				  256,		/* display */ \
				  90,		/* short_display */ \
				  1536,		/* v_display */ \
				  44,		/* v_blank */ \
				  8,		/* v_sync */ \
				  4,		/* v_preequalise */ \
				  4,		/* v_postequalise */ \
				  150,		/* broad_pulse */ \
				  486,		/* mem_init */ \
				  26,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \

/*------------------------------------------------------------
 * Video timing parameters
 *
 * Pixel rate          : 25 Mhz
 * Display resolution  : 640 by 480
 * Suitable monitor    : TANDON TC0512 and TC0513
 *
 *------------------------------------------------------------
 */

#define V_640_480_TC051X	{ 0x5,		/* pll */ \
				  196,		/* line_time */ \
				  3,		/* half_sync */ \
				  19,		/* back_porch */ \
				  160,		/* display */ \
				  62,		/* short_display */ \
				  960,		/* v_display */ \
				  28,		/* v_blank */ \
				  8,		/* v_sync */ \
				  4,		/* v_preequalise */ \
				  4,		/* v_postequalise */ \
				  87,		/* broad_pulse */ \
				  494,		/* mem_init */ \
				  18,		/* transfer_delay */ \
				  0xffffff,	/* mask_register */ \
				  0 }		/* control */ \

/* Default 1024 by 768 */

#define V_1024_768 V_1024_768_NEC_XL

#endif /* _b419_h */
