#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<list<int>> graph;
    int numEdge;
    vector<int> visited;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) {
        graph.resize(numVertices);
        visited.resize(numVertices, UNVISITED);
        numEdge = 0;
    }

    int numVertices() {
        return graph.size();
    }

    int numEdges() {
        return numEdge;
    }

    // Function to get the first adjacent vertex of a given vertex
    list<int>::iterator first(int v) {
        return graph[v].begin();
    }

    // Function to get the next adjacent vertex of a given vertex after a given vertex
    list<int>::iterator next(int v, list<int>::iterator it) {
        return ++it;
    }

    bool isEdge(int u, int v) {
        for (int neighbor : graph[u]) {
            if (neighbor == v) {
                return true;
            }
        }
        return false;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        if (!isEdge(u, v)) {
            numEdge++;
            graph[u].push_back(v);
            graph[v].push_back(u); // Assuming an undirected graph
        }
    }

    void delEdge(int u, int v) {
        graph[u].remove(v);
        graph[v].remove(u);
        numEdge--;
    }

    // Function to set the mark of a vertex
    void setMark(int v, int value) {
        visited[v] = value;
    }

    // Function to get the mark of a vertex
    int getMark(int v) {
        return visited[v];
    }

    // Pre-visit action
    void preVisit(int v) {
        cout << v << " ";
    }

    // Depth-First Search (DFS) algorithm
    void DFS(int start) {
        preVisit(start);
        setMark(start, VISITED);
        for (auto it = first(start); it != graph[start].end(); it = next(start, it)) {
            if (getMark(*it) == UNVISITED) {
                DFS(*it);
            }
        }
    }

    // Breadth-First Search (BFS) algorithm
    void BFS(int start) {
        queue<int> Q;
        Q.push(start);
        setMark(start, VISITED);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            preVisit(v);
            for (auto it = first(v); it != graph[v].end(); it = next(v, it)) {
                if (getMark(*it) == UNVISITED) {
                    setMark(*it, VISITED);
                    Q.push(*it);
                }
            }
        }
    }

    // Traverse the graph using both BFS and DFS
    void graphTraverse(string type, int start) {
        if (type == "bfs") {
            resetVisited();
            BFS(start);
        } else if (type == "dfs") {
            resetVisited();
            DFS(start);
        }
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
        string command;
        cin >> command;

        if (command == "add") {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        } else if (command == "BFS") {
            int v;
            cin >> v;
            g.graphTraverse("bfs", v);
            cout << endl;
        } else if (command == "DFS") {
            int v;
            cin >> v;
            g.graphTraverse("dfs", v);
            cout << endl;
        }
    }

    return 0;
}