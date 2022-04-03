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

##### IMAKEF CUT #####

RAYTRACE.BTL : RAYTRACE.CFB 
	$(DB) -c "$(COLLECT) RAYTRACE.CFB /o RAYTRACE.BTL $(COLLECTOPT) > 1.out" -c "exit"
	cat 1.OUT

RAYTRACE.CFB : RAYTRACE.PGM FRAMEBUF.C8H CNTLSYS.C8H RAYTRACE.C8H 
	$(DB) -c "$(OCONFIG) RAYTRACE.PGM /o RAYTRACE.CFB $(OCONFOPT) > 2.out" -c "exit"
	cat 2.OUT

FRAMEBUF.C8H : FRAMEBUF.L8H FRAMEBUF.T8H 
	$(DB) -c "$(LINK) /f FRAMEBUF.L8H /t8 /h /o FRAMEBUF.C8H $(LINKOPT) > 3.out" -c "exit"
	cat 3.OUT

FRAMEBUF.T8H : FRAMEBUF.OCC
	$(DB) -c "$(OCCAM) FRAMEBUF /t8 /h /o FRAMEBUF.T8H $(OCCOPT) > 4.out" -c "exit"
	cat 4.OUT

CNTLSYS.C8H : CNTLSYS.L8H CNTLSYS.T8H 
	$(DB) -c "$(LINK) /f CNTLSYS.L8H /t8 /h /o CNTLSYS.C8H $(LINKOPT) > 5.out" -c "exit"
	cat 5.OUT

CNTLSYS.T8H : CNTLSYS.OCC
	$(DB) -c "$(OCCAM) CNTLSYS /A /t8 /h /o CNTLSYS.T8H $(OCCOPT) > 6.out" -c "exit"
	cat 6.OUT

RAYTRACE.C8H : RAYTRACE.L8H RAYTRACE.T8H 
	$(DB) -c "$(LINK) /f rAYTRACE.L8H /t8 /h /o RAYTRACE.C8H $(LINKOPT) > 7.out" -c "exit"
	cat 7.OUT

RAYTRACE.T8H : RAYTRACE.OCC
	$(DB) -c "$(OCCAM) RAYTRACE /A /t8 /h /o RAYTRACE.T8H $(OCCOPT) > 8.out" -c "exit"
	cat 8.OUT

