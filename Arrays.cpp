#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

#define UNVISITED 0
#define VISITED 1

class Graph {
private:
    vector<vector<int>> graph;
    int edgeCount; // Renamed to avoid conflict with numEdges() method
    vector<int> visited;

public:
    Graph(int numVertices){
        graph.resize(numVertices, vector<int>(numVertices, 0));
        visited.resize(numVertices, UNVISITED);
        edgeCount = 0;
    }

    void addEdge(int i, int j){
        if (graph[i][j] == 0) {
            edgeCount++;
        }
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    void delEdge(int i, int j){
        if (graph[i][j] == 1) {
            edgeCount--;
        }
        graph[i][j] = 0;
        graph[j][i] = 0;
    }

    int numVertices(){
        return graph.size();
    }

    int numEdges(){
        return edgeCount;
    }

    int first(int v){
        for (int i = 0; i < numVertices(); i++) {
            if (graph[v][i] == 1) {
                return i;
            }
        }
        return numVertices();
    }

    int next(int v, int w){
        for (int i = w + 1; i < numVertices(); i++) {
            if (graph[v][i] == 1) {
                return i;
            }
        }
        return numVertices();
    }

    bool isEdge(int i, int j){
        return graph[i][j] == 1;
    }

    void setMark(int v, int value){
        visited[v] = value;
    }

    int getMark(int v){
        return visited[v];
    }

    void resetVisited(){
        fill(visited.begin(), visited.end(), UNVISITED);
    }

    void preVisit(int v){
        cout << v << " ";
    }

    void posVisit(int v){
        cout << v << " ";
    }

    void DFS(int start){
        preVisit(start);
        setMark(start, VISITED);
        int w = first(start);
        while (w < numVertices()) {
            if (getMark(w) == UNVISITED) {
                DFS(w);
            }
            w = next(start, w);
        }
    }

    void BFS(int start){
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

    void graphTraverse(const string& type, int start){
        if (type == "bfs") {
            resetVisited();
            for (int v = start; v < graph.size(); v++) {
                if (getMark(v) == UNVISITED) {
                    BFS(v);
                }
            }
        } else if (type == "dfs") {
            resetVisited();
            for (int v = start; v < graph.size(); v++) {
                if (getMark(v) == UNVISITED) {
                    DFS(v);
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    
    string type = "dfs";
    g.graphTraverse(type, 0);
    
    return 0;
}
