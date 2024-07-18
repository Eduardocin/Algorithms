#include <bits/stdc++.h>
using namespace std;

// Define DisjointSet base class
class DisjointSet {
protected:
    vector<int> parent, size;

public:
    // Constructor to initialize the disjoint set with n elements
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set containing element curr
    int find(int curr) {
        if (curr == parent[curr]) {
            return parent[curr]; // Path compression
        }
        else{
            parent[curr] = find(parent[curr]); // Path compression
            return parent[curr]; 
        }
    }

    void join(int a, int b) {
        int a = find(a);
        int b = find(b);

        parent[a] = b;
    }

};

// Define Graph class that inherits from DisjointSet
class Graph : public DisjointSet {
private:
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // (weight, u, v)

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) : DisjointSet(V), V(V) {}

    // Function to add an edge
    void addEdge(int u, int v, int weight) {
        edges.push_back(make_tuple(weight, u, v));
    }

    // Function to implement Kruskal's algorithm
    void kruskalMST() {
        // Sort edges by weight
        sort(edges.begin(), edges.end());

        vector<tuple<int, int, int>> mst; // To store the edges of the MST

        for (auto &edge : edges) {
            int weight, u, v;
            tie(weight, u, v) = edge;

            // If u and v are in different sets, include this edge in the MST
            if (find(u) != find(v)) {
                join(u, v);
                mst.push_back(edge);
            }
        }

        // Print the edges of the MST
        int totalWeight = 0;
        for (auto &edge : mst) {
            int weight, u, v;
            tie(weight, u, v) = edge;
            cout << "Edge: " << u << " - " << v << " with weight: " << weight << endl;
            totalWeight += weight;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V = 4;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
