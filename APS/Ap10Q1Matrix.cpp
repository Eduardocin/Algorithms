#include <iostream> // Include the input-output stream library for printing and reading
#include <vector> // Include the vector library for using the vector container
#include <string> // Include the string library for using the string class
#include <queue> // Include the queue library for using the queue container

using namespace std; // Use the standard namespace

// Define the Graph class
class Graph {
private:
    vector<vector<int>> graph; // Adjacency matrix representation of the graph
    int numEdges; // Number of edges in the graph
    vector<int> visited; // Track visited nodes

public:
    // Constructor to initialize the graph with a given number of nodes
    Graph(int Nodes) {
        graph.resize(Nodes, vector<int>(Nodes, 0)); // Initialize adjacency matrix with 0s
        numEdges = 0; // Initialize number of edges to 0
        visited.resize(Nodes, 0); // Initialize visited vector with 0s
    }

    // Return the number of nodes in the graph
    int numNodes() {
        return graph.size();
    }

    // Find the first neighbor of a given node v
    int first(int v) {
        for (int i = 0; i < numNodes(); i++) {
            if (graph[v][i] != 0) {
                return i; // Return the first neighbor found
            }
        }
        return numNodes(); // Return numNodes() if no neighbor is found
    }

    // Find the next neighbor of a given node v after node w
    int next(int v, int w) {
        for (int i = w + 1; i < numNodes(); i++) {
            if (graph[v][i] != 0) {
                return i; // Return the next neighbor found
            }
        }
        return numNodes(); // Return numNodes() if no neighbor is found
    }

    // Set an edge between two nodes in the graph
    void setEdge(int sourc, int dest) {
        if (graph[sourc][dest] == 0) {
            graph[sourc][dest] = 1; // Set the edge in the adjacency matrix
            graph[dest][sourc] = 1; // Set the reverse edge (for undirected graph)
            numEdges++; // Increment the number of edges
        }
    }

    // Mark a node as visited
    void setMark(int v, int mark) {
        visited[v] = mark; // Set the visited mark for node v
    }

    // Breadth-First Search (BFS) traversal starting from a given node
    void BFS(int start) {
        queue<int> q; // Create a queue for BFS
        q.push(start); // Push the start node to the queue
        setMark(start, 1); // Mark the start node as visited

        while (!q.empty()) {
            int v = q.front(); // Get the front node from the queue
            q.pop(); // Remove the front node from the queue
            cout << v << " "; // Print the current node
            int w = first(v); // Find the first neighbor of the current node

            while (w < numNodes()) {
                if (visited[w] == 0) {
                    setMark(w, 1); // Mark the neighbor as visited
                    q.push(w); // Push the neighbor to the queue
                }
                w = next(v, w); // Find the next neighbor
            }
        }
    }

    // Depth-First Search (DFS) traversal starting from a given node
    void DFS(int start) {
        cout << start << " "; // Print the current node
        setMark(start, 1); // Mark the current node as visited
        int w = first(start); // Find the first neighbor of the current node

        while (w < numNodes()) {
            if (visited[w] == 0) {
                DFS(w); // Recursively call DFS for the neighbor
            }
            w = next(start, w); // Find the next neighbor
        }
    }

    // General graph traversal method that can perform either BFS or DFS
    void graphTraversal(string type, int start = 0) {
        for (size_t i = 0; i < visited.size(); i++) {
            setMark(i, 0); // Reset the visited marks
        }

        if (type == "BFS") {
            for (int i = 0; i < numNodes(); i++) {
                if (visited[i] == 0) {
                    BFS(i); // Perform BFS starting from node i
                }
            }
        }

        if (type == "DFS") {
            DFS(start); // Perform DFS starting from the given start node

            for (int i = 0; i < numNodes(); i++) {
                if (visited[i] == 0) {
                    DFS(i); // Perform DFS for any unvisited nodes
                }
            }
        }
    }
};

int main() {
    int numVertices, numQueries, source, destination;

    cin >> numVertices >> numQueries; // Read the number of vertices and queries
    Graph g(numVertices); // Create a graph with the given number of vertices

    for (int i = 0; i < numQueries; i++) {
        string type;
        cin >> type; // Read the type of query

        if (type == "add") {
            cin >> source >> destination; // Read the source and destination nodes
            g.setEdge(source, destination); // Add an edge between the nodes
        } else if (type == "BFS") {
            cin >> source; // Read the starting node for BFS
            g.graphTraversal(type, source); // Perform BFS traversal
            cout << endl; // Print a newline
        } else if (type == "DFS") {
            cin >> source; // Read the starting node for DFS
            g.graphTraversal(type, source); // Perform DFS traversal
            cout << endl; // Print a newline
        }
    }

    return 0; // Return 0 to indicate successful execution
}
