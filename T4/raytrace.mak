OCCAM=oc
LINK=ilink
OCONFIG=occonf
COLLECT=icollect
OCCOPT=/Y
LINKOPT=/Y /I
OCONFOPT=/NV /Y /I
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
FBCPU=/T8
#CPU=/T8
##### IMAKEF CUT #####

debug: 
	$(DB)
	
clean:
	-rm *.C?H
	-rm *.T?H
	-rm *.CFB
	-rm *.CLU
	-rm *.BTL
	-rm *.OUT

RAYTRACE.BTL : RAYTRACE.CFB 
	$(DB) -c "$(COLLECT) RAYTRACE.CFB /o RAYTRACE.BTL $(COLLECTOPT) > 1.out" -c "exit"
	-grep --color "Warning\|Error" 1.OUT

RAYTRACE.CFB : RAYTRACE.PGM FRAMEBUF.C4H CNTLSYS.C4H RAYTRACE.C4H network.inc
	$(DB) -c "$(OCONFIG) RAYTRACE.PGM /o RAYTRACE.CFB $(OCONFOPT) > 2.out" -c "exit"
	-grep --color "Warning\|Error" 2.OUT

FRAMEBUF.C4H : FRAMEBUF.L4H FRAMEBUF.T4H 
	$(DB) -c "$(LINK) /f FRAMEBUF.L4H $(FBCPU) /h /o FRAMEBUF.C4H $(LINKOPT) > 3.out" -c "exit"
	-grep --color "Warning\|Error" 3.OUT

FRAMEBUF.T4H : FRAMEBUF.OCC
	$(DB) -c "$(OCCAM) FRAMEBUF $(FBCPU) /h /o FRAMEBUF.T4H $(OCCOPT) > 4.out" -c "exit"
	-grep --color "Warning\|Error" 4.OUT

CNTLSYS.C4H : CNTLSYS.L4H CNTLSYS.T4H 
	$(DB) -c "$(LINK) /f CNTLSYS.L4H $(CPU) /h /o CNTLSYS.C4H $(LINKOPT) > 5.out" -c "exit"
	-grep --color "Warning\|Error" 5.OUT

CNTLSYS.T4H : CNTLSYS.OCC
	$(DB) -c "$(OCCAM) CNTLSYS /A $(CPU) /h /o CNTLSYS.T4H $(OCCOPT) > 6.out" -c "exit"
	-grep --color "Warning\|Error" 6.OUT

RAYTRACE.C4H : RAYTRACE.L4H RAYTRACE.T4H 
	$(DB) -c "$(LINK) /f RAYTRACE.L4H $(CPU) /h /o RAYTRACE.C4H $(LINKOPT) > 7.out" -c "exit"
	-grep --color "Warning\|Error" 7.OUT

RAYTRACE.T4H : RAYTRACE.OCC
	$(DB) -c "$(OCCAM) RAYTRACE /A $(CPU) /h /o RAYTRACE.T4H $(OCCOPT) > 8.out" -c "exit"
	-grep --color "Warning\|Error" 8.OUT

