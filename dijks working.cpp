#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int vertArr[20][20]; // the adjacency matrix initially 0

// Function to display the adjacency matrix
void displayMatrix(int v) {
    int count = 65; // ASCII value for 'A'
    int i, j, d;
    cout << "  ";
    for (d = 0; d < v; d++) {
        cout << char(count) << " ";
        count++;
    }
    cout << endl;
    count = 65;
    for (i = 0; i < v; i++) {
        cout << char(count) << " ";
        count++;
        for (j = 0; j < v; j++) {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add an edge with a weight into the adjacency matrix
void add_edge(int u, int v, int weight) {
    u--; // Decrementing to match 0-based index
    v--; // Decrementing to match 0-based index
    vertArr[u][v] = weight;
    vertArr[v][u] = weight;
}

// Function to find the vertex with the minimum distance value that is not yet included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// Recursive function to print the shortest path from the source to a vertex
void printPath(vector<int> parent, int j) {
    if (parent[j] == -1) { // Base case: source node
        return;
    }
    printPath(parent, parent[j]); // Recur for the parent

    cout << " -> " << char(j + 65); // Print the current vertex
}

// Function to implement Dijkstra's algorithm for a graph represented using an adjacency matrix
void dijkstra(int graph[20][20], int src, int dest, int V) {
    int dist[20]; // Array to hold the shortest distance from the source to each vertex
    bool sptSet[20]; // Array to keep track of vertices included in the shortest path tree
    vector<int> parent(V); // Array to store the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1; // Initialize parent array
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V); // Pick the minimum distance vertex not yet processed
        sptSet[u] = true; // Mark the picked vertex as processed

        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u; // Set the parent of v to u
                dist[v] = dist[u] + graph[u][v]; // Update the distance to v
            }
        }
    }

    // Print the constructed distance array and path
    cout << "Shortest path from " << char(src + 65) << " to " << char(dest + 65) << ": ";
    if (dist[dest] != INT_MAX) {
        cout << char(src + 65);
        printPath(parent, dest);
        cout << " with distance " << dist[dest] << endl;
    }
    else {
        cout << "No path exists" << endl;
    }
}

int main() {
    int v = 8; // Number of vertices in the graph
    // Adding edges with weights
    add_edge(1, 2, 10);
    add_edge(1, 4, 12);
    add_edge(1, 7, 11);
    add_edge(1, 8, 4);
    add_edge(2, 1, 10);
    add_edge(2, 4, 8);
    add_edge(2, 8, 20);
    add_edge(3, 4, 17);
    add_edge(3, 5, 8);
    add_edge(3, 7, 13);
    add_edge(3, 8, 10);
    add_edge(4, 1, 12);
    add_edge(4, 2, 8);
    add_edge(4, 3, 17);
    add_edge(4, 6, 16);
    add_edge(4, 7, 24);
    add_edge(4, 8, 14);
    add_edge(5, 3, 8);
    add_edge(5, 6, 8);
    add_edge(5, 7, 11);
    add_edge(5, 8, 5);
    add_edge(6, 4, 16);
    add_edge(6, 5, 8);
    add_edge(6, 7, 18);
    add_edge(6, 8, 21);
    add_edge(7, 1, 11);
    add_edge(7, 3, 13);
    add_edge(7, 4, 24);
    add_edge(7, 5, 11);
    add_edge(7, 6, 18);
    add_edge(7, 8, 30);
    add_edge(8, 1, 4);
    add_edge(8, 2, 20);
    add_edge(8, 3, 10);
    add_edge(8, 4, 14);
    add_edge(8, 5, 5);
    add_edge(8, 6, 21);
    add_edge(8, 7, 30);

    // Display the adjacency matrix
    displayMatrix(v);

    int start, end;
    cout << "Enter the start node (1 to " << v << "): ";
    cin >> start;
    cout << "Enter the end node (1 to " << v << "): ";
    cin >> end;

    // Call Dijkstra's algorithm to find the shortest path from start to end
    dijkstra(vertArr, start - 1, end - 1, v);

    return 0;
}
