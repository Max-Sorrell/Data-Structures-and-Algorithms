#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int SIZE = 8;

int findMinDistance(int distances[], bool visitedSet[], int size) // finding minimum distance
{
    int minDistance = INT_MAX, minIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (!visitedSet[i] && distances[i] <= minDistance)
        {
            minDistance = distances[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(vector<int> predecessors, int vertex) {
    if (vertex == -1) {
        return;
    }
    printPath(predecessors, predecessors[vertex]);
    cout << (char)('A' + vertex) << " ";
}

void dijkstraAlgorithm(int graph[SIZE][SIZE], int src) // adjacency matrix 
{
    int distances[SIZE]; // array to calculate the minimum distance for each node                             
    bool visitedSet[SIZE]; // boolean array to mark visited and unvisited for each node
    vector<int> predecessors(SIZE, -1); // array to store the predecessor of each node

    for (int i = 0; i < SIZE; i++)
    {
        distances[i] = INT_MAX;
        visitedSet[i] = false;
    }

    distances[src] = 0; // Source vertex distance is set 0               

    for (int i = 0; i < SIZE; i++)
    {
        int minVertex = findMinDistance(distances, visitedSet, SIZE);
        if (minVertex == -1) break; // all reachable vertices processed
        visitedSet[minVertex] = true;

        for (int j = 0; j < SIZE; j++)
        {
            // updating the distance of neighbouring vertex
            if (!visitedSet[j] && graph[minVertex][j] != -1 && distances[minVertex] != INT_MAX && distances[minVertex] + graph[minVertex][j] < distances[j])
            {
                distances[j] = distances[minVertex] + graph[minVertex][j];
                predecessors[j] = minVertex;
            }
        }
    }

    cout << "Vertex\t\tDistance from source vertex\tPath" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        char vertex = 65 + i; // Convert index to corresponding vertex letter
        cout << vertex << "\t\t\t" << distances[i] << "\t\t\t";
        printPath(predecessors, i);
        cout << endl;
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        // A   B    C    D    E    F    G    H
        { 0,  10,  -1,  12,  -1,  -1,  11,   4}, // A
        {10,   0,  -1,   8,  -1,  -1,  -1,  20}, // B
        { -1, -1,   0,  17,   8,  -1,  13,  10}, // C
        {12,   8,  17,   0,  -1,  16,  24,  14}, // D
        { -1, -1,   8,  -1,   0,   8,  11,   5}, // E
        { -1, -1,  -1,  16,   8,   0,  18,  21}, // F
        {11,  -1,  13,  24,  11,  18,   0,  30}, // G
        { 4,  20,  10,  14,   5,  21,  30,   0}  // H
    };

    char srcVertex;
    cout << "Enter the source vertex (A-H): ";
    cin >> srcVertex;
    srcVertex = toupper(srcVertex);

    if (srcVertex < 'A' || srcVertex > 'H') {
        cout << "Invalid vertex. Please enter a vertex between A and H." << endl;
        return 1;
    }

    int src = srcVertex - 'A'; // Convert the character to an index

    dijkstraAlgorithm(graph, src);

    return 0;
}
