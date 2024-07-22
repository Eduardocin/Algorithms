#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<pair<int,int>>> adjList; // pair<neighbor, weight>
    vector<int> visited; // 1 for visited, 0 for not visited

public:
    Graph(int V): adjList(V), visited(V, 0) {}

    void setEdge(int u, int v, int w){
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); 
    }

    void Prim(vector<int>& dist, vector<int>& parent){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq; // pair<weight, pair<vecter, previous vertex>

        pq.push({0, {0, 0}});
        dist[0] = 0;

        for(int i = 0; i < adjList.size(); i++){
            int p, v; // previous vertex and current vertex

            do{
                if(pq.empty()) return; // graph is disconnected
                
                p = pq.top().second.second;
                v = pq.top().second.first;
                pq.pop();

            }while(visited[v] == 1);

            visited[v] = 1;
            parent[v] = p;

            for(auto& neighbor : adjList[v]){
                int weight = neighbor.second;
                int neighborVertex = neighbor.first;
                
                if(visited[neighborVertex] == 0 && weight < dist[neighborVertex]){
                    dist[neighborVertex] = weight;
                    pq.push({weight, {neighborVertex, v}});
                }
            }
        }
    }
};




int main() {
    int NumNode, NumEdge;
    cin >> NumNode >> NumEdge;

    Graph g(NumNode);

    for(int i = 0; i < NumEdge; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g.setEdge(u - 1, v - 1, w);
    }
    
    int start;
    cin >> start;

    vector<int> dist(NumNode, INT_MAX);
    vector<int> parent(NumNode, -1);
    
    g.Prim(dist, parent);

    int totalCost = 0 ;
    totalCost = accumulate(dist.begin(), dist.end(), 0);
    cout << totalCost << endl;


    return 0;
}