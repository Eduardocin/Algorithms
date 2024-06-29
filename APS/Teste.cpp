#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm> // Inclua este cabeçalho para std::find

using namespace std;

#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<vector<int>> adjList;
    int numEdge;
    vector<int> visited;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) {
        adjList.resize(numVertices);
        visited.resize(numVertices, UNVISITED);
        numEdge = 0;
    }

    int numVertices() {
        return adjList.size();
    }

    // Function to get the first adjacent vertex of a given vertex
    int first(int v) {
        if (!adjList[v].empty()) {
            return adjList[v][0]; // Returns the first adjacent vertex
        }
        return numVertices(); // Returns the size of adjacency list if no adjacent vertices
    }

    // Function to get the next adjacent vertex of a given vertex after a given vertex
    int next(int v, int w) {
        auto it = find(adjList[v].begin(), adjList[v].end(), w);

        if (it != adjList[v].end() && ++it != adjList[v].end()) {
            return *it; // Returns the next adjacent vertex
        }
        return numVertices(); // Returns the size of adjacency list if no adjacent vertices
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        auto it_u = lower_bound(adjList[u].begin(), adjList[u].end(), v);
        adjList[u].insert(it_u, v);
        numEdge++;
    }

    // Function to set the mark of a vertex
    void setMark(int v, int value) {
        visited[v] = value;
    }

    // Function to get the mark of a vertex
    int getMark(int v) {
        return visited[v];
    }

    void topologicalSort(int v, stack<int>& S) {
        setMark(v, VISITED);
        for (int w : adjList[v]) {
            if (getMark(w) == UNVISITED) {
                topologicalSort(w, S);
            }
        }
        S.push(v);
    }

    // Reset visited array
    void resetVisited() {
        fill(visited.begin(), visited.end(), UNVISITED);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Graph g(n);

    for (int i = 0; i < q; i++) {
        int s, d;
        cin >> s >> d;
        g.addEdge(s, d);
    }

    stack<int> S;
    g.resetVisited(); // Reset visited before topological sort
    for (int i = 0; i < n; i++) {
        if (g.getMark(i) == UNVISITED) {
            g.topologicalSort(i, S);
        }
    }

    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }

    return 0;
}