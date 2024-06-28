#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<vector<int>> graph;
    int numEdge;
    vector<int> visited;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) {
        graph.resize(numVertices, vector<int>(numVertices, 0));
        visited.resize(numVertices, UNVISITED);
        numEdge = 0;
    }


    int numVertices() {
        return graph.size();
    }

    // Function to get the first adjacent vertex of a given vertex
    int first(int v) {
        for (int i = 0; i < numVertices(); i++) {
            if (graph[v][i] != 0) {
                return i;
            }
        }
        return numVertices();
    }

    // Function to get the next adjacent vertex of a given vertex after a given vertex
    int next(int v, int w) {
        for (int i = w + 1; i < numVertices(); i++) {
            if (graph[v][i] != 0) {
                return i;
            }
        }
        return numVertices();
    }

    bool isEdge(int u, int v) {
        return graph[u][v]!= 0;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        if (graph[u][v] == 0) {
            numEdge++;
        }
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming an undirected graph
    }

    void delEdge(int u, int v) {
        if(graph[u][v] != 0) {
            numEdge--;
        }
        graph[u][v] = 0;
        graph[v][u] = 0; // Assuming an undirected graph
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

    // Post-visit action
    void posVisit(int v) {
        cout << v << " ";
    }

    // Depth-First Search (DFS) algorithm
    // aplications finding the connected components
    void DFS(int start) {
        preVisit(start);
        setMark(start, VISITED);
        int w = first(start);
        while (w < graph.size()) {
            if (getMark(w) == UNVISITED) {
                DFS(w);
            }
            w = next(start, w);
        }
    }

    // Breadth-First Search (BFS) algorithm
    // aplications finding the shortest path
    void BFS(int start) {
        queue<int> Q;
        Q.push(start);
        setMark(start, VISITED);
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            preVisit(v);
            int w = first(v);
            while (w < numVertices()) {
                if (getMark(w) == UNVISITED) {
                    setMark(w, VISITED);
                    Q.push(w);
                }
                w = next(v, w);
            }
        }
    }

    // Traverse the graph using both BFS and DFS
    void graphTraverse(string type, int start) {
        
        if(type == "bfs") {
            resetVisited();
            for (int v = start; v < graph.size(); v++) {
                if (getMark(v) == UNVISITED) {
                    BFS(v);
                }
            }
        } else if(type == "dfs") {
            resetVisited();
            for (int v = start; v < graph.size(); v++) {
                if (getMark(v) == UNVISITED) {
                    DFS(v);
                }
            }
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