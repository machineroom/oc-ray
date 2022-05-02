#!/usr/bin/env python3

# Create the CONNECT statements of an Occam netork map from the output of ispy
import sys
import string
for line in sys.stdin:
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
                if target_processor <= processor:
                    # only connect "backwards" else occam tools complain about duplicated connections
                    print (f"    CONNECT System[{processor}][link][{index}] TO System[{target_processor}][link][{target_link}]")
        
