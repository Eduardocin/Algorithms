#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph{
private:
    vector<list<int>> adjList;
    vector<int> visited;

public:

    Graph(int numNodes): adjList(numNodes), visited(numNodes, 0) {}

    void setEdge(int src, int dest){
        adjList[src].push_front(dest);
        adjList[dest].push_front(src);
    }


    void setMarked(int src, int val){
        visited[src] = val;
    }

    int getMarked(int src){
        return visited[src];
    }

    void DFS(int src){
        cout << src << " ";
        setMarked(src, 1);

        for(int neighbor : adjList[src]){
            if(getMarked(neighbor) == 0){
                DFS(neighbor);
            }
        }
        
    }

    int numNodes(){
        return adjList.size();
    }

    void graphTraversal(){
        for(int i = 0; i < numNodes(); i++){
                setMarked(i, 0);
            }

            DFS(0);
    }

    


    void printGraph(){
        for(int i = 0; i < numNodes(); i++){
            cout << i << ": ";
                
                if(adjList[i].empty()){
                    cout << "Lista Vazia";
                }
                else{
                    for(int w : adjList[i]){
                        cout << w << " ";
                    }
                }
            
            cout << endl;
            }
        }
    

};



int main(){

    int numNodes;
    cin >> numNodes;

    Graph g(numNodes);

    int src, dest, flag;
    while(cin >> src >> dest >> flag){
        g.setEdge(src, dest);
        if(flag == 0){
            break;
        }
    }


    g.printGraph();
    cout << endl;
    g.graphTraversal();


    return 0;
}