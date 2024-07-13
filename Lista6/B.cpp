#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<list<pair<int, int>>> adjList; // <pair<vertex, weight>>
    vector<int> visited;

public:
    Graph(int numVertices): adjList(numVertices), visited(numVertices, 0) {}

    void setEdge(int u, int v, int w){
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int getSize(){
        return adjList.size();
    }

    void setMark(int u, int mark){
        visited[u] = mark;
    }

    int getMark(int u){
        return visited[u];
    }

    void Prim(int start, vector<int>& dist, vector<int>& parent){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // pair<weight, pair<vertex, parent>>

        pq.emplace(0, make_pair(start, start));
        dist[start] = 0;

        for(int i = 0; i < getSize(); i++){
            int p, v;

            do{
                if(pq.empty()){
                    return;
                }

                auto current = pq.top();
                pq.pop();

                v = current.second.first;
                p = current.second.second;

            } while(getMark(v) == 1);

            setMark(v, 1);
            parent[v] = p;

            for(auto& neighbour: adjList[v]){
                int w = neighbour.first;
                int weight = neighbour.second;

                if(getMark(w) == 0 && dist[w] > weight){
                    dist[w] = weight;
                    pq.emplace(weight, make_pair(w, v));
                }
            }
        }
    }
};

int main(){
    int numCities, numRoads;

    while(cin >> numCities >> numRoads && (numCities != 0 || numRoads != 0)) {
        Graph g(numCities);

        for(int i = 0; i < numRoads; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g.setEdge(u, v, w);
        }

        vector<int> dist(numCities, INT_MAX);
        vector<int> parent(numCities, -1);
        g.Prim(0, dist, parent);

            // Check if it's possible to travel between all cities
        if(find(dist.begin(), dist.end(), INT_MAX) != dist.end()){
            cout << "IMPOSSIBLE" << endl;
        } else {
            // Find minimum range  to travel between any two cities
            int maxRange = *max_element(dist.begin(), dist.end());
            cout << maxRange << endl;
        }
    }

    return 0;
}
