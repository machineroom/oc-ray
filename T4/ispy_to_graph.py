#!/usr/bin/env python3

# Create an Occam network map from the output of ispy for the WX9020 hardware
import sys
import string
from pyvis.network import Network
import matplotlib.pyplot as plt
import networkx as nx

ispy_output = open(sys.argv[1]).readlines()

filtered = []
for line in ispy_output:
    line = line.strip()
    # strip any headers
    if line.startswith(tuple(string.digits)):
        filtered.append (line.strip())

pvnet = Network()  # create graph object
G = nx.Graph()  # create graph object

n = len(filtered)
nodes = range(n)
labels = ['n ' + str(l) for l in range(n)]

pvnet.add_nodes(
    nodes,  # node ids
    label=labels,  # node labels
    # node titles (display on mouse hover)
    #title=['Main node', 'Just node', 'Just node', 'Just node', 'Node with self-loop'],
    #color=['#d47415', '#22b512', '#42adf5', '#4a21b0', '#e627a3']  # node colors (HEX)
)

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
            pvnet.add_edges([(processor, target_processor)])
            edges.append((processor, target_processor))


pvnet.show('graph.html', notebook=False)  # save visualization in 'graph.html'

G.add_nodes_from(nodes)
G.add_edges_from(edges)

distanceDict = nx.shortest_path_length(G, 0)
#colours=['black','pink','yellow','orange','yellow','brown','burgundy','red', 'green']
cmap=[]
for node in G:
    #colour = colours[distanceDict[node]]
    #cmap.append(colour)
    G.nodes[node]['weight'] = distanceDict[node]
    cmap.append(float(distanceDict[node]))
pos = nx.spring_layout(G, seed=0)
#pos = nx.circular_layout(G)
nx.draw(G, with_labels=True, node_color=cmap, pos=pos, cmap=plt.cm.Blues, vmin=0, vmax=8)
plt.show()

                        
        
