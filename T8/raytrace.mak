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


##### IMAKEF CUT #####

raytrace.btl : raytrace.cfb 
	$(COLLECT) raytrace.cfb /o raytrace.btl $(COLLECTOPT)

raytrace.cfb : raytrace.pgm framebuf.c8h cntlsys.c8h raytrace.c8h 
	$(OCONFIG) raytrace.pgm /o raytrace.cfb $(OCONFOPT)

framebuf.c8h : framebuf.l8h framebuf.t8h 
	$(LINK) /f framebuf.l8h /t8 /h /o framebuf.c8h $(LINKOPT)

framebuf.t8h : framebuf.occ
	$(OCCAM) framebuf /t8 /h /o framebuf.t8h $(OCCOPT)

cntlsys.c8h : cntlsys.l8h cntlsys.t8h 
	$(LINK) /f cntlsys.l8h /t8 /h /o cntlsys.c8h $(LINKOPT)

cntlsys.t8h : cntlsys.occ
	$(OCCAM) cntlsys /t8 /h /o cntlsys.t8h $(OCCOPT)

raytrace.c8h : raytrace.l8h raytrace.t8h 
	$(LINK) /f raytrace.l8h /t8 /h /o raytrace.c8h $(LINKOPT)

raytrace.t8h : raytrace.occ
	$(OCCAM) raytrace /t8 /h /o raytrace.t8h $(OCCOPT)

