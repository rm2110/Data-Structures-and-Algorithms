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
        adj[v][u] = w; // undirected
    }

    int minKey(int key[], bool mstSet[]) {
        int min = 9999, min_index;
        for (int v = 0; v < vertices; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void primMST() {
        int parent[100];
        int key[100];
        bool mstSet[100];

        for (int i = 0; i < vertices; i++) {
            key[i] = 9999;
            mstSet[i] = false;
        }

        key[0] = 0;     // start from vertex 0
        parent[0] = -1; // first node has no parent

        for (int count = 0; count < vertices - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        cout << "\nEdges in MST (Prim):\n";
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << "  Weight: " << adj[i][parent[i]] << "\n";
            totalWeight += adj[i][parent[i]];
        }
        cout << "Total Weight of MST: " << totalWeight << "\n";
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
         << "3. Prim's MST\n";

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

            case 3:
                g.primMST();
                break;

            default:
                cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}
