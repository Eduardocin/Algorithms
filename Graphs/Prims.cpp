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
    // Define uma fila de prioridade mínima para armazenar pares de pesos e vértices.
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq; //pair<weight, pair<current vertex, previous vertex>>

    // Inicializa a fila com o vértice inicial (0) e peso 0.
    pq.emplace(0, make_pair(0, 0));
    // Define a distância do vértice inicial para ele mesmo como 0.
    dist[0] = 0;

    // Loop para iterar sobre todos os vértices.
    for(int i = 0 ; i < getSize(); ++i){
        int p, v;
        do{
            // verífica se  a heap está vazia antes de acabar o loop. Se sim, o grafo é desconexo.
            if(pq.empty()) return;

            // Remove o elemento com o menor peso da fila.
            auto temp = pq.top();
            pq.pop();
            // Atualiza o vértice anterior e o vértice atual.
            p = temp.second.second; // previous vertex
            v = temp.second.first;  // current vertex

        }while(visited[v] == 1); // Repete até encontrar um vértice não visitado.

        parent[v] = p;
        visited[v] = 1;

        // Itera sobre todos os vizinhos do vértice atual.
        for(auto &it : adjList[v]){
            int u = it.first;
            int weight = it.second;

            // Verifica se o vizinho não foi visitado e se a nova distância é menor que a distância atual.
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