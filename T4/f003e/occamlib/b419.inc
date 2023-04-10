--{{{  Header
--
-- Copyright INMOS Limited 1992
--
-- **************************************************************************
--
-- Group:	Iq Software
--
-- Product:	IMS-F003
--
-- File:	b419.inc
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
--
--}}}

--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 105 Mhz
-- Display resolution  : 1280 by 1024
-- Suitable monitor    : Hitachi
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.1280.1024.HITACHI IS
                  [ #15,      -- pll
                    422,      -- line.time
                    #15,      -- half.sync
                    #36,      -- back.porch
                    320,      -- display
                    109,      -- short.display
                    2048,     -- v.display
                    56,       -- v.blank
                    6,        -- v.sync
                    8,        -- v.preequalise
                    8,        -- v.postequalise
                    205,      -- broad.pulse
                    489,      -- mem.init
                    #17,      -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control

--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 65 Mhz
-- Display resolution  : 1024 by 768
-- Suitable monitor    : NEC Multisync XL
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.1024.768.NEC.XL IS
                  [ #D,       -- pll
                    #14A,     -- line.time
                    #8,       -- half.sync
                    #2E,      -- back.porch
                    #100,     -- display
                    #5B,      -- short.display
                    1536,     -- v.display
                    #38,      -- v.blank
                    8,        -- v.sync
                    8,        -- v.preequalise
                    8,        -- v.postequalise
                    #99,      -- broad.pulse
                    #1EB,     -- mem.init
                    #15,      -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control


--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 25 Mhz
-- Display resolution  : 640 by 480
-- Suitable monitor    : IBM VGA 8513002 and 8512002
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.640.480.IBM.VGA IS
                  [ #5,       -- pll
                    202,      -- line.time
                    8,        -- half.sync
                    20,       -- back.porch
                    160,      -- display
                    61,       -- short.display
                    960,      -- v.display
                    80,       -- v.blank
                    4,        -- v.sync
                    4,        -- v.preequalise
                    4,        -- v.postequalise
                    75,       -- broad.pulse
                    494,      -- mem.init
                    18,       -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control

--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 35 Mhz
-- Display resolution  : 800 by 600
-- Suitable monitor    : NEC Multisync II or III
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.800.600.NEC.II IS
                  [ #7,       -- pll
                    250,      -- line.time
                    7,        -- half.sync
                    30,       -- back.porch
                    200,      -- display
                    75,       -- short.display
                    1200,     -- v.display
                    80,       -- v.blank
                    8,        -- v.sync
                    8,        -- v.preequalise
                    8,        -- v.postequalise
                    117,      -- broad.pulse
                    497,      -- mem.init
                    15,       -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control
          
--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 65 Mhz
-- Display resolution  : 1024 by 768
-- Suitable monitor    : NEC Multisync XL or 5D
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.1024.768.NEC.5D IS
                  [ #D,       -- pll
                    332,      -- line.time
                    8,        -- half.sync
                    49,       -- back.porch
                    256,      -- display
                    90,       -- short.display
                    1536,     -- v.display
                    44,       -- v.blank
                    8,        -- v.sync
                    4,        -- v.preequalise
                    4,        -- v.postequalise
                    150,      -- broad.pulse
                    486,      -- mem.init
                    26,       -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control
          
--------------------------------------------------------------
-- Video timing parameters
--
-- Pixel rate          : 25 Mhz
-- Display resolution  : 640 by 480
-- Suitable monitor    : TANDON TC0512 and TC0513
--
--------------------------------------------------------------

VAL [VTG.SIZE]INT V.640.480.TC051X IS
                  [ #5,       -- pll
                    196,      -- line.time
                    3,        -- half.sync
                    19,       -- back.porch
                    160,      -- display
                    62,       -- short.display
                    960,      -- v.display
                    28,       -- v.blank
                    8,        -- v.sync
                    4,        -- v.preequalise
                    4,        -- v.postequalise
                    87,       -- broad.pulse
                    494,      -- mem.init
                    18,       -- transfer.delay
                    #FFFFFF,  -- mask.register
                    0 ] :     -- control
          
-- Default 1024 by 768

VAL [VTG.SIZE]INT V.1024.768 IS V.1024.768.NEC.XL :
