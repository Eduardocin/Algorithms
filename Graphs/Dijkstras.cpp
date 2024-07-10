#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, weight>
    vector<int> visited;

public:
    Graph(int N) : adjList(N), visited(N, 0) {}

    void setEdge(int u, int v, int w) {
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }
    
    int getSize(){
        return adjList.size();
    }

    void Dijkstra(int initalNode, vector<int>& D, vector<int>& P) {

        // Initialize distances and parents
        // for(int i = 0; i < getSize(); ++i){
        //     visited[i] = 0; // UNVISITED
        //     P[i] = -1;
        //     D[i] = INT_MAX;
        // }

        // Priority queue: (acumulate cost, vertex, previous vertex)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // pair<cost, pair<vertex, previous vertex>>
        
        // Start from the source
        pq.emplace(0, make_pair(initalNode, initalNode));
        D[initalNode] = 0; // distance to the startNode

        for(int i = 0; i < getSize(); ++i){
            int p, v;
            do {
                if(pq.empty()) return;
                auto current = pq.top();
                pq.pop();
                p = current.second.second; // previous verte
                v = current.second.first; // current vertex

            } while(visited[v] == 1); // Repeat until an unvisited vertex is found
            
            visited[v] = 1; // Mark the vertex as visited
            P[v] = p; // Update parent

            for(auto& neighbor : adjList[v]){
                int w = neighbor.first;
                int weight = neighbor.second;
                if(visited[w] == 0 && D[w] > D[v] + weight){ // Update distance if shorter path is found
                    D[w] = D[v] + weight;
                    pq.emplace(D[w], make_pair(w, v)); // Add to priority queue
                }
            }
        }
    }
};

int main() {
    int nodes, edges, initialNode;
    cin >> nodes >> edges >> initialNode;

    Graph graph(nodes);

    for(int i = 0; i < edges; ++i){
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.setEdge(u, v, weight);
    }

    vector<int> distances(nodes, INT_MAX);
    vector<int> parents(nodes, -1);
    graph.Dijkstra(initialNode, distances, parents);
    
    for(int i = 0; i < nodes; ++i){
        cout << distances[i] << " ";
    }
    
    // cout << endl;
    // int targetNode = 2; // Node to which we want to find the path
    // stack<int> path;

    // //menor custo possível do caminho do nó inicial ao nó alvo
    // cout << "Shortest path cost from 0 to 2: " << distances[targetNode] << endl;
    
    // while(targetNode!= initialNode){
    //     path.push(targetNode);
    //     targetNode = parents[targetNode];
    // }

    // cout << "Path from 0 to 2: ";
    // while (!path.empty()) {
    //     cout << path.top() << " ";
    //     path.pop();
    // }
    // cout << endl;




    return 0;
}
