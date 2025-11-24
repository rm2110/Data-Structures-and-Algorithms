#include <iostream>
using namespace std;

class Graph {
public:
    int vertices;
    int **adj;

    Graph(int v) {
        vertices = v;
        adj = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adj[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
                adj[i][j] = 0; 
        }
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }
        adj[u][v] = w;
        adj[v][u] = w; // Undirected graph
        cout << "Edge and weight added!\n";
    }

    int minDistance(int dist[], bool visited[]) {
        int min = 9999, min_index = -1;
        
        for (int v = 0; v < vertices; v++) {
            if (visited[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex!\n";
            return;
        }

        int dist[100];     // shortest distance from start
        bool visited[100]; // processed vertices

        for (int i = 0; i < vertices; i++) {
            dist[i] = 9999;   // infinity
            visited[i] = false;
        }

        dist[start] = 0; // distance to itself is 0

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && adj[u][v] != 0 && dist[u] != 9999
                    && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        cout << "\nShortest distances from vertex " << start << ":\n";
        for (int i = 0; i < vertices; i++) {
            cout << "To " << i << " : " << dist[i] << "\n";
        }
    }

    void printGraph() {
        cout << "\nAdjacency Matrix (weights):\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cout << adj[i][j] << " ";
            cout << "\n";
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adj[i];
        delete[] adj;
    }
};

int main() {
    int n, option;
    cout << "Enter number of vertices: ";
    cin >> n;

    Graph g(n);

    cout << "\n0. Exit\n"
         << "1. Add Edge\n"
         << "2. Print Graph\n"
         << "3. Run Dijkstra\n";

    while (true) {
        cout << "\nEnter option: ";
        cin >> option;

        switch (option) {
            case 0:
                exit(EXIT_SUCCESS);
                break;

            case 1: {
                int u, v, w;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g.addEdge(u, v, w);
                break;
            }

            case 2:
                g.printGraph();
                break;

            case 3: {
                int start;
                cout << "Enter start vertex: ";
                cin >> start;
                g.dijkstra(start);
                break;
            }

            default:
                cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}
