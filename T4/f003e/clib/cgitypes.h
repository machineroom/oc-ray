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
-- File:	cgitypes.h
--
-- Version:	1.0
--
-- **************************************************************************
--
-- Published CGI constants and type definitions.
--
-- **************************************************************************
--
-- History:	
--
-- (DD-MMM-90) Phil Atkin, Andy Hamilton, DIVISION Limited.
--             + Originated.
-- (29-NOV-91) Bob Wipfel.
--             + Added INMOS header and tidied up for IMS-F003.
--
-- **************************************************************************
*/
/*}}}*/

#ifndef _cgitypes_h
#define _cgitypes_h

#ifdef _FONT
/*{{{  font8by8 */
/* Font definition */

#define font_FAMW	8   /* Font width */
#define font_NCHARS	164 /* Number of characters */
#define font_FWPC	2   /* Words per character */
#define font_FLPW	4   /* Number of lines per word */

/* Font character cells */

static unsigned int font8by8[]= {
               0x00000000, 0x00000000,
               0x00000000, 0x00000001,
               /*{{{  0 - 31 */
               0x00000000, 0x00000002, 0x00000000, 0x00000003,
               0x00000000, 0x00000004, 0x00000000, 0x00000005,
               0x00000000, 0x00000006, 0x00000000, 0x00000007,
               0x00000000, 0x00000008, 0x00000000, 0x00000009,
               0x00000000, 0x0000000A, 0x00000000, 0x0000000B,
               0x00000000, 0x0000000C, 0x00000000, 0x0000000D,
               0x00000000, 0x0000000E, 0x00000000, 0x0000000F,
               0x00000000, 0x00000010, 0x00000000, 0x00000011,
               0x00000000, 0x00000012, 0x00000000, 0x00000013,
               0x00000000, 0x00000014, 0x00000000, 0x00000015,
               0x00000000, 0x00000016, 0x00000000, 0x00000017,
               0x00000000, 0x00000018, 0x00000000, 0x00000019,
               0x00000000, 0x0000001A, 0x00000000, 0x0000001B,
               0x00000000, 0x0000001C, 0x00000000, 0x0000001D,
               0x00000000, 0x0000001E, 0x00000000, 0x0000001F,
               /*}}}*/
               /*{{{  punctuation 32 - 47 */
               0x00000000, 0x00000000, 0x18181818, 0x00180018,
               0x006C6C6C, 0x00000000, 0x7CFE6C6C, 0x006C6CFE,
               0x3C583E18, 0x00187C1A, 0x18CCC600, 0x00C66630,
               0x76386C38, 0x0076CCDC, 0x00301818, 0x00000000,
               0x3030180C, 0x000C1830, 0x0C0C1830, 0x0030180C,
               0xFF3C6600, 0x0000663C, 0x7E181800, 0x00001818,
               0x00000000, 0x30181800, 0x7E000000, 0x00000000,
               0x00000000, 0x00181800, 0x30180C06, 0x0080C060,
               /*}}}*/
               /*{{{  0 - 9 */
               0xD6CEC67C, 0x007CC6E6, 0x18183818, 0x007E1818,
               0x3C06663C, 0x007E6660, 0x1C06463C, 0x003C6606,
               0x98583818, 0x003C18FE, 0x3C60627E, 0x003C6606,
               0x7C60663C, 0x003C6666, 0x0C06467E, 0x00181818,
               0x3C66663C, 0x003C6666, 0x3E66663C, 0x003C6606,
               /*}}}*/
               /*{{{  punctuation 58 - 64 */
               0x18180000, 0x00181800, 0x18180000, 0x30181800,
               0x6030180C, 0x000C1830, 0x007E0000, 0x00007E00,
               0x0C183060, 0x00603018, 0x0C06663C, 0x00180018,
               0xDEDEC67C, 0x007CC0DE,
               /*}}}*/
               /*{{{  A - Z */
               0x66663C18, 0x0066667E, 0x7C6666FC, 0x00FC6666,
               0xC0C0663C, 0x003C66C0, 0x66666CF8, 0x00F86C66,
               0x786862FE, 0x00FE6268, 0x786862FE, 0x00F06068,
               0xC0C0663C, 0x007EC6CE, 0x7E666666, 0x00666666,
               0x1818187E, 0x007E1818, 0x0C0C0C1E, 0x0078CCCC,
               0x786C66E6, 0x00E6666C, 0x606060F0, 0x00FE6662,
               0xFEFEEEC6, 0x00C6C6D6, 0xDEF6E6C6, 0x00C6C6CE,
               0xC6C66C38, 0x00386CC6, 0x786666FC, 0x00F06060,
               0xC6C66638, 0x0076CCDA, 0x7C6666FC, 0x00E2666C,
               0x3C60663C, 0x003C6606, 0x18185A7E, 0x003C1818,
               0x66666666, 0x003C6666, 0x66666666, 0x00183C66,
               0xD6C6C6C6, 0x00C6EEFE, 0x38386CC6, 0x00C6C66C,
               0x3C666666, 0x003C1818, 0x188CC6FE, 0x00FE6632,
               /*}}}*/
               /*{{{  punctuation 91 - 96 */
               0x3030303C, 0x003C3030, 0x183060C0, 0x0002060C,
               0x0C0C0C3C, 0x003C0C0C, 0x187E3C18, 0x00181818,
               0x00000000, 0xFF000000, 0x0C183000, 0x00000000,
               /*}}}*/
               /*{{{  a - z */
               0x0C780000, 0x0076CC7C, 0x667CE0E0, 0x00BC6666,
               0x663C0000, 0x003C6660, 0xCC7C0C1C, 0x0076CCCC,
               0x663C0000, 0x003C607E, 0x7830361C, 0x00783030,
               0x663E0000, 0x7C063E66, 0x766C60E0, 0x00E66666,
               0x18380018, 0x003C1818, 0x060E0006, 0x3C666606,
               0x6C6660E0, 0x00E6CE78, 0x18181838, 0x003C1818,
               0xFE6C0000, 0x00C6D6D6, 0x66D80000, 0x00666666,
               0x663C0000, 0x003C6666, 0x66DC0000, 0xF0607C66,
               0xCC760000, 0x1E0C7CCC, 0x366C0000, 0x00783030,
               0x603C0000, 0x007C063C, 0x307C3030, 0x001C3630,
               0x66660000, 0x003E6666, 0x66660000, 0x00183C66,
               0xD6C60000, 0x006CFED6, 0x6CC60000, 0x00C66C38,
               0x66660000, 0x7C063E66, 0x4C7E0000, 0x007E3018,
               /*}}}*/
               /*{{{  punctuation 123 - 126 */
               0x7018180E, 0x000E1818, 0x18181818, 0x00181818,
               0x0E181870, 0x00701818, 0x0000D876, 0x00000000,
               /*}}}*/
               /*{{{  others      127 - 159 */
               0x33CC33CC, 0x33CC33CC, 0x00000000, 0x00000000,
               0xF0F0F0F0, 0x00000000, 0x0F0F0F0F, 0x00000000,
               0xFFFFFFFF, 0x00000000, 0x00000000, 0xF0F0F0F0,
               0xF0F0F0F0, 0xF0F0F0F0, 0x0F0F0F0F, 0xF0F0F0F0,
               0xFFFFFFFF, 0xF0F0F0F0, 0x00000000, 0x0F0F0F0F,
               0xF0F0F0F0, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F,
               0xFFFFFFFF, 0x0F0F0F0F, 0x00000000, 0xFFFFFFFF,
               0xF0F0F0F0, 0xFFFFFFFF, 0x0F0F0F0F, 0xFFFFFFFF,
               0xFFFFFFFF, 0xFFFFFFFF, 0x18000000, 0x00000018,
               0x18181818, 0x00000018, 0x3F000000, 0x0000003F,
               0x1818181F, 0x0000000F, 0x18000000, 0x18181818,
               0x18181818, 0x18181818, 0x0F000000, 0x1818181F,
               0x1818181F, 0x1818181F, 0xFC000000, 0x000000FC,
               0xF8181818, 0x000000F0, 0xFF000000, 0x000000FF,
               0xFF181818, 0x000000FF, 0xF0000000, 0x181818F8,
               0xF8181818, 0xF11818F8, 0xFF000000, 0x181818FF,
               0xFF181818, 0x181818FF,
               /*}}}*/
               /*{{{  7 miscellaneous */
               0xFF99FF7E, 0x7EFFC3BD,
               0xFF99FF7E, 0x7EFFBDC3,
               0xFE38387C, 0x3810FEFE,
               0xFE7C3810, 0x0010387C,
               0xFEFEFE6C, 0x0010387C,
               0xFE7C3810, 0x003810FE,
               0xFFE16000, 0x0033333F,
               /*}}}*/
               0x00000000, 0x00000000 };

