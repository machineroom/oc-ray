VAL m.adaptive   IS 0 :
VAL m.stochastic IS 1 :
VAL m.dumb       IS 2 :
VAL m.test       IS 3 :

VAL n.reflect IS 0 :        -- point to children
VAL n.refract IS 1 :
VAL n.next    IS 2 :        -- maintain linked list of leaf nodes
VAL n.type    IS 3 :        -- reflected, refracted or primary ray

-- Valid ray types for n.type slot

VAL n.t       IS 11 :       -- distance parameter 't' of intersection

VAL n.startx  IS 12 :       -- ray origin
VAL n.starty  IS 13 :
VAL n.startz  IS 14 :

VAL n.dx      IS 15 :       -- ray direction
VAL n.dy      IS 16 :
VAL n.dz      IS 17 :

VAL n.red   IS 18 :
VAL n.green IS 19 :
VAL n.blue  IS 20 :

VAL nodeSize IS n.blue + 1 :

VAL maxDepth IS 6 :
VAL maxNodes IS 4 + (2 << maxDepth) :  -- traverse tree 5 deep max,
                                       -- PLUS 4 for good measure
VAL treeSize  IS nodeSize * maxNodes : -- shadow generation

VAL o.sphere    IS 0 :
VAL o.xyplane   IS 1 :
VAL o.xzplane   IS 2 :
VAL o.yzplane   IS 3 :
VAL o.plane     IS 4 :
VAL o.cone      IS  5 :
VAL o.cylinder  IS  6 :
VAL o.ellipsoid IS  7 :
VAL o.quadric   IS  8 : -- general quadric, hell to compute

VAL x.axis     IS  0 :
VAL y.axis     IS  1 :
VAL z.axis     IS  2 :

-- the attribute word contains gross attributes of the object as
-- bits. The relevant words in the object descriptor expand upon these

VAL a.spec     IS #01 :  -- use lambert / use phong and reflect
VAL a.frac     IS #02 :  -- refract on surface
VAL a.bound0   IS #04 :  -- bounded in 1 dimension
VAL a.bound1   IS #08 :  -- bounded in 2 dimension
VAL a.tex      IS #10 :  -- texture map ?
VAL a.bump     IS #20 :  -- bump map    ?

VAL o.type     IS  0 : -- type field of all objects
VAL o.attr     IS  1 : -- attribute field of all object

VAL o.kdR      IS  2 :  -- coeffs of diffuse reflection R G B
VAL o.kdG      IS  3 :
VAL o.kdB      IS  4 :

VAL o.ks       IS  5 :  -- coeff of specular reflection ( for reflections)

VAL o.kg       IS  6 :  -- coeff of gloss for phong shading
VAL o.xmitR    IS  7 :  -- coeffs of transmission R G B
VAL o.xmitG    IS  8 :
VAL o.xmitB    IS  9 :

VAL o.power    IS 10 :  -- power for phong shading
VAL o.refix    IS 11 :  -- refractive index (relative)

VAL o.specific IS 12 :

VAL first      IS o.specific :

VAL s.rad      IS  first + 0 :
VAL s.x        IS  first + 1 :
VAL s.y        IS  first + 2 :
VAL s.z        IS  first + 3 :

