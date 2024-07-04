#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> dependence;

public:
    Graph(int numNodes) : adjList(numNodes), dependence(numNodes, 0) {}

    void setEdge(int u, int v) {
        adjList[u].push_back(v);
        dependence[v]++;
    }

    bool topoSort(vector<int>& result) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < dependence.size(); i++) {
            if (dependence[i] == 0) {
                pq.push(i);
            }
        }

        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();
            result.push_back(node);

            for (int neighbor : adjList[node]) {
                dependence[neighbor]--;
                if (dependence[neighbor] == 0) {
                    pq.push(neighbor);
                }
            }
        }

        //check if Sandro Fails
        return result.size() == adjList.size();
    }
};

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    Graph graph(numNodes);

    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        cin >> source >> destination;
        graph.setEdge(source - 1, destination - 1);
    }

    vector<int> result;
    if (graph.topoSort(result)) {
        for (int i : result) {
            cout << i + 1 << " "; 
        }
        cout << endl;
    } else {
        cout << "Sandro fails." << endl;
    }

    return 0;
}