/*}}}*/
#endif

/*{{{  Define */
/* Maxima and minima */

#define maxLineStyle 128
#define maxPelSize   32
#define maxFontSize  64   /* Use 64 by 64 storage for chars */
#define maxFillSize  32

#define maxErrString 80   /* Maximum size of an error string */

#define maxPalette   256  /* Palette contains 256 colour values */

/* Fixed by the RPC packet size */

#define maxPoints       256   /* Max number of points */
#define maxString       2048  /* Max chars in a string */
#define maxSpacedString 512   /* Max chars in a spaced string */

#define max(v,w) (((v)>(w))?(v):(w))
#define min(v,w) (((v)>(w))?(w):(v))

#define screenaddr(s,x,y) ((x)+((y)*s->stride))
#define memaddr(s,x,y) (s->raster+screenaddr(s,x,y))
#define onscreen(s,x,y) ( ((x)>=0) & ((x)<s->xsize) & \
			  ((y)>=0) & ((y)<s->ysize) )

/* Blitting */

#define MOVE2DALL     0
#define MOVE2DZERO    1
#define MOVE2DNONZERO 2

/* Plot modes */

#define PM_COL         0
#define PM_LINESTYLE   1
#define PM_LINESTYLETR 4
#define PM_PEL         2
#define PM_LS_PEL      3

