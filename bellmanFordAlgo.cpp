#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

// Function to implement Bellman-Ford algorithm
void bellmanFord(const vector<vector<tuple<int, int>>>& adjList, int V, int src) {
    // Initialize distances from src to all other vertices as INFINITE
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (const auto& edge : adjList[u]) {
                int v, weight;
                tie(v, weight) = edge;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (const auto& edge : adjList[u]) {
            int v, weight;
            tie(v, weight) = edge;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print the distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<tuple<int, int>>> adjList(V);

    cout << "Enter the edges in the format (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjList[u].emplace_back(v, weight);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(adjList, V, src);

    return 0;
}
