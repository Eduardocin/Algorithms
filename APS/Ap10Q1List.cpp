#include <iostream>
#include <vector>
#include <queue>

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

    // // Function to get the first adjacent vertex of a given vertex
    // int first(int v) {
    //     if (!adjList[v].empty()) {
    //         return adjList[v][0]; // Returns the first adjacent vertex
    //     }
    //     return numVertices();// Returns the size of adjacency list if no adjacent vertices
    // }

    //     // Function to get the next adjacent vertex of a given vertex after a given vertex
    // int next(int v, int w) {
    //     auto it = find(adjList[v].begin(), adjList[v].end(), w);
        
    //     if (it != adjList[v].end() && ++it != adjList[v].end()) {
    //         return *it; // Retorna o próximo vértice adjacente
    //     }
    //     return numVertices();// Returns the size of adjacency list if no adjacent vertices
    // }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        auto it_u = lower_bound(adjList[u].begin(), adjList[u].end(), v);
        adjList[u].insert(it_u, v);

        auto it_v = lower_bound(adjList[v].begin(), adjList[v].end(), u);
        adjList[v].insert(it_v, u);

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

    // Pre-visit action
    void preVisit(int v) {
        cout << v << " ";
    }

    // Depth-First Search (DFS) algorithm
    void DFS(int start) {
        preVisit(start);
        setMark(start, VISITED);
        
        for(auto w : adjList[start]){
            if (getMark(w) == UNVISITED) {
                DFS(w);
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
            for(auto i : adjList[v]){
                if (getMark(i) == UNVISITED) {
                    setMark(i, VISITED);
                    Q.push(i);
                }
            }
        }
    }

    // Traverse the graph using either BFS or DFS
    void graphTraverse(string type, int start) {
        resetVisited();


        if (type == "dfs") {
            DFS(start);
            for(int v = 0; v < numVertices(); v++){
                if(getMark(v) == UNVISITED){
                    DFS(v);
                }
            }
        } else if (type == "bfs") {
            BFS(start);
            for(int v = 0; v < numVertices(); v++){
                if(getMark(v) == UNVISITED){
                    BFS(v);
                }
            }
        }
        cout << endl; // Added to separate outputs of different traversals
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
        } else if (command == "DFS") {
            int v;
            cin >> v;
            g.graphTraverse("dfs", v);
        }
    }

    return 0;
}
