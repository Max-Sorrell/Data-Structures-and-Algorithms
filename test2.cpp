#include<iostream>
using namespace std;
int vertArr[20][20]; //the adjacency matrix initially 0
void displayMatrix(int v) {
    int count = 65;
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
void add_edge(int u, int v, int weight) {       //function to add edge into the matrix
    u--;
    v--;
    vertArr[u][v] = weight;
    vertArr[v][u] = weight;
}
void main() {
    int v = 8;    //there are 6 vertices in the graph
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

    displayMatrix(v);
}