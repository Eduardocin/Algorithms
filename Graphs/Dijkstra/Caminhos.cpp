#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<pair<int, int>>> adjList; // pair<int, int> = {destination, weight}
    int numEdges;
    vector<int> visited;
public:
    Graph(int numVertices): adjList(numVertices), numEdges(0), visited(numVertices, 0) {}

    void setEdge(int v1, int v2, int weight){
        adjList[v1].push_back({v2, weight});
        numEdges ++;
    }

    int getSize(){
        return adjList.size();
    }

    void Dijkstra(int startVertex, vector<int>& dist, vector<int>& prev){
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq; // <pair<weight, {vertex, previous vertex} >>>
        
        pq.emplace(0, make_pair(startVertex, startVertex));
        dist[startVertex] = 0;

        for(int i = 0; i < getSize(); i++){
            int p, v;

            do{
                if(pq.empty()) return;

                auto current = pq.top();
                pq.pop();
                v = current.second.first;
                p = current.second.second;

            }while(visited[v] == 1);


            visited[v] = 1;
            prev[v] = p;

            for(auto &edges : adjList[v]){
                int neighbor = edges.first;
                int weight = edges.second;

                if(visited[neighbor] == 0 && dist[neighbor] > dist[v] + weight){
                    dist[neighbor] = dist[v] + weight;
                    pq.emplace(dist[neighbor], make_pair(neighbor, v));
                }
            }
        }
    }

};





int main(){
    int numCases;

    cin >> numCases;

    for(int i = 0; i < numCases; i++){
        int numVertices, numEdges;
        cin >> numVertices >> numEdges;

        Graph g(numVertices);

        for(int j = 0; j < numEdges; j++){
            int edge1, edge2, weight;
            cin >> edge1 >> edge2 >> weight;

            g.setEdge(edge1, edge2, weight);
        }

        int startVertex;    
        cin >> startVertex;

        vector<int> dist(numVertices, INT_MAX);
        vector<int> prev(numVertices, -1);
        g.Dijkstra(startVertex, dist, prev);



        // print the shortest path
        cout << "Caso " << i + 1 << endl;
        for(int i = 0; i < numVertices; i++){
            if(dist[i] == INT_MAX){
                cout << -1 << endl;
            }
            else{
            cout << dist[i] << endl;
            }
        }

    }
    
    return 0;
}