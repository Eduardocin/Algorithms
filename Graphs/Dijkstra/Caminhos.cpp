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
    // Define uma fila de prioridade mínima para armazenar pares de pesos e vértices.
    priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq; // <pair<weight, {vertex, previous vertex} >>
    
    // Inicializa a fila com o vértice inicial e seu peso 0.
    pq.emplace(0, make_pair(startVertex, startVertex));
    // Define a distância do vértice inicial para ele mesmo como 0.
    dist[startVertex] = 0;

    // Loop para iterar sobre todos os vértices.
    for(int i = 0; i < getSize(); i++){
        int p, v;

        do{
            // Verifica se a fila está vazia. Se sim, retorna.
            if(pq.empty()) return;

            // Remove o elemento com o menor peso da fila.
            auto current = pq.top();
            pq.pop();
            // Atualiza o vértice atual e o vértice anterior.
            v = current.second.first;
            p = current.second.second;

        }while(visited[v] == 1); // Repete até encontrar um vértice não visitado.

        // Marca o vértice atual como visitado.
        visited[v] = 1;
        // Atualiza o vértice anterior no caminho mais curto.
        prev[v] = p;

        // Itera sobre todos os vizinhos do vértice atual.
        for(auto &edges : adjList[v]){
            int neighbor = edges.first;
            int weight = edges.second;

            // Verifica se o vizinho não foi visitado e se a nova distância é menor que a distância atual.
            if(visited[neighbor] == 0 && dist[neighbor] > dist[v] + weight){
                // Atualiza a distância do vizinho.
                dist[neighbor] = dist[v] + weight;
                // Adiciona o vizinho à fila com a nova distância.
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