VAL s.map      IS  first + 4 :  -- which map ( texture or bump)
VAL s.uoffs    IS  first + 5 :  -- offsets for u and v in map
VAL s.voffs    IS  first + 6 :
VAL s.size     IS  first + 7 :
VAL first   IS o.specific:
VAL co.x     IS first + 0:       -- center of the circle
VAL co.y     IS first + 1:       --  at the beginnig of the cone
VAL co.z     IS first + 2:
VAL co.a11   IS first + 3:       -- transformation matrix of the cone
VAL co.a12   IS first + 4:       -- from gobal to local coord.
VAL co.a13   IS first + 5:
VAL co.a21   IS first + 6:
VAL co.a22   IS first + 7:
VAL co.a23   IS first + 8:
VAL co.a31   IS first + 9:
VAL co.a32   IS first + 10:
VAL co.a33   IS first + 11:
VAL co.rada  IS first + 12:      -- size of the circle at the beginning
VAL co.radb  IS first + 13:      -- size of the circle at the end
VAL co.len   IS first + 14:      -- length of the cone on new z axis
VAL co.size  IS first + 15:
VAL first   IS o.specific:
VAL e.x     IS first + 0:       -- center of the ellipsoid
VAL e.y     IS first + 1:
VAL e.z     IS first + 2:
VAL e.a11   IS first + 3:       -- transformation matrix of the ellipsoid
VAL e.a12   IS first + 4:       -- from gobal to local coord.
VAL e.a13   IS first + 5:
VAL e.a21   IS first + 6:
VAL e.a22   IS first + 7:
VAL e.a23   IS first + 8:
VAL e.a31   IS first + 9:
VAL e.a32   IS first + 10:
VAL e.a33   IS first + 11:
VAL e.radx  IS first + 12:      -- size on x axis ( of the new system )
VAL e.rady  IS first + 13:      -- size on y axis ( of the new system )
VAL e.radz  IS first + 14:      -- size on z axis ( of the new system )
VAL e.size  IS first + 15:
VAL first   IS o.specific:
VAL c.x     IS first + 0:       -- center of the circle
VAL c.y     IS first + 1:       --  at the beginnig of the cylinder
VAL c.z     IS first + 2:
VAL c.a11   IS first + 3:       -- transformation matrix of the cylinder
VAL c.a12   IS first + 4:       -- from gobal to local coord.
VAL c.a13   IS first + 5:
VAL c.a21   IS first + 6:
VAL c.a22   IS first + 7:
VAL c.a23   IS first + 8:
VAL c.a31   IS first + 9:
VAL c.a32   IS first + 10:
VAL c.a33   IS first + 11:
VAL c.rad   IS first + 12:      -- size of the circle
VAL c.len   IS first + 13:      -- length of the cylinder
VAL c.size  IS first + 14:

VAL first      IS o.specific :

VAL p.x        IS first + 1  :
VAL p.y        IS first + 2  :
VAL p.z        IS first + 3  :
VAL p.ux       IS first + 4  :
VAL p.uy       IS first + 5  :
VAL p.uz       IS first + 6  :
VAL p.vx       IS first + 7  :
VAL p.vy       IS first + 8  :
VAL p.vz       IS first + 9  :
VAL p.wx       IS first + 10 :
VAL p.wy       IS first + 11 :
VAL p.wz       IS first + 12 :
VAL p.sizeu    IS first + 13 :
VAL p.sizev    IS first + 14 :

VAL p.map      IS first + 15 :  -- which map ( texture or bump)
VAL p.uoffs    IS first + 16 :  -- offsets for u and v in map
VAL p.voffs    IS first + 17 :
VAL p.size     IS first + 18 :

VAL first      IS o.specific :

VAL pxy.x        IS first + 0 : -- origin x of the plane
VAL pxy.y        IS first + 1 : -- origin y of the plane
VAL pxy.z        IS first + 2 : -- origin z of the plane
VAL pxy.sizex    IS first + 3 : -- bounding on x axis
VAL pxy.sizey    IS first + 4 : -- bounding on y axis
VAL pxy.map      IS first + 5 :  -- which map ( texture or bump)
VAL pxy.uoffs    IS first + 6 :  -- offsets for u and v in map
VAL pxy.voffs    IS first + 7 :
VAL pxy.size     IS first + 8 :

VAL first      IS o.specific :

VAL pxz.x        IS first + 0 : -- origin x of the plane
VAL pxz.y        IS first + 1 : -- origin y of the plane
VAL pxz.z        IS first + 2 : -- origin z of the plane
VAL pxz.sizex    IS first + 3 : -- bounding on x axis
VAL pxz.sizez    IS first + 4 : -- bounding on z axis
VAL pxz.map      IS first + 5 :  -- which map ( texture or bump)
VAL pxz.uoffs    IS first + 6 :  -- offsets for u and v in map
VAL pxz.voffs    IS first + 7 :
VAL pxz.size     IS first + 8 :

VAL first      IS o.specific :

VAL pyz.x        IS first + 0 : -- origin x of the plane
VAL pyz.y        IS first + 1 : -- origin y of the plane
VAL pyz.z        IS first + 2 : -- origin z of the plane
VAL pyz.sizey    IS first + 3 : -- bounding on y axis
VAL pyz.sizez    IS first + 4 : -- bounding on z axis
VAL pyz.map      IS first + 5 :  -- which map ( texture or bump)
VAL pyz.uoffs    IS first + 6 :  -- offsets for u and v in map
VAL pyz.voffs    IS first + 7 :
VAL pyz.size     IS first + 8 :

VAL l.ir   IS 0 :   -- light intensity fields  R G B
VAL l.ig   IS 1 :
VAL l.ib   IS 2 :

