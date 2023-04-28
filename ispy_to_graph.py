#!/usr/bin/env python3

# Create an Occam network map from the output of ispy for the WX9020 hardware
import sys
import string
import matplotlib.pyplot as plt
import networkx as nx

ispy_output = open(sys.argv[1]).readlines()

filtered = []
for line in ispy_output:
    line = line.strip()
    # strip any headers
    if line.startswith(tuple(string.digits)):
        filtered.append (line.strip())

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

#colour edges by longest path
for e in G.edges():
    G[e[0]][e[1]]['color'] = 'black'
for e in longest_path:
    G[e[0]][e[1]]['color'] = 'red'
edge_colours = [ G[e[0]][e[1]]['color'] for e in G.edges() ]

#colour nodes by distance from root
distanceDict = nx.shortest_path_length(G, 0)
cmap=[]
for node in G:
    cmap.append(float(distanceDict[node]))
pos = nx.spring_layout(G, center=[0,0], iterations=5000)
nx.draw(G, edge_color=edge_colours, with_labels=True, node_color=cmap, pos=pos, cmap=plt.cm.Blues, vmin=0, vmax=8)
plt.show()
