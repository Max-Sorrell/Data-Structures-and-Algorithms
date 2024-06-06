#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int SIZE = 8; // can be changed depending on whatever MD array size is needed

int findMinDistance(int distances[], bool visitedSet[], int size){ // finding minimum distance
    int minDistance = INT_MAX, minIndex = -1; // int_max is the largest possible integer. 

    for (int i = 0; i < size; i++){
        if (!visitedSet[i] && distances[i] <= minDistance){
            minDistance = distances[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printPath(vector<int> predecessors, int vertex) { // this function is for printing the paths it has found and is recursive again yayyyyyyyy
    if (vertex == -1) {
        return;
    }
    printPath(predecessors, predecessors[vertex]);
    cout << (char)('A' + vertex) << " "; // you can use (int) or (char) to convert between them in cpp. this converts the ascii value of A, plus the vertex into a char
}

void dijkstraAlgorithm(int graph[SIZE][SIZE], int src){ // takes in the MD array and the ascii for the input
    int distances[SIZE]; // array to calculate the minimum dastance for each node                             
    bool visitedSet[SIZE]; // boolean array to mark visited and unvisited for each node
    vector<int> predecessors(SIZE, -1); // vectorr to store the predecessor of each node

    for (int i = 0; i < SIZE; i++){ // initialise a bunch of values into the arrays
        distances[i] = INT_MAX;
        visitedSet[i] = false;
    }

    distances[src] = 0; // Source vertex distance is set 0 

    for (int i = 0; i < SIZE; i++){
        int minVertex = findMinDistance(distances, visitedSet, SIZE); // calls findmindist which obvs finds the min dist - sets return value to minVertex
        if (minVertex == -1) {
            break; // all reachable vertices processed
        }
        visitedSet[minVertex] = true; // should be false by default

        for (int j = 0; j < SIZE; j++){
            // updating the distance of neighbouring vertex
            if (!visitedSet[j] && graph[minVertex][j] != -1 && distances[minVertex] != INT_MAX && distances[minVertex] + graph[minVertex][j] < distances[j]){
                // the code for the if statement above is long af but its basically checking if the values remain as they have been initialised or if they have been changed
                //the next two lines just change them if they need to be changed
                distances[j] = distances[minVertex] + graph[minVertex][j];
                predecessors[j] = minVertex;
            }
        }
    }

    cout << "Vertex\t\tDistance from source vertex\tPath" << endl; // \t very handy to put tabs in - lets you not worry about spacing out letters until they get too big and its a problem but ah well doesnt matter for this
    for (int i = 0; i < SIZE; i++){ // anyway this just prints off to the screen everything which has / hasnt been updated with the correct paths.
        char vertex = 65 + i; // convert index to corresponding vertex letter
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

    int src = srcVertex - 'A'; // CONvert the character to an index

    dijkstraAlgorithm(graph, src);

    return 0;
}