VAL l.dx   IS 3 :   -- light direction cosines x y z
VAL l.dy   IS 4 :   -- this is a quick'n'tacky shading sheme
VAL l.dz   IS 5 :

VAL l.size IS 6 :

-- each light is |nextPtr|r|g|b|dx|dy|dz

--
-- run data is a vector of
--
--  runData [0] ->  ambient R
--           1      ambient G
--           2      ambient B
--           3      rendering mode  -- m.adaptive / m.dumb / m.stochastic
--           4      patch size
--           5      scale factor    -- 1 2 or 4
--           6      screenOrg x
--           7                y
--           8                z
--           9      screen  dxX
--           10             dyX
--           11             dzX
--           12     screen  dxY
--           13             dyY
--           14             dzY
--           15     pinhole  x
--           16     pinhole  y
--           17     pinhole  z
--

[20] INT runData :

[3] REAL32 ambient RETYPES [ runData FROM 0 FOR 3 ] :

renderingMode IS runData [3] :
runPatchSize  IS runData [4] :
scaleFactor   IS runData [5] :

[3] REAL32 screenOrg RETYPES [ runData FROM  6 FOR 3 ] :
[3] REAL32 screendX  RETYPES [ runData FROM  9 FOR 3 ] :
[3] REAL32 screendY  RETYPES [ runData FROM 12 FOR 3 ] :
[3] REAL32 pinhole   RETYPES [ runData FROM 15 FOR 3 ] :

VAL patchSize IS 16 :

