#include <iostream>
#include <queue> 
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
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;  
            }
        }
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }
        
        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph. Remove this to make directed
        cout << "Edge added!\n";
    }

    void deleteEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }

        if (adj[u][v] == 0 && adj[v][u] == 0) {
            cout << "Edge does not exist!\n";
            return;
        }

        adj[u][v] = 0;
        adj[v][u] = 0;  // Undirected. 
        cout << "Edge deleted!\n";
    }

    bool searchEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return false;
        }
        return (adj[u][v] == 1);
    }

    void printGraph() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++)
                cout << adj[i][j] << " ";
            cout << "\n";
        }
    }

    void BFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex!\n";
            return;
        }

        int *visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = 0;

        queue<int> q;       
        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v = 0; v < vertices; v++) {
                if (adj[u][v] == 1 && visited[v] == 0) {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
        cout << "\n";
        delete[] visited;
    }

    void DFSUtil(int v, int visited[]) {
        visited[v] = 1;
        cout << v << " ";
        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] == 1 && visited[i] == 0)
                DFSUtil(i, visited);
        }
    }

    void DFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex!\n";
            return;
        }

        int *visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = 0;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << "\n";

        delete[] visited;
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
         << "2. Delete Edge\n"
         << "3. Print Graph\n"
         << "4. Search Edge\n"
         << "5. BFS Traversal\n"
         << "6. DFS Traversal\n";

    while (true) {
        cout << "\nEnter option: ";
        cin >> option;

        switch (option) {
            case 0:
                exit(EXIT_SUCCESS);

            case 1: {
                int u, v;
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.addEdge(u, v);
                break;
            }

            case 2: {
                int u, v;
                cout << "Enter edge to delete (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            }

            case 3:
                g.printGraph();
                break;

            case 4: {
                int u, v;
                cout << "Enter edge to search (u v): ";
                cin >> u >> v;
                if (g.searchEdge(u, v))
                    cout << "Edge exists!\n";
                else
                    cout << "No edge found!\n";
                break;
            }

            case 5: {
                int start;
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                g.BFS(start);
                break;
            }

            case 6: {
                int start;
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                g.DFS(start);
                break;
            }

            default:
                cout << "INVALID OPTION!\n";
        }
    }
}

