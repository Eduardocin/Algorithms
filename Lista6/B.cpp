#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    unordered_map<string, list<pair<string, int>>> adjList; // <vertex<pair<adj vertex, weight>>>
    unordered_map<string, bool> visited;

public:
    Graph() {}

    void setEdge(string u, string v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    void setVisited(string v) {
        visited[v] = true;
    }

    bool getVisited(string v) {
        return visited[v];
    }

    void Prim(unordered_map<string, int>& MST, unordered_map<string, string>& parent) {
        for (const auto& node : adjList) {
            MST[node.first] = INT_MAX;
            visited[node.first] = false;
        }

        string start = adjList.begin()->first;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;  //<pair<weight, vertex>>

        MST[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            string v = pq.top().second;
            pq.pop();

            if (getVisited(v)) continue;
            setVisited(v);

            for (auto& edge : adjList[v]) {
                string u = edge.first;
                int weight = edge.second;

                if (!getVisited(u) && MST[u] > weight) {
                    MST[u] = weight;
                    parent[u] = v;
                    pq.emplace(weight, u);
                }
            }
        }
    }
};

int main() {
    string centro1, centro2;
    int dist;

    Graph g;
    while (cin >> centro1 >> centro2 >> dist) {
        g.setEdge(centro1, centro2, dist);
    }

    unordered_map<string, int> MST;
    unordered_map<string, string> parent;

    g.Prim(MST, parent);

    int maxDist = 0;
    for (const auto& dist : MST) {
        if (dist.second != INT_MAX) {
            maxDist = max(maxDist, dist.second);
        }
    }

    cout << maxDist << endl;

    return 0;
}
