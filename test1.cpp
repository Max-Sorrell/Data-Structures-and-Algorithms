#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// Define a structure for edges
struct Edge {
    char destination;
    int weight;
};

// Define the graph as an adjacency list
unordered_map<char, vector<Edge>> createGraph() {
    unordered_map<char, vector<Edge>> graph;
    graph['A'] = { {'B', 10}, {'D', 12}, {'G', 11}, {'H', 4} };
    graph['B'] = { {'A', 10}, {'D', 8}, {'H', 20} };
    graph['C'] = { {'D', 17}, {'E', 8}, {'G', 13}, {'H', 10} };
    graph['D'] = { {'A', 12}, {'B', 8}, {'C', 17}, {'F', 16}, {'G', 24}, {'H', 14} };
    graph['E'] = { {'C', 8}, {'F', 8}, {'G', 11}, {'H', 5} };
    graph['F'] = { {'D', 16}, {'E', 8}, {'G', 18}, {'H', 21} };
    graph['G'] = { {'A', 11}, {'C', 13}, {'D', 24}, {'E', 11}, {'F', 18}, {'H', 30} };
    graph['H'] = { {'A', 4}, {'B', 20}, {'C', 10}, {'D', 14}, {'E', 5}, {'F', 21}, {'G', 30} };
    return graph;
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(unordered_map<char, vector<Edge>>& graph, char start, char end) {
    unordered_map<char, int> distances;
    unordered_map<char, char> previous;
    for (auto& node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    auto compare = [&distances](char left, char right) {
        return distances[left] > distances[right];
        };
    priority_queue<char, vector<char>, decltype(compare)> pq(compare);
    pq.push(start);

    while (!pq.empty()) {
        char current = pq.top();
        pq.pop();

        if (current == end) {
            break;
        }

        for (Edge& edge : graph[current]) {
            int newDist = distances[current] + edge.weight;
            if (newDist < distances[edge.destination]) {
                distances[edge.destination] = newDist;
                previous[edge.destination] = current;
                pq.push(edge.destination);
            }
        }
    }

    // Print shortest path
    if (distances[end] == INT_MAX) {
        cout << "There is no path from " << start << " to " << end << endl;
    }
    else {
        cout << "The shortest path from " << start << " to " << end << " is " << distances[end] << endl;
        stack<char> path;
        for (char at = end; at != start; at = previous[at]) {
            path.push(at);
        }
        path.push(start);

        cout << "Path: ";
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

int main() {
    unordered_map<char, vector<Edge>> graph = createGraph();
    char start, end;

    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the end node: ";
    cin >> end;

    dijkstra(graph, start, end);
    return 0;
}
