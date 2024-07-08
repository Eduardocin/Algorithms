#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, weight>
    int V;
    vector<int> visited;

public:
    Graph(int N) : V(N), adjList(N), visited(N, 0) {}

    void setEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    void Dijkstra(int src, vector<int>& D) {
        D.assign(V, INT_MAX);
        D[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist > D[u]) continue;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (D[u] + weight < D[v]) {
                    D[v] = D[u] + weight;
                    pq.emplace(D[v], v);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.setEdge(0, 1, 10);
    g.setEdge(0, 4, 5);
    g.setEdge(1, 2, 1);
    g.setEdge(1, 4, 2);
    g.setEdge(2, 3, 4);
    g.setEdge(3, 4, 3);
    g.setEdge(3, 0, 7);

    vector<int> distances;
    g.Dijkstra(0, distances);

    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from 0 to " << i << " is " << distances[i] << endl;
    }

    return 0;
}