/* Fill modes */

#define FM_COL     0
#define FM_PATTERN 1

/* Arc close modes */

#define CM_SEGMENT 0
#define CM_CHORD   1
#define CM_OPEN    2

/* Replace modes */

#define RM_ALL  MOVE2DALL
#define RM_COL  RM_ALL
#define RM_Z    MOVE2DZERO
#define RM_NZ   MOVE2DNONZERO
#define RM_AND  (RM_ALL+3)
#define RM_OR   (RM_AND+1)
#define RM_XOR  (RM_OR+1)
#define RM_NOR  (RM_XOR+1)
#define RM_NAND (RM_NOR+1)

#define RM_TRANOP     (RM_AND-1)
#define RM_BOOLOP     (RM_AND)
#define RM_LASTBOOLOP (RM_NAND)

/* Search modes */

#define S_RIGHT    0
#define S_LEFT     1
#define S_WHILEGOT 2
#define S_WHILENOT 3

/* Text and flip modes */

#define TX_NORM     0  /* 0        */
#define TX_90       1  /* 90       */
#define TX_180      2  /* 180      */
#define TX_270      3  /* 270      */
#define TX_NORMFLIP 4  /* 0 flip   */
#define TX_90FLIP   5  /* 90 flip  */
#define TX_180FLIP  6  /* 180 flip */
#define TX_270FLIP  7  /* 270 filp */

/* Errors */

#define e_OK            0
#define e_BADPELMODE    1
#define e_BADREPMODE    2
#define e_BADFILLMODE   3
#define e_BADSEARCHDIRN 4
#define e_BADSEARCHTEST 5
#define e_BADSTACKMODE  6
#define e_BADFORIMODE   7

/* CGI server stack size */

#define CGI_STACK_SIZE 16384
/*}}}*/

/*{{{  Typedef */
typedef unsigned int  bool;
typedef unsigned char byte;

typedef void (*vfptr)(); /* void function ptr */

/* A screen. This is usually a description of a frame store sized
   raster, but is generalised to allow scratch pad screens, which are
   not displayed, to be used as the source or destination of image
   copy / transformation operations. */

typedef struct
{
  char *raster;
  int xsize, ysize, stride, multiMode;
} screen, *screenptr;

/* VTG parameters. These are independent of the CVC being used, ie:
   they support the IMS-G300B and IMS-G332. The `display' and `v_display'
   parameters define the size of the displayed frame. */

typedef struct
{
  int  pll,            /* Pixel clock PLL factor */

       line_time,      /* Line timing parameters */
       half_sync,
       back_porch,
       display,
       short_display,

       v_display,      /* Frame timing parameters */
       v_blank,       
       v_sync,
       v_preequalise,
       v_postequalise,
       broad_pulse,

       mem_init,       /* Frame store management */
       transfer_delay,
       mask_register,

       control;	       /* CVC control register */

} VTG, *VTGptr;
/*}}}*/

#endif /* _cgitypes_h */
