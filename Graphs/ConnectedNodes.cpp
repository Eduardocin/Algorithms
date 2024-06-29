#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> graph;
    int numEdge;

public:
    Graph(int size) : numEdge(0) {
        graph.resize(size);
    }

    void addEdge(int source, int destination) {
        graph[source].push_back(destination);
        graph[destination].push_back(source);
        numEdge++;
    }

    bool findConnection(int source, int destination) {
        for (int i : graph[source]) {
            if (i == destination) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int nodes, edges, source, destination, queries;

    cin >> nodes >> edges;

    Graph* graph = new Graph(nodes);

    for (int i = 0; i < edges; i++) {
        cin >> source >> destination;
        graph->addEdge(source - 1, destination - 1); // Adjusting for 0-based indexing
    }

    // Check if there exists a connection between two nodes
    cin >> queries;
    for (int i = 0; i < queries; i++) {
        cin >> source >> destination;
        
        if (graph->findConnection(source - 1, destination - 1)) { // Adjusting for 0-based indexing
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    delete graph;
    return 0;
}
