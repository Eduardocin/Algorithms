#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    struct DijointsSubsets {
        vector<int> parent;

        DijointsSubsets(int n) {
            parent.resize(n);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }

        int find(int curr) {
            if (parent[curr] == curr) {
                return curr;
            }
            parent[curr] = find(parent[curr]);
            return parent[curr];
        }

        void unionSets(int a, int b) {
            int root1 = find(a);
            int root2 = find(b);
            if (root1 != root2) {
                parent[root2] = root1;
            }
        }
    };

    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) : adjList(V) {}

    void setEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    void Kruskal() {
        vector<tuple<int, int, int>> edges;

        // Collect all edges
        for (int i = 0; i < adjList.size(); i++) {
            for (auto& edge : adjList[i]) {
                if (i < edge.first) {
                    edges.push_back(make_tuple(edge.second, i, edge.first));
                }
            }
        }

        // Create a min-heap from the edges
        auto heapBottomUp = [](vector<tuple<int, int, int>>& H) {
            make_heap(H.begin(), H.end(), greater<tuple<int, int, int>>());
        };
        heapBottomUp(edges);

        // Create disjoint subsets
        DijointsSubsets ds(adjList.size());
        vector<tuple<int, int, int>> MSTEdges;


        int numMst = adjList.size();
        // Process edges in the min-heap
        while (numMst > 1) {
            pop_heap(edges.begin(), edges.end(), greater<tuple<int, int, int>>());
            auto [wt, v, u] = edges.back();
            edges.pop_back();

            if (ds.find(v) != ds.find(u)) {
                ds.unionSets(v, u);
                MSTEdges.push_back(make_tuple(wt, v, u));
                --numMst;
            }
        }

        // Find MST sum of weights
        int MSTSum = 0;
        for (auto& [wt, v, u] : MSTEdges) {
            MSTSum += wt;
        }
        cout << MSTSum << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g.setEdge(a, b, w);
    }

    g.Kruskal();

    return 0;
}