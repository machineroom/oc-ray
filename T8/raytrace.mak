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

#	$(shell echo $1 $2)
DB=dosbox\
	-c "mount D $(shell pwd)"\
	-c "mount E $(D7305A)"\
	-c "PATH=Z:;e:\tools"\
	-c "SET ISEARCH=e:\libs\\"\
	-c "D:"

##### IMAKEF CUT #####

raytrace.btl : raytrace.cfb 
	$(DB) -c "$(COLLECT) raytrace.cfb /o raytrace.btl $(COLLECTOPT) > 1.out" -c "exit"
	cat 1.OUT

raytrace.cfb : raytrace.pgm framebuf.c8h cntlsys.c8h raytrace.c8h 
	$(DB) -c "$(OCONFIG) raytrace.pgm /o raytrace.cfb $(OCONFOPT) > 2.out" -c "exit"
	cat 2.OUT

framebuf.c8h : framebuf.l8h framebuf.t8h 
	$(DB) -c "$(LINK) /f framebuf.l8h /t8 /h /o framebuf.c8h $(LINKOPT) > 3.out" -c "exit"
	cat 3.OUT

framebuf.t8h : framebuf.occ
	$(DB) -c "$(OCCAM) framebuf /t8 /h /o framebuf.t8h $(OCCOPT) > 4.out" -c "exit"
	cat 4.OUT

cntlsys.c8h : cntlsys.l8h cntlsys.t8h 
	$(DB) -c "$(LINK) /f cntlsys.l8h /t8 /h /o cntlsys.c8h $(LINKOPT) > 5.out" -c "exit"
	cat 5.OUT

cntlsys.t8h : cntlsys.occ
	$(DB) -c "$(OCCAM) cntlsys /t8 /h /o cntlsys.t8h $(OCCOPT) > 6.out" -c "exit"
	cat 6.OUT

raytrace.c8h : raytrace.l8h raytrace.t8h 
	$(DB) -c "$(LINK) /f raytrace.l8h /t8 /h /o raytrace.c8h $(LINKOPT) > 7.out" -c "exit"
	cat 7.OUT

raytrace.t8h : raytrace.occ
	$(DB) -c "$(OCCAM) raytrace /t8 /h /o raytrace.t8h $(OCCOPT) > 8.out" -c "exit"
	cat 8.OUT

