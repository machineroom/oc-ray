LIBRARIAN=ilibr
OCCAM=oc
LINK=ilink
CONFIG=icconf
OCONFIG=occonf
COLLECT=icollect
CC=icc
FORTRAN=if77
DELETE=del
LIBOPT=
OCCOPT=
LINKOPT=
CONFOPT=
OCONFOPT=
COLLECTOPT=
COPT=
F77OPT=

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

RAYTRACE.BTL : RAYTRACE.CFB 
	$(DB) -c "$(COLLECT) RAYTRACE.CFB /o RAYTRACE.BTL $(COLLECTOPT) > 1.out" -c "exit"
	cat 1.OUT

RAYTRACE.CFB : RAYTRACE.PGM FRAMEBUF.C4H CNTLSYS.C4H RAYTRACE.C4H network.inc
	$(DB) -c "$(OCONFIG) RAYTRACE.PGM /o RAYTRACE.CFB $(OCONFOPT) > 2.out" -c "exit"
	cat 2.OUT

FRAMEBUF.C4H : FRAMEBUF.L4H FRAMEBUF.T4H 
	$(DB) -c "$(LINK) /f FRAMEBUF.L4H $(CPU) /h /o FRAMEBUF.C4H $(LINKOPT) > 3.out" -c "exit"
	cat 3.OUT

FRAMEBUF.T4H : FRAMEBUF.OCC
	$(DB) -c "$(OCCAM) FRAMEBUF $(CPU) /h /o FRAMEBUF.T4H $(OCCOPT) > 4.out" -c "exit"
	cat 4.OUT

CNTLSYS.C4H : CNTLSYS.L4H CNTLSYS.T4H 
	$(DB) -c "$(LINK) /f CNTLSYS.L4H $(CPU) /h /o CNTLSYS.C4H $(LINKOPT) > 5.out" -c "exit"
	cat 5.OUT

CNTLSYS.T4H : CNTLSYS.OCC
	$(DB) -c "$(OCCAM) CNTLSYS /A $(CPU) /h /o CNTLSYS.T4H $(OCCOPT) > 6.out" -c "exit"
	cat 6.OUT

RAYTRACE.C4H : RAYTRACE.L4H RAYTRACE.T4H 
	$(DB) -c "$(LINK) /f RAYTRACE.L4H $(CPU) /h /o RAYTRACE.C4H $(LINKOPT) > 7.out" -c "exit"
	cat 7.OUT

RAYTRACE.T4H : RAYTRACE.OCC
	$(DB) -c "$(OCCAM) RAYTRACE /A $(CPU) /h /o RAYTRACE.T4H $(OCCOPT) > 8.out" -c "exit"
	cat 8.OUT

