#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> visited;
    stack<int> topoOrder; // Pilha para armazenar a ordenação topológica

public:
    Graph(int n) {
        adjList.resize(n);
        visited.assign(n, 0);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void dfs(int v) {
        visited[v] = 1; // Marca o vértice como visitado

        // Para cada vértice adjacente não visitado, execute DFS recursivamente
        for (int u : adjList[v]) {
            if (visited[u] == 0) {
                dfs(u);
            }
        }

        // Após visitar todos os vizinhos de v, empilhe v
        topoOrder.push(v);
    }

    vector<int> topologicalSort() {
        for (int v = 0; v < adjList.size(); ++v) {
            if (visited[v] == 0) {
                dfs(v); // Chama o DFS para cada vértice não visitado
            }
        }

        // Constrói o vetor de saída a partir da pilha (ordem reversa da pilha)
        vector<int> result;
        while (!topoOrder.empty()) {
            result.push_back(topoOrder.top());
            topoOrder.pop();
        }

        return result;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    vector<int> topoOrder = graph.topologicalSort();

    // Imprime a ordenação topológica
    for (int i = 0; i < topoOrder.size(); ++i) {
        cout << topoOrder[i];
        if (i < topoOrder.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
