
#!/bin/bash
D7305A=$HOME/d7305a/install/D7305A

#note that D7205A toolset runs much of toolchain on a transputer.... I dont have a DOS PC with B008 so this won't work!
#D7305A is almost all PC hosted but objects to the Occam code. /A cmd line switch disables the offending checks (I assume this enables "D7205 mode")

dosbox -c "mount D $(pwd)" -c "mount E ${D7305A}" -c "PATH=Z:;e:\tools" -c "SET ISEARCH=e:\LIBS\\" -c "D:" -c "oc simple /TA > 1.out" -c "exit"
cat 1.OUT
dosbox -c "mount D $(pwd)" -c "mount E ${D7305A}" -c "PATH=Z:;e:\tools" -c "SET ISEARCH=e:\LIBS\\" -c "D:" -c "ilink simple.tco hostio.lib /f occama.lnk /tA > 2.out" -c "exit"
cat 2.OUT
dosbox -c "mount D $(pwd)" -c "mount E ${D7305A}" -c "PATH=Z:;e:\tools" -c "SET ISEARCH=e:\LIBS\\" -c "D:" -c "occonf simple.pgm > 3.out" -c "exit"
cat 3.OUT
dosbox -c "mount D $(pwd)" -c "mount E ${D7305A}" -c "PATH=Z:;e:\tools" -c "SET ISEARCH=e:\LIBS\\" -c "D:" -c "icollect simple.cfb > 4.out" -c "exit"
cat 4.OUT
