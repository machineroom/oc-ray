-- MANUAL block for 12 workers

VAL processors IS 13 :
VAL workers IS (processors-1) :
NODE Root:
[workers]NODE System:
NETWORK
  DO
    SET Root (type, memsize := "T805", 2*M)
    DO i = 0 FOR workers
      SET System[i] (type, memsize := "T425", 16*M)
    CONNECT Root[link][0] TO HOST WITH Hostlink
    CONNECT Root[link][1] TO System[0][link][2]
    CONNECT Root[link][2] TO System[1][link][0]

    CONNECT System[0][link][0] TO System[2][link][2]
    CONNECT System[0][link][1] TO System[3][link][1]

    CONNECT System[1][link][1] TO System[4][link][1]
    CONNECT System[1][link][2] TO System[5][link][0]

    CONNECT System[2][link][0] TO System[6][link][2]
    CONNECT System[2][link][1] TO System[7][link][1]

    CONNECT System[5][link][1] TO System[8][link][1]
    CONNECT System[5][link][2] TO System[9][link][0]

    CONNECT System[6][link][1] TO System[10][link][1]

    CONNECT System[9][link][1] TO System[11][link][1]
:

--{{{  Mapping
NODE framebuf.p :
NODE cntlsys.p :
[workers]NODE raytrace.p :
MAPPING
  DO
    MAP framebuf.p ONTO Root
    MAP cntlsys.p ONTO Root
    MAP raytrace.p[0] ONTO System[0]
    MAP raytrace.p[1] ONTO System[1]
    MAP raytrace.p[2] ONTO System[2]
    MAP raytrace.p[3] ONTO System[3]
    MAP raytrace.p[4] ONTO System[4]
    MAP raytrace.p[5] ONTO System[5]
    MAP raytrace.p[6] ONTO System[6]
    MAP raytrace.p[7] ONTO System[7]
    MAP raytrace.p[8] ONTO System[8]
    MAP raytrace.p[9] ONTO System[9]
    MAP raytrace.p[10] ONTO System[10]
    MAP raytrace.p[11] ONTO System[11]
:
--}}}
