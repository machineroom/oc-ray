#!/usr/bin/env python3

# Create an Occam network map from the output of ispy for the WX9020 hardware
import sys
import string

ispy_output = sys.stdin.readlines()

processors = 0
for line in ispy_output:
    line = line.strip()
    # strip any headers
    if (line.startswith(tuple(string.digits))):
        processors+=1

print ("-- NETWORK block auto-generated by ispy_to_network.py")

print ("-- problem size. `processors` is total number of nodes in the net. `workers` is number of raytracer nodes (processors-2)")
print (f"VAL processors IS {processors} :")
print ("VAL workers IS (processors-2) :")
print ("[processors]NODE System:")

print ("NETWORK")
print ("  DO")
print ("    SET System[0] (type, memsize := \"T425\", 1*M)")
print ("    SET System[1] (type, memsize := \"T425\", 16*M)")
print ("    DO i = 2 FOR workers")
print ("      SET System[i] (type, memsize := \"T425\", 16*M)")


for line in ispy_output:
    line = line.strip()
    # strip any headers
    if (line.startswith(tuple(string.digits))):
        # Translate from this...
        #0 T425c-20 962k 1 [    ...   HOST    1:2    2:0 ]
        # to this...
        #CONNECT System[0][link][1] TO HOST WITH Hostlink
        # or this...
        #CONNECT System[1][link][0] TO System[0][link][3]
        processor = line.split()[0]
        line = line[line.index('[')+1:line.index(']')]
        links = line.split()
        for index,link in enumerate(links):
            if link == "...":
                pass
            elif link == "HOST":
                print (f"    CONNECT System[{processor}][link][{index}] TO HOST WITH Hostlink")
            else:
                target_processor = link.split(":")[0]
                target_link = link.split(":")[1]
                if int(target_processor) < int(processor):
                    # only connect "backwards" else occam tools complain about duplicated connections
                    # this also removes links connected on the same processor (that ispy reports twice and occam tools bitch about)
                    print (f"    CONNECT System[{processor}][link][{index}] TO System[{target_processor}][link][{target_link}]")
        
print (":")