#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int numEdges;
    vector<int> visited;

public:
    Graph(int n) {
        adjList.resize(n);
        visited.resize(n, 0);
        numEdges = 0;
    }

    bool checkEdge(int s, int d) {
        return (find(adjList[s].begin(), adjList[s].end(), d) != adjList[s].end());
    }

    void setEdge(int s, int d) {
        if (checkEdge(s, d)) return;

        adjList[s].push_back(d);
        adjList[d].push_back(s);
        numEdges++;
    }

    void ShortestPath(int source, int target, vector<int>& path) {
        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int neighbour : adjList[v]) {
                if (visited[neighbour] == 0) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                    path[neighbour] = v;
                    if (neighbour == target) {
                        return;
                    }
                }
            }
        }
    }

    void graphTraversal(string type, int source, int target = 0) {
        for (size_t i = 0; i < visited.size(); i++) {
            visited[i] = 0;
        }

        if (type == "Shortest Path") {
            vector<int> path(adjList.size(), -1);
            stack<int> s;
            
            for(size_t i = 0; i < adjList.size(); i++) {
                if(visited[i] == 0){
                ShortestPath(source, target, path);
                }
            }


            if (path[target] == -1) {
                cout << "There is no path from " << source << " to " << target << endl;
                return;
            } else {
                int current = target;
                while (current != -1) {
                    s.push(current);
                    current = path[current];
                }

                while (!s.empty()) {
                    cout << s.top() << " ";
                    s.pop();
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(6); // Example graph with 6 vertices

    // Example edges
    g.setEdge(0, 1);
    g.setEdge(1, 3);
    g.setEdge(2, 4);
    g.setEdge(4, 5);

    // Finding shortest path from vertex 0 to vertex 5
    cout << "Shortest path from 0 to 5: ";
    g.graphTraversal("Shortest Path", 0, 5);

    return 0;
}
