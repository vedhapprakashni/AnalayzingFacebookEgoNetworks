import networkx as nx
from networkx.algorithms import community

# Load the graph
G = nx.read_edgelist("facebook_combined.txt")

print("Total Nodes:", G.number_of_nodes())
print("Total Edges:", G.number_of_edges())

# Betweenness Centrality
bet_centrality = nx.betweenness_centrality(G)
top_bet = sorted(bet_centrality.items(), key=lambda x: x[1], reverse=True)[:5]
print("\nTop 5 Betweenness Centrality Nodes:")
for node, val in top_bet:
    print(f"Node {node}: {val:.4f}")

#Eigenvector Centrality
eigen_centrality = nx.eigenvector_centrality(G, max_iter=1000)
top_eigen = sorted(eigen_centrality.items(), key=lambda x: x[1], reverse=True)[:5]
print("\nTop 5 Eigenvector Centrality Nodes:")
for node, val in top_eigen:
    print(f"Node {node}: {val:.4f}")

#Diameter of Network (only for connected graphs)
if nx.is_connected(G):
    diameter = nx.diameter(G)
    print(f"\nDiameter of Network: {diameter}")
else:
    print("\nGraph is not connected. Computing diameter of largest component...")
    largest_cc = max(nx.connected_components(G), key=len)
    G_sub = G.subgraph(largest_cc)
    diameter = nx.diameter(G_sub)
    print(f"Diameter of Largest Component: {diameter}")

#Shortest Path (Dijkstra Example)
source = '0'
target = '10'
if nx.has_path(G, source, target):
    path = nx.shortest_path(G, source=source, target=target, method='dijkstra')
    print(f"\nShortest path from {source} to {target}: {path}")
else:
    print(f"\nNo path between {source} and {target}")

# Community Detection (Girvan-Newman)
print("\nCommunity Detection (Girvan-Newman):")
comp = community.girvan_newman(G)
first_level = next(comp)
communities = [list(c) for c in first_level]
for i, c in enumerate(communities[:5]):  # Show only first 5
    print(f"Community {i+1} Size: {len(c)} Nodes")

