#include <iostream>
#include <climits>

using namespace std;

int miniDist(int distance[], bool Tset[], int size) // finding minimum distance
{
    int minimum = INT_MAX, ind = -1;

    for (int k = 0; k < size; k++)
    {
        if (Tset[k] == false && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[8][8], int src) // adjacency matrix 
{
    int size = 8;
    int distance[8]; // array to calculate the minimum distance for each node                             
    bool Tset[8]; // boolean array to mark visited and unvisited for each node

    for (int k = 0; k < size; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // Source vertex distance is set 0               

    for (int k = 0; k < size; k++)
    {
        int m = miniDist(distance, Tset, size);
        if (m == -1) break; // all reachable vertices processed
        Tset[m] = true;

        for (int k = 0; k < size; k++)
        {
            // updating the distance of neighbouring vertex
            if (!Tset[k] && graph[m][k] != -1 && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }

    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < size; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }
}

int main() {
    int graph[8][8] = {
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

    int src = 0; // Source vertex 'A' (index 0)
    DijkstraAlgo(graph, src);

    return 0;
}
