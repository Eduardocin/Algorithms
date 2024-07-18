#include <bits/stdc++.h>


using namespace std;


class Graph{
private:
    vector<vector<pair<int,int>>> adjList; // pair<vertex, weight>
    vector<int> visited;

public:
    Graph(int numVertices): adjList(numVertices), visited(numVertices, 0) {}


    void SetEdge(int u, int v, int w = 1){
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }


    void setVisited(int vertex, int value){
        visited[vertex] = value;
    }

    int getVisited(int vertex){
        return visited[vertex];
    }

    int sizeGraph(){
        return adjList.size();
    }

    void Dijkstra(int start, vector<int>& dist, vector<int>& prev){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int, int>>>> pq; // pair<weight, pair<vertex, previous>>


        pq.emplace(0, make_pair(start, start));
        dist[start] = 0;

        for(int i = 0; i < sizeGraph(); i++){
            int v, p;

            do{
                if(pq.empty()) return;
                auto node = pq.top();
                pq.pop();

                v = node.second.first;
                p = node.second.second;

            }while(getVisited(v) == 1);
    

            setVisited(v, 1);
            prev[v] = p;

            for(auto& w : adjList[v]){
                int vertex = w.first;
                int weight = w.second;
                if(getVisited(vertex) == 0 && dist[vertex] > dist[v] + weight){ 
                    dist[vertex] = dist[v] + weight;
                    pq.emplace(dist[vertex], make_pair(vertex, v));
                }
            }
        }
    }

};