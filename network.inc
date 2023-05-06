-- MANUAL block for 12 workers

VAL processors IS 13 :
VAL workers IS (processors-1) :
[processors]NODE System:
NETWORK
  DO
    SET System[0] (type, memsize := "T805", 2*M)
    DO i = 1 FOR workers
      SET System[i] (type, memsize := "T425", 16*M)
    CONNECT System[0][link][0] TO HOST WITH Hostlink
    CONNECT System[0][link][1] TO System[1][link][2]
    CONNECT System[0][link][2] TO System[2][link][0]

    CONNECT System[1][link][0] TO System[3][link][2]
    CONNECT System[1][link][1] TO System[4][link][1]

    CONNECT System[2][link][1] TO System[5][link][1]
    CONNECT System[2][link][2] TO System[6][link][0]

    CONNECT System[3][link][0] TO System[7][link][2]
    CONNECT System[3][link][1] TO System[8][link][1]

    CONNECT System[6][link][1] TO System[9][link][1]
    CONNECT System[6][link][2] TO System[10][link][0]

    CONNECT System[7][link][1] TO System[11][link][1]

    CONNECT System[10][link][1] TO System[12][link][1]
:

--{{{  Mapping
NODE framebuf.p :
NODE cntlsys.p :
[workers]NODE raytrace.p :
MAPPING
  DO
    MAP framebuf.p ONTO System[0]
    MAP cntlsys.p ONTO System[0]
    MAP raytrace.p[0] ONTO System[1]
    MAP raytrace.p[1] ONTO System[2]
    MAP raytrace.p[2] ONTO System[3]
    MAP raytrace.p[3] ONTO System[4]
    MAP raytrace.p[4] ONTO System[5]
    MAP raytrace.p[5] ONTO System[6]
    MAP raytrace.p[6] ONTO System[7]
    MAP raytrace.p[7] ONTO System[8]
    MAP raytrace.p[8] ONTO System[9]
    MAP raytrace.p[9] ONTO System[10]
    MAP raytrace.p[10] ONTO System[11]
    MAP raytrace.p[11] ONTO System[12]
:
--}}}
