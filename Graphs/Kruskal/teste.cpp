#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Edge {
public:
    int u, v, weight;

    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            subsets[i].push_back(i);
        }
    }

    int find(int u) {
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            // Always append the smaller list to the larger one
            if (size[rootU] < size[rootV]) {
                swap(rootU, rootV);
            }

            // Append the list of rootV to rootU
            subsets[rootU].splice(subsets[rootU].end(), subsets[rootV]);

            // Update the parent for all elements in rootV's list
            for (int x : subsets[rootU]) {
                parent[x] = rootU;
            }

            // Update the size
            size[rootU] += size[rootV];
        }
    }

private:
    vector<int> parent;
    vector<int> size;
    vector<list<int>> subsets = vector<list<int>>(parent.size());
};

class Graph {
public:
    Graph(int n) : n(n) {}

    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    vector<Edge> kruskalMST() {
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        vector<Edge> mst;

        for (const auto& edge : edges) {
            if (ds.find(edge.u) != ds.find(edge.v)) {
                ds.unite(edge.u, edge.v);
                mst.push_back(edge);
            }
        }

        return mst;
    }

    void printMST(const vector<Edge>& mst) const {
        cout << "Edges in the MST:" << endl;
        for (const auto& edge : mst) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        }
    }

private:
    int n;
    vector<Edge> edges;
};

int main() {
    int n = 4; // Number of vertices
    Graph g(n);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    vector<Edge> mst = g.kruskalMST();
    g.printMST(mst);

    return 0;
}
