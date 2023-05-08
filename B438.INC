-- See Inmos TN66. Occam addresses are not Hardware addresses. Oh no, that would be 
-- way too simple, wouldn't it. Oh no, we're Inmos and we know better. #FFS
PORT OF INT32 boardRegBase :
VAL boardRegBaseHardware IS #200000 :
PLACE boardRegBase AT ((boardRegBaseHardware >> 2) - (#80000000 >> 2)) /\ #3FFFFFFF :

PROC resetB438()
  SEQ
    boardRegBase ! 0(INT32)
    boardRegBase ! #1(INT32)
    boardRegBase ! 0(INT32)
:

[4096]PORT OF INT32 regs :
VAL regsHardware IS 0 :
PLACE regs AT ((regsHardware >> 2) - (#80000000 >> 2)) /\ #3FFFFFFF :
PROC IMS.332.WriteRegister(VAL INT regno, VAL INT32 val)
  SEQ
    regs[regno] ! val
:

VAL INT32 mon.frequency IS 25(INT32) :
VAL INT32 mon.lineTime IS 202(INT32) :
VAL INT32 mon.halfSync IS 8(INT32) :
VAL INT32 mon.backPorch IS 20(INT32) :
VAL INT32 mon.display IS 160(INT32) :
VAL INT32 mon.shortDisplay IS 61(INT32) :
VAL INT32 mon.vDisplay IS 960(INT32) :
VAL INT32 mon.vBlank IS 80(INT32) :
VAL INT32 mon.vSync IS 4(INT32) :
VAL INT32 mon.vPreEqualize IS 4(INT32) :
VAL INT32 mon.vPostEqualize IS 4(INT32) :
VAL INT32 mon.broadPulse IS 75(INT32) :
VAL INT32 mon.memInit IS 128(INT32) :
VAL INT32 mon.xferDelay IS 1(INT32) :
VAL INT32 mon.lineStart IS 0(INT32) :

VAL IMS.332.REGBOOT	IS #000 :
VAL	IMS.332.REGHALFSYNCH IS #021 :
VAL	IMS.332.REGBACKPORCH IS #022 :
VAL	IMS.332.REGDISPLAY IS #023 :
VAL	IMS.332.REGSHORTDIS IS	#024 :
VAL	IMS.332.REGBROADPULSE IS	#025 :
VAL	IMS.332.REGVSYNC	IS #026 :
VAL	IMS.332.REGVPREEQUALIZE	IS #027 :
VAL	IMS.332.REGVPOSTEQUALIZE IS #028 :
VAL	IMS.332.REGVBLANK IS #029 :
VAL	IMS.332.REGVDISPLAY IS	#02A :
VAL	IMS.332.REGLINETIME IS #02B :
VAL	IMS.332.REGLINESTART	IS #02C :
VAL	IMS.332.REGMEMINIT	IS #02D :
VAL	IMS.332.REGXFERDELAY	IS #02E :
VAL IMS.332.REGCOLORMASK IS #040 :
VAL IMS.332.REGCSRA	IS #060 :
VAL IMS.332.REGCSRB	IS #070 :
VAL IMS.332.REGLUTBASE IS #100 : --color palette
VAL IMS.332.REGLUTEND IS #1FF :

VAL INT32 IMS.332.CSRA.VTGENABLE		IS #000001(INT32) :	-- vertical timing generator
VAL INT32 IMS.332.CSRA.INTERLACED		IS #000002(INT32) :	-- screen format
VAL INT32 IMS.332.CSRA.CCIR		IS #000004(INT32) :	--default is EIA
VAL INT32 IMS.332.CSRA.SLAVESYNC		IS #000008(INT32) :	-- else from our pll
VAL INT32 IMS.332.CSRA.PLAINSYNC		IS #000010(INT32) :	-- else tesselated
VAL INT32 IMS.332.CSRA.SEPARATESYNC	IS #000020(INT32) :	-- else composite
VAL INT32 IMS.332.CSRA.VIDEOONLY		IS #000040(INT32) :	-- else video+sync
VAL INT32 IMS.332.CSRA.BLANKPEDESTAL	IS #000080(INT32) :	-- blank level
VAL INT32 IMS.332.CSRA.CBLANKISOUT	IS #000100(INT32) :
VAL INT32 IMS.332.CSRA.CBLANKNODELAY	IS #000200(INT32) :
VAL INT32 IMS.332.CSRA.FORCEBLANK	IS #000400(INT32) :
VAL INT32 IMS.332.CSRA.BLANKDISABLE	IS #000800(INT32) :
VAL INT32 IMS.332.CSRA.VRAMINCREMENT	IS #003000(INT32) :
VAL INT32 IMS.332.VRAMINC1	IS #000000(INT32) :
VAL INT32 IMS.332.VRAMINC256	IS #001000(INT32) :	-- except interlaced->2
VAL INT32 IMS.332.VRAMINC512	IS #002000(INT32) :
VAL INT32 IMS.332.VRAMINC1024	IS #003000(INT32) :
VAL INT32 IMS.332.CSRA.DMADISABLE	IS #004000(INT32) :
VAL INT32 IMS.332.CSRA.SYNCDELAYMASK	IS #038000(INT32) :	-- 0-7 VTG clk delays
VAL INT32 IMS.332.CSRA.PIXELINTERLEAVE	IS #040000(INT32) : -- bit 18
VAL INT32 IMS.332.CSRA.DELAYEDSAMPLING	IS #080000(INT32) :
VAL INT32 IMS.332.CSRA.BITSPERPIXEL	IS #700000(INT32) :
VAL INT32 IMS.332.CSRA.DISABLECURSOR	IS #800000(INT32) :

VAL INT32 IMS.335.BPP24		IS #600000(INT32) : -- bits 22,21

VAL	INT32 IMS.332.BOOTPLL IS #00001F(INT32) :	-- xPLL, binary
VAL	INT32 IMS.332.BOOTCLOCKPLL IS #000020(INT32) :	-- else xternal
VAL	INT32 IMS.332.BOOT64BITMODE IS #000040(INT32) :	-- else 32

PROC IMS.332.Init()
  -- PLL multipler in bits 0..4 (values from 5 to 31 allowed)
  -- B438 TRAM derives clock from TRAM clock (5MHz)
  -- SU are *2 for 24bpp mode
  INT32 clock :
  INT32 pllMultiplier :
  INT32 CSRA :
  SEQ
    clock := 5(INT32) --5MHz from TRAM
    pllMultiplier := mon.frequency/clock 
    pllMultiplier := pllMultiplier * 2(INT32) -- 24bpp interleaved mode -> clock=2*dot rate
    IMS.332.WriteRegister (IMS.332.REGBOOT, pllMultiplier BITOR IMS.332.BOOTCLOCKPLL)
    IMS.332.WriteRegister (IMS.332.REGCSRA, 0(INT32))
    IMS.332.WriteRegister (IMS.332.REGCSRB, #B(INT32)) -- 1011 Split SAM, Sync on green, External pixel sampling
    IMS.332.WriteRegister (IMS.332.REGLINETIME,	    mon.lineTime*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGHALFSYNCH,     mon.halfSync*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGBACKPORCH,     mon.backPorch*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGDISPLAY,        mon.display*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGSHORTDIS,	    mon.shortDisplay*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGVDISPLAY,      mon.vDisplay)
    IMS.332.WriteRegister (IMS.332.REGVBLANK,	    mon.vBlank)
    IMS.332.WriteRegister (IMS.332.REGVSYNC,		    mon.vSync)
    IMS.332.WriteRegister (IMS.332.REGVPREEQUALIZE, mon.vPreEqualize)
    IMS.332.WriteRegister (IMS.332.REGVPOSTEQUALIZE,mon.vPostEqualize)
    IMS.332.WriteRegister (IMS.332.REGBROADPULSE,	mon.broadPulse*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGMEMINIT, 	    mon.memInit*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGXFERDELAY,	    mon.xferDelay*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGLINESTART,	    mon.lineStart*2(INT32))
    IMS.332.WriteRegister (IMS.332.REGCOLORMASK, #FFFFFFFF(INT32))
    CSRA := 0(INT32)
    CSRA := CSRA BITOR IMS.332.CSRA.DISABLECURSOR
    CSRA := CSRA BITOR IMS.335.BPP24
    CSRA := CSRA BITOR IMS.332.CSRA.PIXELINTERLEAVE
    CSRA := CSRA BITOR IMS.332.VRAMINC1024
    CSRA := CSRA BITOR IMS.332.CSRA.PLAINSYNC
    CSRA := CSRA BITOR IMS.332.CSRA.VTGENABLE
    CSRA := CSRA BITOR IMS.332.CSRA.SEPARATESYNC
    CSRA := CSRA BITOR IMS.332.CSRA.VIDEOONLY
    IMS.332.WriteRegister(IMS.332.REGCSRA, CSRA)
:

[524288]INT32 VRAM :  -- 4*512K=2MB
VAL VRAMHardware IS #80400000 :
PLACE VRAM AT ((VRAMHardware >> 2) - (#80000000 >> 2)) /\ #3FFFFFFF :


PROC pokeWords (VAL INT addr, VAL INT count, VAL INT32 val)
  INT a :
  SEQ
    a := addr
    SEQ c = 0 FOR count
      SEQ
        VRAM[a] := val
        a := a + 1
:

-- Thanks again, Inmos. Somewhere deep in the data sheet is a one liner about the palette being used for
-- gamma correction in true colour modes. #FFS
--some sort of gamma correction
PROC bt709Gamma ()
  INT32 entry, corrected :
  REAL32 g,i :
  SEQ
    SEQ c = IMS.332.REGLUTBASE FOR 256
      SEQ
        i := REAL32 ROUND (c-IMS.332.REGLUTBASE)
        g := POWER(i/255.0(REAL32), 2.2(REAL32))
        corrected := INT32 ROUND (255.0(REAL32) * g)
        --so.write.string (fs,ts, "gamma uncorrected=")
        --so.write.real32 (fs,ts, i, 3, 1)
        --so.write.string (fs,ts, " corrected=")
        --so.write.int32 (fs,ts, corrected, 2)
        --so.write.string.nl (fs,ts, "")
        entry := corrected
        entry := entry << 8
        entry := entry BITOR corrected
        entry := entry << 8
        entry := entry BITOR corrected
        IMS.332.WriteRegister (c, entry)
:
      
PROC setupGfx()
  SEQ
    resetB438()
    IMS.332.Init()
    --nilGamma()
    bt709Gamma()
    pokeWords(0000, 640*480, #00000000(INT32)) -- black
    pokeWords(640*10, 640*10, #0000FF00(INT32)) -- green
    pokeWords(640*20, 640*10, #000000FF(INT32)) -- blue
:

