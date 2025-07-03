import networkx as nx
import matplotlib.pyplot as plt

# Load the graph with integer node labels
G = nx.read_edgelist("facebook_combined.txt", nodetype=int)

# 1. Basic Info
print("Number of nodes:", G.number_of_nodes())
print("Number of edges:", G.number_of_edges())

# 2. Degree Centrality
degree_centrality = nx.degree_centrality(G)
top_deg = sorted(degree_centrality.items(), key=lambda x: x[1], reverse=True)[:5]
print("\nTop 5 Degree Centrality Nodes:")
for node, val in top_deg:
    print(f"Node {node}: {val:.4f}")


# 4. Ego Network Visualization for Node 0
ego_node = 0
ego = nx.ego_graph(G, ego_node)

plt.figure(figsize=(8, 6))
pos = nx.spring_layout(ego)
nx.draw(ego, pos, node_color='lightblue', with_labels=True, node_size=50, edge_color='gray')
nx.draw_networkx_nodes(ego, pos, nodelist=[ego_node], node_color='red', node_size=100)
plt.title(f"Ego Network of Node {ego_node}")
plt.show()
