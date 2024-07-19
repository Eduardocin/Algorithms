#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // pair<vertex, weight>
    vector<int> visited;

public:
    Graph(int V) : adjList(V), visited(V, 0) {}

    void setEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    void Dijkstra(int start, vector<int>& dist, vector<int>& prev) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // pair<cost, pair<vertex, previous vertex>>
        
        pq.emplace(0, make_pair(start,start));
        dist[start] = 0;

        for(int i = 0; i < adjList.size(); ++i){
            int p, v;

            do{
                if(pq.empty()) return;

                auto current = pq.top();
                pq.pop();
                p = current.second.second; 
                v = current.second.first; 

            }while(visited[v] == 1);

            visited[v] = 1;
            prev[v] = p;

            for (auto& neighbor : adjList[v]) {
                int w = neighbor.first;
                int weight = neighbor.second;

                if (visited[w] == 0 && dist[w] > dist[v] + weight) {
                    dist[w] = dist[v] + weight;
                    pq.emplace(dist[w], make_pair(w, v));
                }
            }
        }
    }
};

int main() {
    int cities, roads, start, end;
    cin >> cities >> roads >> start >> end;

    cities++; 
    Graph g(cities);

    for (int i = 0; i < roads; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.setEdge(u, v, w);
    }

    vector<int> dist(cities, INT_MAX);
    vector<int> prev(cities, -1);


    g.Dijkstra(start, dist, prev);


    if (dist[end] == INT_MAX) {
        cout << "Não é possível chegar ao destino." << endl;
    } else {
        stack<int> path;
        
        while(start != end){
            path.push(end);
            end = prev[end];
        }
        path.push(start);

        while (!path.empty()) {
            if(path.size() > 1){
                cout << path.top() << " ";
            }
            else{
                cout  << path.top();
            }
            path.pop();
        }
    }
    cout << endl;


    return 0;
}
