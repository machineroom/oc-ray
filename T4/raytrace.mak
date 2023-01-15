# OC options
# A     disable alias checking            B     display brief error messages
# C     check only                        CODE  set code buffer size (in Kbytes)
# D     minimum debugging data            E     disable compiler libraries
# G     sequential code insertion         H     halt error mode (default)
# I     output information                K     disable range checking
# N     disable usage checking            NA    disable run-time ASSERT checks
# NWCA  no warnings on CHAN OF ANY        NWGY  no warnings on GUY construct
# NWP   no unused parameter warnings      NWU   no unused name warnings
# O     specify output file               P     specify map file name
# R     redirect screen output to file    S     stop error mode
# TA    target to TA processor class      TB    target to TB processor class
# U     disable run-time error checking   V     disable separate vector space
# W     full code insertion               WALL  enable all warnings
# WD    provide descoped name warnings    WQUAL enable software quality warnings
# WO    provide overlap check warnings    X     universal error mode
# Y     disable interactive debugging    

#ilink Options:
# EX       extract modules only          F        specify indirect file        
# H        halt mode (default)           I        print information            
# KB       specify Kb for code           LB       lff iboot/iconf output       
# LC       lff iconf output              M212     M212 compatibility           
# ME       specify main entry symbol     MO       specify module file          
# O        specify output file           S        stop mode                    
# T        tcoff output (default)        T2       T212 compatibility           
# T3       T225 compatibility            T4       T414 compatibility (default) 
# T5       T400, T425, T426 compat.      T8       T800 compatibility           
# T9       T805 compatibility            TA       Any 32-bit transputer        
# TB       Any 32-bit proc. without fpu  U        allow undefined symbols      
# X        universal mode                Y        disable interactive debugging

#icollect options
# B   Specify user bootstrap file BM  Use bottom of memory loader
# C   Specify debug file          CM  Do clear memory
# D   Disable debug info          E   Flip halt on error mode
# I   Verbose                     K   Produce non bootable file
# M   Specify memory size         O   Specify output file
# P   Specify memory map file     RA  Rom run in ram
# RO  Rom run in rom              RS  Specify rom size
# S   Specify stack size (words)  T   Iboot mode
# Y   Disable debugging

#occonf Options:
# B     display brief error messages      C     check only
# CODE  set code buffer size (in Kbytes)  G     sequential code insertion
# GA    advanced debugger                 H     halt error mode (default)
# I     output information                K     disable range checking
# NA    disable run-time ASSERT checks    NV    disable software virtual routing
# NWCA  no warnings on CHAN OF ANY        NWGY  no warnings on GUY construct
# NWP   no unused parameter warnings      NWU   no unused name warnings
# O     specify output file               PRE   execution profiler
# PRU   utilisation profiler              R     redirect screen output to file
# RA    configure for ROM running in RAM  RE    enable memory layout reordering
# RO    configure for ROM running in ROM  S     stop error mode
# U     disable run-time error checking   V     disable separate vector space
# W     full code insertion               WALL  enable all warnings
# WD    provide descoped name warnings    WQUAL enable software quality warnings
# WO    provide overlap check warnings    X     universal error mode
# Y     disable interactive debugging    

LIBRARIAN=ilibr
OCCAM=oc
LINK=ilink
CONFIG=icconf
OCONFIG=occonf
COLLECT=icollect

ERROR_MODE=/X
OCCOPT=/WALL $(ERROR_MODE) /W
LINKOPT=$(ERROR_MODE)
OCONFOPT=/WALL $(ERROR_MODE)
COLLECTOPT=

D7305A=$(HOME)/d7305a/install/D7305A

#note that D7205A toolset runs much of toolchain on a transputer.... I dont have a DOS PC with B008 so this won't work!
#D7305A is almost all PC hosted but objects to the Occam code. /A cmd line switch disables the offending checks (I assume this enables "D7205 mode")
DB=dosbox\
	-c "mount D $(shell pwd)"\
	-c "mount E $(D7305A)"\
	-c "PATH=Z:;e:\tools"\
	-c "SET ISEARCH=e:\libs\\"\
	-c "D:"

CPU=/T425
#CPU=/T8
##### IMAKEF CUT #####

DEBUG: 
	$(DB)

CLEAN: 
	-rm ?.OUT
	-rm *.C4H
	-rm *.T4H
	-rm *.CFB
	-rm *.CLU
	-rm *.BTL


RAYTRACE.BTL : RAYTRACE.CFB raytrace.mak
	$(DB) -c "$(COLLECT) RAYTRACE.CFB /o RAYTRACE.BTL $(COLLECTOPT) > 1.out" -c "exit"
	cat 1.OUT

RAYTRACE.CFB : RAYTRACE.PGM FRAMEBUF.C4H CNTLSYS.C4H RAYTRACE.C4H network.inc raytrace.mak
	$(DB) -c "$(OCONFIG) RAYTRACE.PGM /o RAYTRACE.CFB $(OCONFOPT) > 2.out" -c "exit"
	cat 2.OUT

FRAMEBUF.C4H : FRAMEBUF.L4H FRAMEBUF.T4H raytrace.mak
	$(DB) -c "$(LINK) /f FRAMEBUF.L4H $(CPU) /o FRAMEBUF.C4H $(LINKOPT) > 3.out" -c "exit"
	cat 3.OUT

FRAMEBUF.T4H : FRAMEBUF.OCC raytrace.mak
	$(DB) -c "$(OCCAM) FRAMEBUF $(CPU) /o FRAMEBUF.T4H $(OCCOPT) > 4.out" -c "exit"
	cat 4.OUT

CNTLSYS.C4H : CNTLSYS.L4H CNTLSYS.T4H raytrace.mak
	$(DB) -c "$(LINK) /f CNTLSYS.L4H $(CPU) /o CNTLSYS.C4H $(LINKOPT) > 5.out" -c "exit"
	cat 5.OUT

CNTLSYS.T4H : CNTLSYS.OCC raytrace.mak
	$(DB) -c "$(OCCAM) CNTLSYS /A $(CPU) /o CNTLSYS.T4H $(OCCOPT) > 6.out" -c "exit"
	cat 6.OUT

RAYTRACE.C4H : RAYTRACE.L4H RAYTRACE.T4H raytrace.mak
	$(DB) -c "$(LINK) /f RAYTRACE.L4H $(CPU) /o RAYTRACE.C4H $(LINKOPT) > 7.out" -c "exit"
	cat 7.OUT

RAYTRACE.T4H : RAYTRACE.OCC raytrace.mak
	$(DB) -c "$(OCCAM) RAYTRACE /A $(CPU) /o RAYTRACE.T4H $(OCCOPT) > 8.out" -c "exit"
	cat 8.OUT

