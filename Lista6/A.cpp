#include <bits/stdc++.h>

using namespace std;

class Graph{
private:
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, weight>
    vector<int> visited;

public:
    Graph(int numNodes): adjList(numNodes), visited(numNodes, 0) {}

    void setEdge(int u, int v, int w){
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int getSize(){
        return adjList.size();
    }

    void setMark(int node, int mark){
        visited[node] = mark;
    }

    int getMark(int node){
        return visited[node];
    }

    void dijkstra(int startNode, vector<int>& dist){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> pq; // pair< weight, pair<currentNode, previousNode>
        pq.emplace(0, make_pair(startNode, startNode));
        dist[startNode] = 0;

        for(int i = 0; i < getSize(); i++){
            int v, p;
            do{
                if(pq.empty()) return;

                auto current = pq.top();
                pq.pop();
                v = current.second.first;
                
                p = current.second.second;

            }while(visited[v] == 1);

            setMark(v, 1);

            for(auto& w : adjList[v]){
                int neighbor = w.first;
                int weight = w.second;

                if(getMark(neighbor) == 0 && dist[neighbor] > dist[v] + weight){
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
        int numServes, numCables;
        cin >> numServes >> numCables;
        
        //create graph with numServes
        Graph g(numServes);

        //servers to find shortest path
        int source, target;
        cin >> source >> target;

        //add connections between servers and cables
        for(int j = 0; j < numCables; j++){
            int server1, server2, cost;
            cin >> server1 >> server2 >> cost;

            g.setEdge(server1, server2, cost);
        }


        //find minimum cost path
        vector<int> dist(numServes, INT_MAX);
        g.dijkstra(source, dist);

        // print min cost
        if(dist[target]!= INT_MAX){
            cout << "Case #" << i+1 << ": " << dist[target] << endl;
        }
        else{
            cout << "Case #" << i+1 << ": unreachable" << endl;
        }

    }

    return 0;
}