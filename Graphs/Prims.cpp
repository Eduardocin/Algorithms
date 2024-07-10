#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<pair<int,int>>> adjList; // <pair<node,weight>>
    vector<int> visited;


public:
    Graph(int numNodes): adjList(numNodes), visited(numNodes, 0) {}


    void setEdge(int a, int b, int w){
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    int getSize(){
        return adjList.size();
    }

    void Prim(vector<int>& dist, vector<int>& parent){
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq; //pair< weight, pair<current vertex , previous vertex>>

        pq.emplace(0, make_pair(0, 0));
        dist[0] = 0;

        for(int i = 0 ; i < getSize(); ++i){
            int p, v;
            do{
                if(pq.empty()) return;
                
                auto temp = pq.top();
                pq.pop();
                p = temp.second.second; //previous vertex
                v = temp.second.first; // current vertex

            }while(visited[v] == 1);

            parent[v] = p;
            visited[v] = 1;

            for(auto &it : adjList[v]){
                int u = it.first;
                int weight = it.second;

                if(visited[u] == 0 && dist[u] > weight){
                        dist[u] = weight;
                        pq.emplace(weight, make_pair(u, v));
                }
            }
        }
    }



}; 

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g.setEdge(a, b, w);
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    g.Prim(dist, parent);

    int MST = accumulate(dist.begin(), dist.end(), 0);

    cout << MST << endl;
    
    return 0;
}