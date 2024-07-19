#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // pair<vertex, weight>
    vector<int> visited;

public:
    Graph(int numVertices) : adjList(numVertices), visited(numVertices, 0) {}

    void setEdge(int u, int v, int w = 1) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    void setVisited(int vertex, int value) {
        visited[vertex] = value;
    }

    int getVisited(int vertex) {
        return visited[vertex];
    }

    int sizeGraph() {
        return adjList.size();
    }

    void Dijkstra(int start, vector<int>& dist, vector<int>& prev) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair<distance, vertex>
        fill(dist.begin(), dist.end(), INT_MAX);
        fill(visited.begin(), visited.end(), 0);
        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            
            if (getVisited(v) == 1) continue;

            setVisited(v, 1);
            for (auto& [next, weight] : adjList[v]) {
                if (getVisited(next) == 0 && dist[next] > dist[v] + weight) {
                    dist[next] = dist[v] + weight;
                    pq.emplace(dist[next], next);
                }
            }
        }
    }

    vector<vector<int>> findComponents() {
        vector<vector<int>> components;
        function<void(int, vector<int>&)> dfs = [&](int v, vector<int>& comp) {
            visited[v] = 1;
            comp.push_back(v);
            for (auto& [next, _] : adjList[v]) {
                if (!visited[next]) {
                    dfs(next, comp);
                }
            }
        };

        for (int i = 0; i < sizeGraph(); ++i) {
            if (!visited[i]) {
                vector<int> comp;
                dfs(i, comp);
                components.push_back(comp);
            }
        }
        return components;
    }

    vector<int> findTerminals(const vector<int>& component) {
        vector<int> degree(sizeGraph(), 0);
        for (int v : component) {
            for (auto& [next, _] : adjList[v]) {
                degree[v]++;
            }
        }
        vector<int> terminals;
        for (int v : component) {
            if (degree[v] != 2) {
                terminals.push_back(v);
            }
        }
        if (terminals.size() < 2) {
            terminals.push_back(component[0]);
            terminals.push_back(component.back());
        }
        sort(terminals.begin(), terminals.end());
        return terminals;
    }

    vector<int> calculateDistances(const vector<int>& terminals) {
        vector<int> distances(terminals.size(), INT_MAX);
        vector<int> dist(sizeGraph(), INT_MAX);
        vector<int> prev(sizeGraph(), -1);

        Dijkstra(terminals[0], dist, prev);
        for (size_t i = 0; i < terminals.size(); ++i) {
            distances[i] = dist[terminals[i]];
        }
        return distances;
    }
};

int main() {
    int caseNum = 0;
    while (true) {
        int N, M;
        cin >> N >> M;
        if (cin.fail()) break;

        Graph graph(N);
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            graph.setEdge(u, v, d);
        }

        vector<vector<int>> components = graph.findComponents();
        vector<pair<int, vector<int>>> lines;

        for (auto& comp : components) {
            vector<int> terminals = graph.findTerminals(comp);
            vector<int> distances = graph.calculateDistances(terminals);
            lines.emplace_back(terminals[0], distances);
        }

        sort(lines.begin(), lines.end());

        cout << "caso " << caseNum++ << endl;
        for (auto& [_, distances] : lines) {
            for (int d : distances) {
                cout << d << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
