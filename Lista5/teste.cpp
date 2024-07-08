#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList;
    map<string, int> distance;

public:
    void setEdge(string a, string b, string c) {
        adjList[a].insert(b);
        adjList[a].insert(c);
        adjList[b].insert(a);
        adjList[b].insert(c);
        adjList[c].insert(a);
        adjList[c].insert(b);

        distance[a] = INF;
        distance[b] = INF;
        distance[c] = INF;
    }

    void BFS(string startNode) {
        queue<pair<int, string>> nodesToVisit;
        nodesToVisit.push({0, startNode});
        distance[startNode] = 0;

        while (!nodesToVisit.empty()) {
            auto [dist, currentNode] = nodesToVisit.front();
            nodesToVisit.pop();

            for (const auto& neighbor : adjList[currentNode]) {
                if (distance[neighbor] == INF) {
                    distance[neighbor] = dist + 1;
                    nodesToVisit.push({dist + 1, neighbor});
                }
            }
        }
    }

    void printDistances() {
        vector<pair<int, string>> results;
        for (const auto& entry : distance) {
            results.emplace_back(entry.second, entry.first);
        }
        stable_sort(results.begin(), results.end());

        cout << results.size() << endl;
        for (const auto& [dist, name] : results) {
            if (dist == INF)
                cout << name << " undefined" << endl;
            else
                cout << name << " " << dist << endl;
        }
    }
};

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numberOfTeams;
        cin >> numberOfTeams;

        Graph graph;

        for (int i = 0; i < numberOfTeams; ++i) {
            string member1, member2, member3;
            cin >> member1 >> member2 >> member3;
            graph.setEdge(member1, member2, member3);
        }

        graph.BFS("Ahmad");
        graph.printDistances();
    }

    return 0;
}
