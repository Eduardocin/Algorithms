#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Graph{
private:
    vector<vector<int>> adjList;
    int numEdges;
    vector<int> visited;

public:
    Graph(int numNodes): adjList(numNodes), numEdges(0), visited(numNodes, 0){}




    bool checkEdge(int s,  int v){
        return (adjList[s].end()!= find(adjList[s].begin(), adjList[s].end(), v));
    }

    //add a edge to a DAG
    void addEdge(int s, int v){
        if(checkEdge(s, v)) return;

        adjList[s].emplace_back(v);
        numEdges++;
    }
    
    void delEdge(int s, int v){
        
        if(!checkEdge(s, v)) return;

        // criar um ponteiro para o elemento a ser removido
        auto it = find(adjList[s].begin(), adjList[s].end(), v);
        adjList[s].erase(it);
        numEdges--;
    }

    void setMark(int v, int mark){
        visited[v] = mark;
    }

    void topoSort(int v, stack<int>& stk){

        setMark(v, 1);
        for(int neighbour : adjList[v]){
            if(visited[neighbour] == 0){
                topoSort(neighbour, stk);
            }
        }
        stk.push(v);
    }

    void graphTraverse(string command , stack<int>& stk){
        //preencher o vetor de visitados
        for(size_t i = 0; i < visited.size(); i++){
            visited[i] = 0;
        }


        if(command == "topoSort"){
            //percorrer o grafo
            for(size_t i = 0; i < adjList.size(); i++){
                if(visited[i] == 0){
                    topoSort(i, stk);
                }
            }
        }
    }
};


int main(){
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    Graph g(numNodes);

    for(int i = 0; i < numEdges; i++){
        int sourc, dest;
        cin >> sourc >> dest;
        g.addEdge(sourc, dest); 
    }

    stack<int> stk;
    g.graphTraverse("topoSort", stk);

    // print topological sort
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    return 0;
}
