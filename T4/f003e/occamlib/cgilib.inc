--{{{  Header
--
-- Copyright INMOS Limited 1991
--
-- **************************************************************************
--
-- Group:	Iq Software
--
-- Product:	IMS-F003
--
-- File:	cgilib.inc
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
-- (09-DEC-91) Bob Wipfel.
--             + Originated from C version.
-- (12-DEC-91) Bob Wipfel.
--             + Added PRAGMA for CGI server process.
-- (19-JAN-93) Bob Wipfel.
--             + Changes for IMS-Dx305 occam toolset.
--
-- **************************************************************************
--
--}}}

--{{{  Font
-- Font definition

VAL font.FAMW   IS 8 :   -- Font width
VAL font.NCHARS IS 164 : -- Number of characters
VAL font.FWPC   IS 2 :   -- Words per character
VAL font.FLPW   IS 4 :   -- Number of lines per word

-- Font character cells

VAL []INT FONT.8.BY.8 IS [ #00000000, #00000000,
                           #00000000, #00000001,
                           --{{{  0 - 31
                           #00000000, #00000002, #00000000, #00000003,
                           #00000000, #00000004, #00000000, #00000005,
                           #00000000, #00000006, #00000000, #00000007,
                           #00000000, #00000008, #00000000, #00000009,
                           #00000000, #0000000A, #00000000, #0000000B,
                           #00000000, #0000000C, #00000000, #0000000D,
                           #00000000, #0000000E, #00000000, #0000000F,
                           #00000000, #00000010, #00000000, #00000011,
                           #00000000, #00000012, #00000000, #00000013,
                           #00000000, #00000014, #00000000, #00000015,
                           #00000000, #00000016, #00000000, #00000017,
                           #00000000, #00000018, #00000000, #00000019,
                           #00000000, #0000001A, #00000000, #0000001B,
                           #00000000, #0000001C, #00000000, #0000001D,
                           #00000000, #0000001E, #00000000, #0000001F,
                           --}}}
                           --{{{  punctuation 32 - 47
                           #00000000, #00000000, #18181818, #00180018,
                           #006C6C6C, #00000000, #7CFE6C6C, #006C6CFE,
                           #3C583E18, #00187C1A, #18CCC600, #00C66630,
                           #76386C38, #0076CCDC, #00301818, #00000000,
                           #3030180C, #000C1830, #0C0C1830, #0030180C,
                           #FF3C6600, #0000663C, #7E181800, #00001818,
                           #00000000, #30181800, #7E000000, #00000000,
                           #00000000, #00181800, #30180C06, #0080C060,
                           --}}}
                           --{{{  0 - 9
                           #D6CEC67C, #007CC6E6, #18183818, #007E1818,
                           #3C06663C, #007E6660, #1C06463C, #003C6606,
                           #98583818, #003C18FE, #3C60627E, #003C6606,
                           #7C60663C, #003C6666, #0C06467E, #00181818,
                           #3C66663C, #003C6666, #3E66663C, #003C6606,
                           --}}}
                           --{{{  punctuation 58 - 64
                           #18180000, #00181800, #18180000, #30181800,
                           #6030180C, #000C1830, #007E0000, #00007E00,
                           #0C183060, #00603018, #0C06663C, #00180018,
                           #DEDEC67C, #007CC0DE,
                           --}}}
                           --{{{  A - Z
                           #66663C18, #0066667E, #7C6666FC, #00FC6666,
                           #C0C0663C, #003C66C0, #66666CF8, #00F86C66,
                           #786862FE, #00FE6268, #786862FE, #00F06068,
                           #C0C0663C, #007EC6CE, #7E666666, #00666666,
                           #1818187E, #007E1818, #0C0C0C1E, #0078CCCC,
                           #786C66E6, #00E6666C, #606060F0, #00FE6662,
                           #FEFEEEC6, #00C6C6D6, #DEF6E6C6, #00C6C6CE,
                           #C6C66C38, #00386CC6, #786666FC, #00F06060,
                           #C6C66638, #0076CCDA, #7C6666FC, #00E2666C,
                           #3C60663C, #003C6606, #18185A7E, #003C1818,
                           #66666666, #003C6666, #66666666, #00183C66,
                           #D6C6C6C6, #00C6EEFE, #38386CC6, #00C6C66C,
                           #3C666666, #003C1818, #188CC6FE, #00FE6632,
                           --}}}
                           --{{{  punctuation 91 - 96
                           #3030303C, #003C3030, #183060C0, #0002060C,
                           #0C0C0C3C, #003C0C0C, #187E3C18, #00181818,
                           #00000000, #FF000000, #0C183000, #00000000,
                           --}}}
                           --{{{  a - z
                           #0C780000, #0076CC7C, #667CE0E0, #00BC6666,
                           #663C0000, #003C6660, #CC7C0C1C, #0076CCCC,
                           #663C0000, #003C607E, #7830361C, #00783030,
                           #663E0000, #7C063E66, #766C60E0, #00E66666,
                           #18380018, #003C1818, #060E0006, #3C666606,
                           #6C6660E0, #00E6CE78, #18181838, #003C1818,
                           #FE6C0000, #00C6D6D6, #66D80000, #00666666,
                           #663C0000, #003C6666, #66DC0000, #F0607C66,
                           #CC760000, #1E0C7CCC, #366C0000, #00783030,
                           #603C0000, #007C063C, #307C3030, #001C3630,
                           #66660000, #003E6666, #66660000, #00183C66,
                           #D6C60000, #006CFED6, #6CC60000, #00C66C38,
                           #66660000, #7C063E66, #4C7E0000, #007E3018,
                           --}}}
                           --{{{  punctuation 123 - 126
                           #7018180E, #000E1818, #18181818, #00181818,
                           #0E181870, #00701818, #0000D876, #00000000,
                           --}}}
                           --{{{  others      127 - 159
                           #33CC33CC, #33CC33CC, #00000000, #00000000,
                           #F0F0F0F0, #00000000, #0F0F0F0F, #00000000,
                           #FFFFFFFF, #00000000, #00000000, #F0F0F0F0,
                           #F0F0F0F0, #F0F0F0F0, #0F0F0F0F, #F0F0F0F0,
                           #FFFFFFFF, #F0F0F0F0, #00000000, #0F0F0F0F,
                           #F0F0F0F0, #0F0F0F0F, #0F0F0F0F, #0F0F0F0F,
                           #FFFFFFFF, #0F0F0F0F, #00000000, #FFFFFFFF,
                           #F0F0F0F0, #FFFFFFFF, #0F0F0F0F, #FFFFFFFF,
                           #FFFFFFFF, #FFFFFFFF, #18000000, #00000018,
                           #18181818, #00000018, #3F000000, #0000003F,
                           #1818181F, #0000000F, #18000000, #18181818,
                           #18181818, #18181818, #0F000000, #1818181F,
                           #1818181F, #1818181F, #FC000000, #000000FC,
                           #F8181818, #000000F0, #FF000000, #000000FF,
                           #FF181818, #000000FF, #F0000000, #181818F8,
                           #F8181818, #F11818F8, #FF000000, #181818FF,
                           #FF181818, #181818FF,
                           --}}}
                           --{{{  7 miscellaneous
                           #FF99FF7E, #7EFFC3BD,
                           #FF99FF7E, #7EFFBDC3,
                           #FE38387C, #3810FEFE,
                           #FE7C3810, #0010387C,
                           #FEFEFE6C, #0010387C,
                           #FE7C3810, #003810FE,
                           #FFE16000, #0033333F,
                           --}}}
                           #00000000, #00000000 ] :
--}}}

--{{{  VALs
-- Maxima and minima

VAL maxLineStyle IS 128 :
VAL maxPelSize   IS 32 :
VAL maxFontSize  IS 64 :
VAL maxFillSize  IS 32 :

VAL maxErrString IS 80 :  -- Maximum size of an error string

VAL maxPalette   IS 256 : -- Palette contains 256 colour values

-- Fixed by the RPC packet size

VAL maxPoints       IS 256 :  -- Max number of points
VAL maxString       IS 2048 : -- Max chars in a string
VAL maxSpacedString IS 512 :  -- Max chars in a spaced string

-- Blitting

VAL MOVE2DALL     IS 0 :
VAL MOVE2DZERO    IS 1 :
VAL MOVE2DNONZERO IS 2 :

-- Plot modes

VAL PM.COL         IS 0 :
VAL PM.LINESTYLE   IS 1 :
VAL PM.LINESTYLETR IS 4 :
VAL PM.PEL         IS 2 :
VAL PM.LS.PEL      IS 3 :

-- Fill modes

VAL FM.COL     IS 0 :
VAL FM.PATTERN IS 1 :

-- Arc close modes

VAL CM.SEGMENT IS 0 :
VAL CM.CHORD   IS 1 :
VAL CM.OPEN    IS 2 :

-- Replace modes

VAL RM.ALL  IS MOVE2DALL :
VAL RM.COL  IS RM.ALL :
VAL RM.Z    IS MOVE2DZERO :
VAL RM.NZ   IS MOVE2DNONZERO :
VAL RM.AND  IS (RM.ALL+3) :
VAL RM.OR   IS (RM.AND+1) :
VAL RM.XOR  IS (RM.OR+1) :
VAL RM.NOR  IS (RM.XOR+1) :
VAL RM.NAND IS (RM.NOR+1) :

VAL RM.TRANOP     IS (RM.AND-1) :
VAL RM.BOOLOP     IS (RM.AND) :
VAL RM.LASTBOOLOP IS (RM.NAND) :

-- Search modes

VAL S.RIGHT    IS 0 :
VAL S.LEFT     IS 1 :
VAL S.WHILEGOT IS 2 :
VAL S.WHILENOT IS 3 :

-- Text and flip modes

VAL TX.NORM     IS 0 : -- 0
VAL TX.90       IS 1 : -- 90      
VAL TX.180      IS 2 : -- 180     
VAL TX.270      IS 3 : -- 270     
VAL TX.NORMFLIP IS 4 : -- 0 flip  
VAL TX.90FLIP   IS 5 : -- 90 flip 
VAL TX.180FLIP  IS 6 : -- 180 flip
VAL TX.270FLIP  IS 7 : -- 270 filp

-- Errors

VAL E.OK            IS 0 :
VAL E.BADPELMODE    IS 1 :
VAL E.BADREPMODE    IS 2 :
VAL E.BADFILLMODE   IS 3 :
VAL E.BADSEARCHDIRN IS 4 :
VAL E.BADSEARCHTEST IS 5 :
VAL E.BADSTACKMODE  IS 6 :
VAL E.BADFORIMODE   IS 7 :
--}}}

--{{{  Typedef
-- A screen. This is usually a description of a frame store sized
-- raster, but is generalised to allow scratch pad screens, which are
-- not displayed, to be used as the source or destination of image
-- copy / transformation operations.

VAL SCREEN.RASTER    IS 0 :
VAL SCREEN.XSIZE     IS 1 :
VAL SCREEN.YSIZE     IS 2 :
VAL SCREEN.STRIDE    IS 3 :
VAL SCREEN.MULTIMODE IS 4 :

VAL SCREEN.SIZE      IS 5 :

-- VTG parameters. These are independent of the CVC being used, ie:
-- they support the IMS-G300B and IMS-G332. The `display' and `v_display'
-- parameters define the size of the displayed frame.

VAL VTG.PLL            IS 0 :  -- Pixel clock PLL factor

VAL VTG.LINE.TIME      IS 1 :  -- Line timing parameters
VAL VTG.HALF.SYNC      IS 2 :
VAL VTG.BACK.PORCH     IS 3 :
VAL VTG.DISPLAY        IS 4 :
VAL VTG.SHORT.DISPLAY  IS 5 :

VAL VTG.V.DISPLAY      IS 6 :  -- Frame timing parameters
VAL VTG.V.BLANK        IS 7 :       
VAL VTG.V.SYNC         IS 8 :
VAL VTG.V.PREEQUALISE  IS 9 :
VAL VTG.V.POSTEQUALISE IS 10 :
VAL VTG.BROAD.PULSE    IS 11 :

VAL VTG.MEM.INIT       IS 12 :	-- Frame store management
VAL VTG.TRANSFER.DELAY IS 13 :
VAL VTG.MASK.REGISTER  IS 14 :

VAL VTG.CONTROL        IS 15 :  -- CVC control register

VAL VTG.SIZE           IS 16 :
--}}}

--{{{  Channel PROTOCOL
PROTOCOL CGI IS ANY :
--}}}

--{{{  CgiServer
-- The CGI display server is a C process. The gsb should be
-- setup to point to a static area, heap space is also required.
-- p is a C process descriptor, this should be set to 0. The
-- in and out channels are used to communicate with the server.
-- Fonts are stored in heap space, make this large if you intend
-- to load complex fonts.

#PRAGMA EXTERNAL "PROC CgiServer(VAL INT gsb, p, *
                       * CHAN OF CGI in, out) = 16384"
--}}}
