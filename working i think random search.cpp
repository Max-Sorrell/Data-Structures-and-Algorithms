#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int globalCount = 0;


char vertices[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
char connections[][7] = {
    {'B', 'D', 'G', 'H'},
    {'A', 'D', 'H'},
    {'D', 'E', 'G', 'H'},
    {'A', 'B', 'C', 'F', 'G', 'H'},
    {'C', 'F', 'G', 'H'},
    {'D', 'E', 'G', 'H'},
    {'A', 'C', 'D', 'E', 'F', 'H'},
    {'A', 'B', 'C', 'D', 'E', 'F', 'G'}
};
char giveMeARandomChar() {
    return char((rand() % 8) + 65);
}



void findPath(char start, char end) {
    globalCount++;
    bool looping = true;
    char random_char1 = giveMeARandomChar();


    cout << start << " "; // print path

    if (start == end) { // end if path found
        cout << endl;
        exit(0);
    }

    for (int i = 0; i < sizeof(vertices); i++) {
        if (start == vertices[i]) {
            cout << "vertice " << vertices[i] << " located" << endl;
            cout << "options available are " << connections[i] << endl;
            cout << globalCount << endl;
            
            for (int p = 0; p < sizeof(connections[i]); p++) {
                char t = connections[i][p];
                if (connections[i][p] == random_char1) {
                    findPath(connections[i][p], end);
                }
            }
            findPath(start, end);
        }
    }


}

int main() {
    char start, end;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the end node: ";
    cin >> end;
    start = toupper(start);
    end = toupper(end);
    srand((unsigned)time(0));

    findPath(start, end);
    return 0;
}
