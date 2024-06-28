#include <iostream>

using namespace std;

class Graph {
private:
    int** adjMatrix;
    int NumVertices;

public:
    // Constructor
    Graph(int size) : NumVertices(size) {
        adjMatrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            adjMatrix[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < NumVertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        if (u >= 0 && u < NumVertices && v >= 0 && v < NumVertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // Assuming an undirected graph
        } else {
            cout << "Invalid vertex index" << endl;
        }
    }

    // Function to print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < NumVertices; ++i) {
            for (int j = 0; j < NumVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5); // Example size

    // Adding some edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}