---------------------------- COMMANDS PROTOCOL -----------------------------

VAL c.invalid  IS -1:
VAL c.stop     IS 0 :
VAL c.render   IS 1 :  -- render; x0; y0
VAL c.object   IS 2 :  -- object; size; [ size ]
VAL c.light    IS 3 :  -- light;  size; [ size ]
VAL c.patch    IS 4 :  -- patch;  x; y; patchSize; worker; [ patchSize][patchSize]
VAL c.runData  IS 5 :  -- ambient light, rendering mode, screen pos etc.
VAL c.message  IS 6 :  -- message; size; [ words ]
VAL c.map      IS 7 :
VAL c.mapAck   IS 8 :  -- count
VAL c.message2 IS 9:  -- message; p1; p2; size; [ words ]