PROC pumpWorldModels ( CHAN OF ANY out, INT model, VAL INT patchEdge, [256] INT buffer )
  [30] INT temp :
  [30] REAL32 ftemp RETYPES temp :
  VAL root.2 IS 1.414213562 (REAL32):
  VAL root.2.2 IS 0.7071067810 (REAL32):

  SEQ
    IF
      (model = 1)       --10 sphere selection
        SEQ
          VAL rad IS 102.0 (REAL32) :
          VAL y  IS -210.0 (REAL32) :
          VAL z  IS 3910.0 (REAL32) :
          VAL x0 IS -210.0 (REAL32) :
          VAL x1 IS    3.0 (REAL32) :
          VAL x2 IS  210.0 (REAL32) :
          SEQ
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := 0
            ftemp [  o.kdR] :=    0.7 (REAL32)
            ftemp [  o.kdG] :=    0.1 (REAL32)
            ftemp [  o.kdB] :=    0.1 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x0
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.2 (REAL32)
            ftemp [  o.kdG] :=    0.3 (REAL32)
            ftemp [  o.kdB] :=    0.4 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [   o.kg] :=   0.95 (REAL32)
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x1
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := 0
            ftemp [  o.kdR] :=    0.1 (REAL32)
            ftemp [  o.kdG] :=    0.9 (REAL32)
            ftemp [  o.kdB] :=    0.1 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x2
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
          writes ( "*N*C sent 3 spheres", buffer)
          VAL rad IS 102.0 (REAL32) :
          VAL y  IS    5.0 (REAL32) :
          VAL z  IS 3910.0 (REAL32) :
          VAL x0 IS -210.0 (REAL32) :
          VAL x1 IS    3.0 (REAL32) :
          VAL x2 IS  210.0 (REAL32) :
          SEQ
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.1 (REAL32)
            ftemp [  o.kdG] :=    0.4 (REAL32)
            ftemp [  o.kdB] :=    0.1 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)
            ftemp [   o.kg] :=    0.9 (REAL32)
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x0
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.3 (REAL32)
            ftemp [  o.kdG] :=    0.1 (REAL32)
            ftemp [  o.kdB] :=    0.1 (REAL32)
            ftemp [   o.ks] :=   0.95 (REAL32)
            ftemp [   o.kg] :=   0.95 (REAL32)
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x1
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.3 (REAL32)
            ftemp [  o.kdG] :=    0.1 (REAL32)
            ftemp [  o.kdB] :=    0.3 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [   o.kg] :=   0.95 (REAL32)
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x2
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
          writes ( "*N*C sent 3 spheres", buffer)
          VAL rad IS 102.0 (REAL32) :
          VAL y  IS  210.0 (REAL32) :
          VAL z  IS 3910.0 (REAL32) :
          VAL x0 IS -210.0 (REAL32) :
          VAL x1 IS    3.0 (REAL32) :
          VAL x2 IS  210.0 (REAL32) :
          SEQ
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := 0
            ftemp [  o.kdR] :=    0.7 (REAL32)
            ftemp [  o.kdG] :=    0.7 (REAL32)
            ftemp [  o.kdB] :=    0.1 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x0
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.4 (REAL32)
            ftemp [  o.kdG] :=    0.1 (REAL32)
            ftemp [  o.kdB] :=    0.4 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)
            ftemp [   o.kg] :=    0.9 (REAL32)
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x1
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.sphere
            temp  [ o.attr] := 0
            ftemp [  o.kdR] :=    0.1 (REAL32)
            ftemp [  o.kdG] :=    0.1 (REAL32)
            ftemp [  o.kdB] :=    0.7 (REAL32)
            ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
            ftemp [  s.rad] :=  rad
            ftemp [    s.x] := x2
            ftemp [    s.y] := y
            ftemp [    s.z] := z
            out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
          writes ( "*N*C sent 3 spheres", buffer)
          temp  [ o.type] := o.sphere
          temp  [ o.attr] := a.spec \/ a.frac

          ftemp [  o.kdR] :=    0.0  (REAL32)
          ftemp [  o.kdG] :=    0.0 (REAL32)
          ftemp [  o.kdB] :=    0.0  (REAL32)

          ftemp [   o.ks] :=    0.3  (REAL32)
          ftemp [   o.kg] :=    0.8  (REAL32)

          ftemp [o.xmitR] :=    0.7  (REAL32)
          ftemp [o.xmitG] :=    0.7  (REAL32)
          ftemp [o.xmitB] :=    0.7  (REAL32)

          ftemp [o.refix] :=   1.02 (REAL32) -- / 0.929091 (REAL32)  -- ??? it was 1.1
          temp  [o.power] :=   10

          ftemp [  s.rad] :=  100.0 (REAL32)

          ftemp [    s.x] :=  -90.0 (REAL32)
          ftemp [    s.y] :=  -80.0 (REAL32)
          ftemp [    s.z] := 3100.0 (REAL32)
          out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
          writes ( "*N*C sent glass sphere", buffer)
      (model = 2)       --14 sphere selection
        SEQ
          VAL r          IS 300.0 (REAL32) :
          VAL r.2        IS 2.0 (REAL32) * r :
          VAL r.2.root.2 IS 2.828427 (REAL32) * r :
          VAL r.root.2   IS 1.414213 (REAL32) * r :
          VAL floor      IS r.2 - 1000.0 (REAL32) :
          VAL xc         IS 0.0 (REAL32) :
          VAL zc         IS 12000.0 (REAL32) :
          SEQ
            SEQ ix = 0 FOR 3
              SEQ jx = 0 FOR 3
                VAL i IS ix - 1 :
                VAL j IS jx - 1 :
                VAL b IS 0.5 (REAL32) :
                VAL d IS 0.04 (REAL32) :
                VAL bdull IS [ b, d ] :
                VAL sp IS (ix * 3) + jx :
                SEQ
                  temp  [ o.type] := o.sphere
                  temp  [ o.attr] := a.spec
                  ftemp [  o.kdR] := bdull [jx /\ 1]
                  ftemp [  o.kdG] := bdull [ix /\ 1]
                  ftemp [  o.kdB] := bdull [ix /\ 4]
                  ftemp [   o.ks] :=    0.7 (REAL32)
                  ftemp [   o.kg] :=    0.7 (REAL32)
                  ftemp [  s.rad] :=  r
                  ftemp [    s.x] := xc + (r.2 * (REAL32 TRUNC i))
                  ftemp [    s.y] := floor
                  ftemp [    s.z] := zc + (r.2 * (REAL32 TRUNC j))
                  out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            SEQ i = 0 FOR 2
              SEQ j = 0 FOR 2
                VAL offs IS [ -r, r] :
                VAL m IS (i * 2) + j :
                SEQ
                  temp  [ o.type] := o.sphere
                  temp  [ o.attr] := a.spec
                  IF
                    m = 0
                      SEQ
                        ftemp [  o.kdR] :=    0.5 (REAL32)
                        ftemp [  o.kdG] :=    0.04 (REAL32)
                        ftemp [  o.kdB] :=    0.03 (REAL32)
                    m = 1
                      SEQ
                        ftemp [  o.kdR] :=    0.1 (REAL32)
                        ftemp [  o.kdG] :=    0.7 (REAL32)
                        ftemp [  o.kdB] :=    0.1 (REAL32)
                    m = 2
                      SEQ
                        ftemp [  o.kdR] :=    0.1 (REAL32)
                        ftemp [  o.kdG] :=    0.1 (REAL32)
                        ftemp [  o.kdB] :=    0.7 (REAL32)
                    m = 3
                      SEQ
                        ftemp [  o.kdR] :=    0.2 (REAL32)
                        ftemp [  o.kdG] :=    0.5 (REAL32)
                        ftemp [  o.kdB] :=    0.1 (REAL32)
                  ftemp [   o.ks] :=    0.7 (REAL32)
                  ftemp [   o.kg] :=    0.7 (REAL32)
                  ftemp [  s.rad] :=  r
                  ftemp [    s.x] := xc + offs [i]
                  ftemp [    s.y] := floor + r.root.2
                  ftemp [    s.z] := zc + offs [j]
                  out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
            temp  [ o.type] := o.ellipsoid
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=    0.04 (REAL32)
            ftemp [  o.kdG] :=    0.04 (REAL32)
            ftemp [  o.kdB] :=    0.3 (REAL32)
            ftemp [   o.ks] :=    0.7 (REAL32)
            ftemp [   o.kg] :=    0.7 (REAL32)
            ftemp [    e.x] := xc
            ftemp [    e.y] := (floor + r.2.root.2 ) + 100.0 (REAL32)
            ftemp [    e.z] := zc
            ftemp [  e.a11] := 1.0 (REAL32)
            ftemp [  e.a12] := 0.0 (REAL32)
            ftemp [  e.a13] := 0.0 (REAL32)
            ftemp [  e.a21] := 0.0 (REAL32)
            ftemp [  e.a22] := 1.0 (REAL32)
            ftemp [  e.a23] := 0.0 (REAL32)
            ftemp [  e.a31] := 0.0 (REAL32)
            ftemp [  e.a32] := 0.0 (REAL32)
            ftemp [  e.a33] := 1.0 (REAL32)
            ftemp [  e.radx] := r
            ftemp [  e.rady] := r + 200.0 (REAL32)
            ftemp [  e.radz] := r
            out ! c.object; e.size; [ temp FROM 0 FOR e.size ]
            writes ( "*N*C sent 14 spheres", buffer)
      (model = 3)                           --cone and ellipsoid image
        SEQ
          VAL root.2  IS  1.414213562 (REAL32) :
          SEQ
            temp  [ o.type] := o.cone
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=     0.04        (REAL32)
            ftemp [  o.kdG] :=     0.04       (REAL32)
            ftemp [  o.kdB] :=     0.4        (REAL32)
            ftemp [   o.ks] :=     0.9        (REAL32)
            ftemp [   o.kg] :=     0.95        (REAL32)
            ftemp [   co.x] :=   300.0        (REAL32)
            ftemp [   co.y] :=     0.0        (REAL32)
            ftemp [   co.z] := 12000.0        (REAL32)
            ftemp [ co.a11] :=     0.3  (REAL32)  * root.2
            ftemp [ co.a12] :=     0.4  (REAL32)  * root.2
            ftemp [ co.a13] :=     0.5  (REAL32)  * root.2
            ftemp [ co.a21] :=    -0.8  (REAL32)
            ftemp [ co.a22] :=     0.6  (REAL32)
            ftemp [ co.a23] :=     0.0  (REAL32)
            ftemp [ co.a31] :=  ( -0.3  (REAL32)) * root.2
            ftemp [ co.a32] :=  ( -0.4  (REAL32)) * root.2
            ftemp [ co.a33] :=     0.5  (REAL32)  * root.2
            ftemp [ co.rada] :=   200.0        (REAL32)
            ftemp [ co.radb] :=   300.0        (REAL32)
            ftemp [ co.len] :=    800.0        (REAL32)
            out ! c.object; co.size; [ temp FROM 0 FOR  co.size ]
          SEQ
            temp  [ o.type] := o.ellipsoid
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=     0.7        (REAL32)
            ftemp [  o.kdG] :=     0.03       (REAL32)
            ftemp [  o.kdB] :=     0.03       (REAL32)
            ftemp [   o.ks] :=     0.9        (REAL32)
            ftemp [   o.kg] :=     0.95        (REAL32)
            ftemp [    e.x] :=  -200.0        (REAL32)
            ftemp [    e.y] :=   500.0        (REAL32)
            ftemp [    e.z] := 13000.0        (REAL32)
            ftemp [  e.a11] :=     0.6  (REAL32)
            ftemp [  e.a12] :=     0.8  (REAL32)
            ftemp [  e.a13] :=     0.0  (REAL32)
            ftemp [  e.a21] :=    -0.8  (REAL32)
            ftemp [  e.a22] :=     0.6  (REAL32)
            ftemp [  e.a23] :=     0.0  (REAL32)
            ftemp [  e.a31] :=     0.0  (REAL32)
            ftemp [  e.a32] :=     0.0  (REAL32)
            ftemp [  e.a33] :=     1.0  (REAL32)
            ftemp [  e.radx] :=   100.0        (REAL32)
            ftemp [  e.rady] :=   500.0        (REAL32)
            ftemp [  e.radz] :=   100.0        (REAL32)
            out ! c.object;  e.size; [ temp FROM 0 FOR   e.size ]
          SEQ
            temp  [ o.type] := o.plane
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=        0.03      (REAL32)
            ftemp [  o.kdG] :=        0.4        (REAL32)
            ftemp [  o.kdB] :=        0.03      (REAL32)
            ftemp [   o.ks] :=        0.7       (REAL32)
            ftemp [   o.kg] :=        0.2       (REAL32)
            ftemp [    p.x] :=     -700.0        (REAL32)
            ftemp [    p.y] :=     -500.0        (REAL32)
            ftemp [    p.z] :=     13000.0       (REAL32)
            ftemp [   p.ux] :=       -0.6470     (REAL32)  -- all the three vectors
            ftemp [   p.uy] :=        0.7548     (REAL32)  -- must be normalized.
            ftemp [   p.uz] :=        0.1078     (REAL32)
            ftemp [   p.vx] :=        0.6470     (REAL32)
            ftemp [   p.vy] :=        0.1078     (REAL32)
            ftemp [   p.vz] :=        0.7548     (REAL32)
            ftemp [   p.wx] :=        0.5774     (REAL32)
            ftemp [   p.wy] :=        0.5773     (REAL32)
            ftemp [   p.wz] :=       -0.5773     (REAL32)
            ftemp [ p.sizeu] :=  1500.0        (REAL32)
            ftemp [ p.sizev] :=  1500.0        (REAL32)
            out ! c.object; p.size; [ temp FROM 0 FOR  p.size ]
            writes ( "*N*C sent a Cone and an Ellipsoid", buffer)
      (model = 4)                               -- cylinder and sphere image
        SEQ
          temp  [ o.type] := o.cylinder
          temp  [ o.attr] := a.spec
          ftemp [  o.kdR] :=     0.3        (REAL32)
          ftemp [  o.kdG] :=     0.3        (REAL32)
          ftemp [  o.kdB] :=     0.03       (REAL32)
          ftemp [   o.ks] :=     0.9        (REAL32)
          ftemp [   o.kg] :=     0.95       (REAL32)
          ftemp [    c.x] :=   0.0        (REAL32)
          ftemp [    c.y] :=  -500.0        (REAL32)
          ftemp [    c.z] := 10900.0        (REAL32)
          ftemp [  c.a11] :=     1.0  (REAL32)
          ftemp [  c.a12] :=     0.0  (REAL32)
          ftemp [  c.a13] :=     0.0  (REAL32)
          ftemp [  c.a21] :=   ( 0.0  (REAL32))
          ftemp [  c.a22] :=   (-1.0   (REAL32)) 
          ftemp [  c.a23] :=     2.5  (REAL32)
          ftemp [  c.a31] :=     0.0  (REAL32)
          ftemp [  c.a32] :=     1.0  (REAL32)
          ftemp [  c.a33] :=   -0.6   (REAL32)
          ftemp [  c.rad] :=   350.0        (REAL32)
          ftemp [  c.len] :=   800.0        (REAL32)
          out ! c.object;  c.size; [ temp FROM 0 FOR   c.size ]
          SEQ 
            VAL root.2  IS  1.414213562 (REAL32) :
            VAL rad IS 80.0 (REAL32) :
            VAL x  IS -310.0 (REAL32) : 
            VAL y  IS 690.0 (REAL32) :
            VAL z  IS 11300.0 (REAL32) :
            SEQ
              temp  [ o.type] := o.sphere
              temp  [ o.attr] := 0
              ftemp [  o.kdR] :=    0.7 (REAL32)
              ftemp [  o.kdG] :=    0.1 (REAL32)
              ftemp [  o.kdB] :=    0.1 (REAL32)
              ftemp [   o.ks] :=    0.9 (REAL32)  -- not needed here
              ftemp [  s.rad] :=  rad
              ftemp [    s.x] := x
              ftemp [    s.y] := y
              ftemp [    s.z] := z
              out ! c.object; s.size; [ temp FROM 0 FOR s.size ]
          SEQ
            temp  [ o.type] := o.xyplane
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=      0.5        (REAL32)
            ftemp [  o.kdG] :=      0.0        (REAL32)
            ftemp [  o.kdB] :=      0.5        (REAL32)
            ftemp [   o.ks] :=      0.9        (REAL32)
            ftemp [   o.kg] :=     0.95        (REAL32)
            ftemp [    pxy.x] :=  -1000.0        (REAL32)
            ftemp [    pxy.y] :=  -1000.0        (REAL32)
            ftemp [    pxy.z] :=  14000.0        (REAL32)
            ftemp [ pxy.sizex] :=  2000.0        (REAL32)
            ftemp [ pxy.sizey] :=  1000.0        (REAL32)
            out ! c.object; pxy.size; [ temp FROM 0 FOR  pxy.size ]
            writes ( "*N*C sent a Cylinder and a Sphere", buffer)
      (model = 5)                               -- SMALL cylinder and sphere image for TESTING
        SEQ
          temp  [ o.type] := o.cylinder
          temp  [ o.attr] := a.spec
          ftemp [  o.kdR] :=     0.3        (REAL32)
          ftemp [  o.kdG] :=     0.3        (REAL32)
          ftemp [  o.kdB] :=     0.03       (REAL32)
          ftemp [   o.ks] :=     0.9        (REAL32)
          ftemp [   o.kg] :=     0.95       (REAL32)
          ftemp [    c.x] :=   0.0        (REAL32)
          ftemp [    c.y] :=  -500.0        (REAL32)
          ftemp [    c.z] := 10900.0        (REAL32)
          ftemp [  c.a11] :=     1.0  (REAL32)
          ftemp [  c.a12] :=     0.0  (REAL32)
          ftemp [  c.a13] :=     0.0  (REAL32)
          ftemp [  c.a21] :=   ( 0.0  (REAL32))
          ftemp [  c.a22] :=   (-1.0   (REAL32)) 
          ftemp [  c.a23] :=     2.5  (REAL32)
          ftemp [  c.a31] :=     0.0  (REAL32)
          ftemp [  c.a32] :=     1.0  (REAL32)
          ftemp [  c.a33] :=   -0.6   (REAL32)
          ftemp [  c.rad] :=   3.0        (REAL32)
          ftemp [  c.len] :=   800.0        (REAL32)
          out ! c.object;  c.size; [ temp FROM 0 FOR   c.size ]
          SEQ 
            temp  [ o.type] := o.xyplane
            temp  [ o.attr] := a.spec
            ftemp [  o.kdR] :=      0.5        (REAL32)
            ftemp [  o.kdG] :=      0.0        (REAL32)
            ftemp [  o.kdB] :=      0.5        (REAL32)
            ftemp [   o.ks] :=      0.9        (REAL32)
            ftemp [   o.kg] :=     0.95        (REAL32)
            ftemp [    pxy.x] :=  -1000.0        (REAL32)
            ftemp [    pxy.y] :=  -1000.0        (REAL32)
            ftemp [    pxy.z] :=  14000.0        (REAL32)
            ftemp [ pxy.sizex] :=  2000.0        (REAL32)
            ftemp [ pxy.sizey] :=  1000.0        (REAL32)
            out ! c.object; pxy.size; [ temp FROM 0 FOR  pxy.size ]
            writes ( "*N*C sent a tiny Cylinder", buffer)        
      TRUE
        SKIP 
    IF
      (model <> 1)
        SEQ
          temp  [ o.type] := o.xzplane
          temp  [ o.attr] := (a.spec \/ a.bound0) \/ a.bound1 -- mirrored plane
          ftemp [  o.kdR] := 0.05 (REAL32)
          ftemp [  o.kdG] := 0.4 (REAL32)
          ftemp [  o.kdB] := 0.05 (REAL32)
          ftemp [   o.ks] := 0.7 (REAL32)
          ftemp [   o.kg] := 0.1 (REAL32)
          ftemp [    pxz.x] := -2000.0 (REAL32)
          ftemp [    pxz.y] :=  -690.0 (REAL32)
          ftemp [    pxz.z] := 10000.0 (REAL32)
          ftemp [pxz.sizex] :=  4000.0 (REAL32)
          ftemp [pxz.sizez] :=  3000.0 (REAL32)
          out ! c.object; pxz.size; [ temp FROM 0 FOR pxz.size ]
          writes ( "*N*C a plane", buffer)
      TRUE
        SKIP         
    ftemp [ l.ir] := 780.8 (REAL32)  -- a yellow sun
    ftemp [ l.ig] := 780.8 (REAL32)
    ftemp [ l.ib] := 710.7 (REAL32)

    ftemp [ l.dx] :=   1.7 (REAL32)
    ftemp [ l.dy] :=   1.6 (REAL32)
    ftemp [ l.dz] :=  -0.9 (REAL32)

    out ! c.light; l.size; [ temp FROM 0 FOR l.size ]
    writes ( "*N*C a light", buffer)
    ftemp [ l.ir] := 780.8 (REAL32)  -- a yellow sun
    ftemp [ l.ig] := 780.8 (REAL32)
    ftemp [ l.ib] := 710.7 (REAL32)

    ftemp [ l.dx] :=   -1.1 (REAL32)
    ftemp [ l.dy] :=   1.8 (REAL32)
    ftemp [ l.dz] :=  -0.3 (REAL32)

    out ! c.light; l.size; [ temp FROM 0 FOR l.size ]
    writes ( "*N*C a light", buffer)
    VAL cosTheta IS 0.93969 (REAL32) :
    VAL sinTheta IS 0.34202 (REAL32) :
    VAL sin.256  IS sinTheta * 256.0 (REAL32) :
    VAL cos.256  IS cosTheta * 256.0 (REAL32) :
    VAL offX IS 0.0 (REAL32) :
    VAL offY IS 0.0 (REAL32) :
    VAL offZ IS 0.0 (REAL32) :
    SEQ
      --renderingMode := m.dumb
      renderingMode := m.adaptive
      runPatchSize  := patchEdge
      scaleFactor   := 1

      ambient   [0] := 266.0 (REAL32)
      ambient   [1] := 266.0 (REAL32)
      ambient   [2] := 280.0 (REAL32)

      screenOrg [0] := offX - 256.0 (REAL32)
      screenOrg [1] := offY - 256.0 (REAL32)
      screenOrg [2] := offZ + 0.0 (REAL32)

      screendX  [0] := 1.0 (REAL32)
      screendX  [1] := 0.0 (REAL32)
      screendX  [2] := 0.0 (REAL32)

      screendY  [0] := 0.0 (REAL32)
      screendY  [1] := 1.0 (REAL32) -- cosTheta
      screendY  [2] := 0.0 (REAL32) -- sinTheta

      pinhole   [0] := offX + 0.0 (REAL32)
      pinhole   [1] := offY + 0.0 (REAL32) -- - (1024.0 (REAL32) * cosTheta)
      pinhole   [2] := offZ + 1024.0 (REAL32) -- (1024.0 (REAL32) * cosTheta)

      out ! c.runData; 20; [ runData FROM 0 FOR 20 ]

    --VAL cosTheta IS 0.93969 (REAL32) :
    --VAL sinTheta IS 0.34202 (REAL32) :
    --VAL sin.256  IS sinTheta * 256.0 (REAL32) :
    --VAL cos.256  IS cosTheta * 256.0 (REAL32) :
    --VAL offX IS 0.0 (REAL32) :
    --VAL offY IS 0.0 (REAL32) :
    --VAL offZ IS 0.0 (REAL32) :
    --SEQ
    --  --renderingMode := m.dumb
    --  renderingMode := m.adaptive
    --  runPatchSize  := patchEdge
    --  scaleFactor   := 1

    --  ambient   [0] := 236.0 (REAL32)
    --  ambient   [1] := 236.0 (REAL32)
    --  ambient   [2] := 270.0 (REAL32)

    --  screenOrg [0] := offX - 256.0 (REAL32)
    --  screenOrg [1] := offY - 256.0 (REAL32)
    --  screenOrg [2] := offZ + 0.0 (REAL32)

    --  screendX  [0] := 1.0 (REAL32)
    --  screendX  [1] := 0.0 (REAL32)
    --  screendX  [2] := 0.0 (REAL32)

    --  screendY  [0] := 0.0 (REAL32)
    --  screendY  [1] := 1.0 (REAL32) -- cosTheta
    --  screendY  [2] := 0.0 (REAL32) -- sinTheta

    --  pinhole   [0] := offX + 0.0 (REAL32)
    --  pinhole   [1] := offY + 0.0 (REAL32) -- - (1024.0 (REAL32) * cosTheta)
    --  pinhole   [2] := offZ + 1024.0 (REAL32) -- (1024.0 (REAL32) * cosTheta)

    --  out ! c.runData; 20; [ runData FROM 0 FOR 20 ]
    writes ( "*N*C run data", buffer)
:

