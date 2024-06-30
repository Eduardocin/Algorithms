//graph shortest path
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adj;
    int numEdges;
    vector<int> Mark;

public:
    Graph(int numNodes): adj(numNodes), numEdges(0), Mark(numNodes, 0) {}

    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        numEdges++;
    }

    void DFS(int v){
        Mark[v] = 1;
        
        for(int i : adj[v]) {
            if(Mark[i] == 0) {
                DFS(i);
            }
        }
    
    }

    void CheckConnected(int value){
        if(value >= 1){
            cout << "Connected" << endl;
            cout << "number of components: " << value << endl;
        }
        else{
            cout << "Not Connected" << endl;
        }
    }


    void graphTraverse(){
        for(size_t i = 0;  i < Mark.size(); i++) {
            Mark[i] = 0;
    
        }

        int numComponents = 0;
        for(size_t i = 0; i < adj.size(); i++) {
            if(Mark[i] == 0) {
                DFS(i);
                numComponents++;
            }
        }

        CheckConnected(numComponents);
        return;
    }
    

};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.graphTraverse();

    return 0;
}