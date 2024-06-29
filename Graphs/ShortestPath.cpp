//graph shortest path
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    int numEdges;
    vector<int> Mark;
    vector<int> Path;

public:
    Graph(int numNodes) : adj(numNodes), numEdges(0), Mark(numNodes), Path(numNodes,-1){}

    void setMark(int u, int v) {
        Mark[u] = v;
    }

    int numNodes() {
        return adj.size();
    }

    int NumEdges() {
        return numEdges;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        numEdges++;
    }

    void printGraph() const {
        for (size_t i = 0; i < adj.size(); i++) {
            cout << i << ": ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void ShortestPath(int start, int target) {
        queue<int> q;
        q.push(start);
        setMark(start, 1);


        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int neighbor : adj[v]) {
                if (Mark[neighbor] == 0) {
                    setMark(neighbor, 1);
                    Path[neighbor] = v;
                    q.push(neighbor);
                    if (neighbor == target) {
                        return;
                    }
                }
            }
        }
    }

    void printPath(int start, int target) const {
        stack<int> s;
        int current = target;

        while (current != start) {
            s.push(current);
            current = Path[current];
        }
        s.push(start);

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void graphTraverse(int start, int target) {
        
        for (size_t i = 0; i < Mark.size(); i++) {
            setMark(i, 0);
        }
        for(size_t i = 0; i < Path.size(); i++) {
            Path[i] = -1;
        }

        ShortestPath(start, target);

        //cheack if there is a path
        if (Mark[target] == 0) {
            cout << "There is no path from " << start << " to " << target << endl;
            return;
        }
    
        cout << "Shortest path from " << start << " to " << target << ": ";
        printPath(start, target);
        
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    int start = 0;
    int target = 1;
    g.graphTraverse(start, target);

    return 0;
}