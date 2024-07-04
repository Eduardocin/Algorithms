#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Graph{
private:
    vector<vector<int>> adjList;
    int NumEdges;
    vector<int> visited;

public: 
    Graph(int numNodes): adjList(numNodes), NumEdges(0), visited(numNodes, 0){}


    void setEdge(int i, int j){
        adjList[i].push_back(j);
        adjList[j].push_back(i);
        NumEdges++;
    }

    void setMark(int node, int mark){
        visited[node] = mark;
    }

    int getMark(int node){
        return visited[node];
    }

    void BFS(int startNode, int destNode, vector<int> &Path){
        queue<int> q;
        q.push(startNode);
        setMark(startNode, 1);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int w : adjList[node]){
                if(getMark(w) == 0 )
                {
                    q.push(w);
                    setMark(w, 1);
                    Path[w] = node;
                    if(w == destNode){
                        return;
                    }
                }
            }
        }
    }

    int getNode(){
        return adjList.size();
    }


    void ShortestPath(int start, int destNode){
        stack<int> s;
        vector<int> Path(getNode(), -1);
        
        for(int i =0; i < getNode(); i++){
            setMark(i, 0);
            Path[i] = -1;
        }

        BFS(start, destNode, Path);

        //check if path exists
        if(getMark(destNode) == 0){
            cout << -1 << endl;
        }
        else{
            int node = destNode;
            while(node != -1){
                s.push(node);
                node = Path[node];
            }

            while(!s.empty()){
                cout << s.top();
                s.pop();
                if(!s.empty()){
                    cout << " -> ";
                }
            }
            cout << endl;
        }



    }


};


int main() {
    Graph g(6);
    g.setEdge(0, 2);
    g.setEdge(0, 4);
    g.setEdge(1, 2);
    g.setEdge(1, 5);
    g.setEdge(2, 3);
    g.setEdge(2, 5);
    g.setEdge(3, 5);
    g.setEdge(4, 5);

    int start = 0;
    int target = 1;
    g.ShortestPath(start, target);

    return 0;
}