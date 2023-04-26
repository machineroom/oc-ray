#!/usr/bin/env python3

# Create an Occam network map of the longest pipe from the output of ispy for the WX9020 hardware
# a combo of ispy_to_network and ispy_to_graph
import sys
import string
import networkx as nx
import argparse

parser = argparse.ArgumentParser(
                    prog='ispy_to_long_pipe ',
                    description='From ispy output write a network map of the longest pipe')

parser.add_argument('--input', default=sys.stdin)
parser.add_argument('--output', default='network.inc')
parser.add_argument('--b438', default=False, action='store_true')
args = parser.parse_args()

ispy_output = open(args.input).readlines()
processors = 0

filtered = []
for line in ispy_output:
    line = line.strip()
    # strip any headers
    if line.startswith(tuple(string.digits)):
        filtered.append (line.strip())
        processors += 1

G = nx.Graph()  # create graph object

n = len(filtered)
nodes = range(n)
labels = ['n ' + str(l) for l in range(n)]

edges = []

for line in filtered:
    processor = int(line.split()[0])
    line = line[line.index('[')+1:line.index(']')]
    links = line.split()
    for index,link in enumerate(links):
        if link == "..." or link=="HOST":
            pass
        else:
            target_processor = int(link.split(":")[0])
            if processor != target_processor:
                edges.append((processor, target_processor))


G.add_nodes_from(nodes)
G.add_edges_from(edges)

# crude hack to get a long path - i.e. for simple pipe layout
longest_length=0
longest_path=None
count=0
for path in nx.all_simple_edge_paths(G,0,n-1):
    if len(path) > longest_length:
        print (f"Longest so far {len(path)}")
        longest_path = path
        longest_length = len(path)
    count+=1
    if count == 2000:
        print (f"stopping at {count}")
        break
print (f"longest path(edges) = {longest_path}")

with open(args.output, encoding="utf-8", mode="w+") as output:
    output.write (f"-- NETWORK block auto-generated by ispy_to_long_pipe.py (args {sys.argv})\n")
    output.write ("-- problem size. `processors` is total number of nodes in the net. `workers` is number of raytracer nodes (processors-1)\n")
    output.write ("-- assumed that framebuf and cntlsys on proc 0\n")
    output.write (f"VAL processors IS {processors} :\n")
    output.write ("VAL workers IS (processors-1) :\n")
    output.write ("[processors]NODE System:\n")

    output.write ("NETWORK\n")
    output.write ("  DO\n")
    if args.b438:
       output.write ("    SET System[0] (type, memsize := \"T805\", 2*M)\n")
    else:
       output.write ("    SET System[0] (type, memsize := \"T425\", 1*M)\n")
    
    output.write ("    SET System[1] (type, memsize := \"T425\", 16*M)\n")
    output.write ("    DO i = 2 FOR workers\n")
    output.write ("      SET System[i] (type, memsize := \"T425\", 16*M)\n")

    if args.b438:
        # work around: ispy on B438 doesn't print HOST for the host link?
        output.write ("    CONNECT System[0][link][0] TO HOST WITH Hostlink\n")

    for line in filtered:
        # Translate from this...
        #0 T425c-20 962k 1 [    ...   HOST    1:2    2:0 ]
        # to this...
        #CONNECT System[0][link][1] TO HOST WITH Hostlink
        # or this...
        #CONNECT System[1][link][0] TO System[0][link][3]
        processor = int(line.split()[0])
        line = line[line.index('[')+1:line.index(']')]
        links = line.split()
        for index,link in enumerate(links):
            if link == "...":
                pass
            elif link == "HOST":
                output.write (f"    CONNECT System[{processor}][link][{index}] TO HOST WITH Hostlink\n")
            else:
                target_processor = int(link.split(":")[0])
                if (processor,target_processor) in longest_path:
                    target_link = link.split(":")[1]
                    output.write (f"    CONNECT System[{processor}][link][{index}] TO System[{target_processor}][link][{target_link}]\n")
                    break
                        
        
    output.write (":\n")

