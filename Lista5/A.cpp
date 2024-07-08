#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    map<string, unordered_set<string>> adjList; 
    map<string, int> distances;

public:
    Graph() {}

    void SetEdge(string a, string b, string c) {
        adjList[a].insert(b);
        adjList[a].insert(c);
        adjList[b].insert(a);
        adjList[b].insert(c);
        adjList[c].insert(a);
        adjList[c].insert(b);

        distances[a] = INT_MAX;
        distances[b] = INT_MAX;
        distances[c] = INT_MAX;
    }

    void BFS(string startNode) {
        queue<pair<string, int>> visitedNodes;
        visitedNodes.push({startNode, 0});
        distances[startNode] = 0;

        while (!visitedNodes.empty()) {
            pair<string, int> currentNode = visitedNodes.front();
            visitedNodes.pop();

            for (auto neighbor : adjList[currentNode.first]) {
                if (distances[neighbor] == INT_MAX) {
                    distances[neighbor] = currentNode.second + 1;
                    visitedNodes.push({neighbor, distances[neighbor]});
                }
            }
        }
    }

    void printDistances() {
        vector<pair<int, string>> sortedDistances;

        for (const auto& entry : distances) {
            sortedDistances.emplace_back(entry.second, entry.first);
        }

        sort(sortedDistances.begin(), sortedDistances.end());


        cout << sortedDistances.size() << endl;
        for (const auto& pair : sortedDistances) {
            if (pair.first == INT_MAX) {
                cout << pair.second << " undefined" << endl;
            } else {
                cout << pair.second << " " << pair.first << endl;
            }
        }
    }
};

int main() {
    int numCases;
    cin >> numCases;

    while (numCases--) {
        int numTeams;
        cin >> numTeams;

        Graph g;

        for (int i = 0; i < numTeams; i++) {
            string m1, m2, m3;
            cin >> m1 >> m2 >> m3;

            g.SetEdge(m1, m2, m3);
        }

        g.BFS("Ahmad");
        g.printDistances();
    }

    return 0;
}
