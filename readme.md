# JamesW notes in 2022:

|   |   |
| - | - |
|14 spheres - scene 2|![](images/14spheres.jpg)|
|10 spheres - scene 1|![](images/10spheres.jpg)|

## Select processor type:
The T4 directory can build or either T425 or T805. To switch modify the following (and do a `git clean -df .`)  

|file|T4|T8|
|----|--|----|
|raytrace.pgm|T425|T805|
|*.l4h|occama|occam8|
|raytrace.mak|CPU=T425|CPU=T8|
|raytrace.occ|occama|occam8|

## Build
```
make -f raytrace.mak RAYTRACE.BTL
```

## Run (as root with rpi/c011 interface)
```
export PATH=$PATH:/home/james/modern_iserver/build/iserver/iserver
export ICONDB=/home/james/modern_iserver/CONNECT/c011.dat 
iserver -SL c011 -SB RAYTRACE.BTL`
```

## MTV file conversion
```
mtvtoppm ray.mtv > ray.ppm
ppmtojpeg ray.ppm > ray.jpg
```

## Single CPU performance:
(@runtime x=[128,376])
|Configuration|1|2|3|4|5|
|--|--|--|--|--|--|
|T425/1MB|>1h|?|?|?|?|
|T805/4MB|736s|662s|200s|145s|89s|

<br>

# OLD stuff...
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