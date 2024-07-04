#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;
class Graph {
private:
    vector<vector<int> > adj;
    vector<int> visited;
public:
    Graph(int numNodes): adj(numNodes + +1), visited(numNodes +1, 0) {}


    void setEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void setMark(int node, int mark){
        visited[node] = mark;
    }

    int getmark(int node){
        return visited[node];
    }

    void BFS(int startNode, vector<int> &level){
        queue<int> q;
        q.push(startNode);
        setMark(startNode, 1);
        level[startNode] = 1;  // Start from level 1


        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int w: adj[v]){
                if(getmark(w) == 0){
                    setMark(w, 1);
                    q.push(w);
                    level[w] = level[v] + 1;
                }
            }
        }
    }
    
    void graphTraversal(vector<int>& level){
        
        for(int i = 0; i < visited.size(); i++){
            setMark(i, 0);
        }

        for(int v = 1; v < visited.size(); v++){
            if(getmark(v) == 0){
                BFS(v, level);
            }
        }

    }

};

int main(){
    int NumberOfNodes;
    cin >> NumberOfNodes;

    Graph g(NumberOfNodes);
    for(int i = 0; i < NumberOfNodes - 1; i++){
        int u, v;
        cin >> u >> v;
        g.setEdge(u, v);
    }

    int countNodesinLevel;
    cin >> countNodesinLevel;

    vector<int> level(NumberOfNodes + 1, 0);
    g.graphTraversal(level);

    cout << count(level.begin(), level.end(), countNodesinLevel) << endl;

    return 0;
}