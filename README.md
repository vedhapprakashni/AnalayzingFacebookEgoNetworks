This project focuses on analyzing Facebook ego networks to gain insights into user connections, community structures, and network behaviors. Ego networks consist of a central user ("ego") and all the nodes they are directly connected to ("alters"), along with connections among the alters.

The main objectives of this project are:

Visualizing ego networks

Identifying community structures using clustering algorithms

Calculating key network metrics (e.g., degree, betweenness centrality)

Detecting influential nodes

Exploring network evolution and patterns


Dataset:

The dataset used in this project is the Facebook Ego Network dataset from the SNAP (Stanford Network Analysis Project).
The contents are already saved in the faceboob_combined.text file.

Tools & Technologies used: 

Python and C,
NetworkX for graph analysis,
Matplotlib / Plotly for visualization,
Pandas and NumPy for data manipulation,
Gephi / Graph-tool for interactive network visualization,

Tasks Performed:

  Data Preprocessing
  
  Reading and parsing .edges and .feat files
  
  Constructing graphs using NetworkX
  
  Network Analysis
  
  Degree distribution
  
  Centrality measures (degree, closeness, betweenness, eigenvector)
  
  Clustering coefficient
  
  Community detection using Girvan–Newman method
  
  Visualization-Plotting ego networks with color-coded communities
  
  Highlighting influential nodes and hubs.
  

Steps to Run:

1.Clone the repository
git clone https://github.com/vedhapprakashni/AnalayzingFacebookEgoNetworks.git
cd facebook-ego-network-analysis

2.Create a virtual environment
python -m venv venv
venv\Scripts\activate

3.Run the main script
python analyze_ego_network.py

4.Compile and run the C file
gcc sna.c -o sna
./sna



