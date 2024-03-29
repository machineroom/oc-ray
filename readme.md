# JamesW updated for 2022
- Code obtained from [Ram's transputer pages](https://www.classiccmp.org/transputer/software/graphics/occam-raytracer.tar.gz) and thanks to Stefan Fennek (https://www.youtube.com/channel/UCauhcBH8yzUS7qwp2pN37tQ, https://github.com/DigiFennek) for pointers in the right direction :)
- Make environment for Linux using dosbox
- Configuration created for [Rpi/C011 interface](https://github.com/machineroom/rpi_c011) and Whitecross WX9020 T425 system. This system has a T425 on the system controller card (512KB), with link 1 to host and 2,3 to the transputer ring (T425, 16MB), all @ 20Mbps
- See also Mike B's mods and results on FPGA hardware (cool!) https://bitbucket.org/transputer/raytracer/src/master/

# 2023 updates
- Use framebuffer on B438 root node by default. Lots of assumptions about framebuf running on T805
- Remove the virtual router and use proper hardware links (massive speedup with many nodes)

## Samples
|   |   |
| - | - |
|10 spheres - scene 1|![](images/10spheres.jpg)|
|14 spheres - scene 2|![](images/14spheres.jpg)|
|Cone, Ellipsoid - scene 3|![](images/scene3.jpg)|

## Performance (all WX9020 unless noted)
All WX9020 results below are with the virtual router enabled (default with D7305a occam tools), since the WX9020 hardware isn't a pipe! The results point at the VR quickly becoming a bottleneck as workers are scaled.
Workers|Type|Scene 1|2|3|4|5|notes|
|--|--|--|--|--|--|--|--|
|1  |T805|736|662|200|145|89|SMT211B TRAM (all procs on single transputer)
|1  |T425|3630||||272|TTM3A TRAM (all procs on single transputer)
|5  |T425|1009||256|||cntlsys and framebuffer on seperate transputers
|11 |T425|532|585|137|88|50|2 cards in system controller rack
|17 |T425|333||137|||
|18 |T425|314|||||
|35 |T425|184|||||
|41 |T425|173|||||
|53 |T425|165|||||
|65 |T425|157|||||
|71 |T425|160|176|95|63|50|
|77 |T425|164|||||
|89 |T425|177|||||
|98 |T425|162|155||||
|108|T425|161|186|87|77|65|
|113|T425|171|192||||
|125|T425|199|181|95|88|77|
|25 |T80x|34|||||Stefan Fennek "TransputerBox" (youtube)
|16 |FPGA|6.5|7.5|2.0|1.5||Acorn CLE-215+ (XC7A200T-3 Artix-7 FPGA) (See Mike B link above)

## Removing virtual router
Results with virtual router disabled, on simple pipe (achievable with a small number of processors). framebuf and cntlsys on root T8. Linear scaling!:
|Workers|Type|Scene 1|notes|
|--|--|--|--|
|3  |T425|1265|fb on T8, cntlsys on worker T4|
|5  |T425|760|fb on T8, cntlsys on worker T4|
|5  |T425|887|3*3 patches|
|6  |T425|636|fb & cntlsys on T8|
|14 |T425|277|fb & cntlsys on T8|
|92 |T425|67|fb & cntlsys on T8 (using ispy_to_long_pipe.py)|
|92 |T425|55|4*4 patches (8*8 causes one worker to hold everything up at end!)|
|92 |T425|52|3*3 patches|
|92 |T425|56|2*2 patches|

## Non-pipe restructure
Results with virtual router disabled, non-pipe branch (map directly to the WX9020 network)
|Workers|Type|Scene 1|notes|
|--|--|--|--|
|8 |T425|559||
|12 |T425|370||
|126 |T425|39||


## Select processor type
Can fairly easily build for either T425 or T805. To switch modify the following (and do a `git clean -df .` because the makefile dependencies aren't right)  

|file|T4|T8|
|----|--|----|
|raytrace.pgm|T425|T805|
|*.l4h|occama|occam8|
|raytrace.mak|CPU=T425|CPU=T8|
|raytrace.occ|occama|occam8|

## Build
Generate the network map for the current system
```
sudo /home/james/INMOS_ispy_c011/ispy > ispy.txt
./ispy_to_network.py --input ispy.txt --b438
```
Make the code
```
make -f raytrace.mak RAYTRACE.BTL
```

## Run (as root with rpi/c011 interface)
```
export PATH=$PATH:/home/james/modern_iserver/build/iserver/iserver
export ICONDB=/home/james/modern_iserver/CONNECT/c011.dat 
iserver -SL c011 -SB RAYTRACE.BTL
```

## MTV file conversion
```
mtvtoppm ray.mtv > ray.ppm
ppmtojpeg ray.ppm > ray.jpg
```

## TODO
- Discover the network (like ispy or T-Mandel does) at run-time rather than having to build for the specific network. The BTL also grows in size as more nodes are added (12 nodes= ~100KB, 120+ nodes= ~0.5MB!)
- Why is is substantially slower with WX HSL cards in word mode (iserver -WM)?! Mandel is slower in this mode too

<br>

# The original Inmos readme
<pre>

Compiling the Raytracer

To compile the raytracer the following files are required.

* cntlsysT8.occ
* raytraceT8.occ
* framebufT8.occ
* raytraceT8.pgm
* raymainT8.occ

The following steps are required for successful compilation.

imakef raytraceT8.btl        --create the make file
make -f raytraceT8.mak       --run the make file
iserver -sb raytraceT8.btl   --run the raytracer

The imakef statement will create a make file called raytraceT8.mak.
Before executing the make file, the following compiler options must be 
included to allow successful compilation. At the line identified as 
OCCONF= the following compiler options must be appended, as they appear below:

OCCONF=-A -U -NWP -NWU

After these options have been added, save the make file and begin the 
compilation by running the make file.


The raytracer produces an output file called "ray.mtv". To do something useful
with this file (like view it) you need to translate it into something viewable.
On a Sun4, the program "/usr/bin/X11/mtvtoppm" creates a ppm-format file. Use
a program such as "xv" to view this.

	eg. mtvtoppm <ray.mtv | xv
</pre>
