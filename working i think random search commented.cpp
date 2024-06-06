#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int globalCount = 0;
string globalPrint = "";


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
char giveMeARandomChar() { // just generates a random number and then turns it into a char from a - h
    return char((rand() % 8) + 65);
}

void findPath(char start, char end) {
    globalCount++; // this is good to have just so you know how inefficient it has been this time
    char random_char1 = giveMeARandomChar();
    // made a random number function - dont really need this but the random number stuff works so weird in this

    cout << start << " "; // print path
    globalPrint = globalPrint + start;

    if (start == end) { // end if path found
        cout << endl;
        cout << globalPrint << endl;
        exit(0); // kill code once done
    }
    else {
        globalPrint = globalPrint + " --> ";
    }

    for (int i = 0; i < sizeof(vertices); i++) { // look at the verticies array and 
        if (start == vertices[i]) { // find the one which we are searching for
            cout << "vertice " << vertices[i] << " located" << endl; // dont need these really but they are a nice
            cout << "options available are " << connections[i] << endl; // visual cue as to whats happening
            cout << globalCount << endl;
            
            for (int p = 0; p < sizeof(connections[i]); p++) { // in the arrays corresponding to the links between the nodes
                char t = connections[i][p]; // this was for the debugger - so that it creates a variable which can be tracked easily
                if (connections[i][p] == random_char1) { // check if it happens to connect with the random char i have generated lol
                    findPath(connections[i][p], end); // if it matches then call this function - thats right baby its recursive 
                } // with the new connection as the start variable - end remains the same obvs
            }
            findPath(start, end); // if nothing then simply call the function again so as to generate another random number
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
