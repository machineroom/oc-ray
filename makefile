OCCAM=oc
OCCOPT=/Y

LINK=ilink
LINKOPT=/Y /I

D7305A=$(HOME)/D7305A/install/D7305A

#note that D7205A toolset runs much of toolchain on a transputer.... I dont have a DOS PC with B008 so this won't work!
#D7305A is almost all PC hosted but objects to the Occam code.
#/A cmd line switch disables the offending checks (I assume this enables "D7205 mode")
DB=dosbox\
	-c "mount D $(shell pwd)"\
	-c "mount E $(D7305A)"\
	-c "PATH=Z:;e:\tools"\
	-c "SET ISEARCH=e:\libs\\"\
	-c "D:"

#workers are all T425
CPU=/T425

all: RAYTRACE.LKU

debug: 
	$(DB)
	
clean:
	-rm *.T4H
	-rm *.OUT
	-rm *.LKU

RAYTRACE.LKU : FRAMEBUF.T4H CNTLSYS.T4H RAYTRACE.T4H
	$(DB) -c "$(LINK) /f RAYTRACE.L4H $(CPU) /h /o RAYTRACE.LKU $(LINKOPT) > 2.out" -c "exit"
	-grep --color "Warning\|Error\|Serious" 2.OUT
	$(DB) -c "ilist /A /T /C /M /W /I /X RAYTRACE.LKU > raytrace.lst" -c "exit"

FRAMEBUF.T4H : FRAMEBUF.OCC PROTOCOL.INC B438.INC
	$(DB) -c "$(OCCAM) FRAMEBUF $(CPU) /h /o FRAMEBUF.T4H $(OCCOPT) > 4.out" -c "exit"
	-grep --color "Warning\|Error\|Serious" 4.OUT

CNTLSYS.T4H : CNTLSYS.OCC PROTOCOL.INC WORLD.INC
	$(DB) -c "$(OCCAM) CNTLSYS /A $(CPU) /h /o CNTLSYS.T4H $(OCCOPT) > 6.out" -c "exit"
	-grep --color "Warning\|Error\|Serious" 6.OUT

RAYTRACE.T4H : RAYTRACE.OCC PROTOCOL.INC RENDERER.INC
	$(DB) -c "$(OCCAM) RAYTRACE /A $(CPU) /h /o RAYTRACE.T4H $(OCCOPT) > 8.out" -c "exit"
	-grep --color "Warning\|Error\|Serious" 8.OUT

