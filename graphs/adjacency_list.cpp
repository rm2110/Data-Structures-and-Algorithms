#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int vertex;
    Node* next;
    
    Node(int v) : vertex(v), next(NULL) {}
};

class Graph {
public:
    int vertices;
    Node** adj;  // array of linked list heads

    Graph(int v) {
        vertices = v;
        adj = new Node*[vertices];
        for (int i = 0; i < vertices; i++)
            adj[i] = NULL;
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }

        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Undirected graph. For directed, remove below 3 lines
        newNode = new Node(u);
        newNode->next = adj[v];
        adj[v] = newNode;

        cout << "Edge added!\n";
    }

    void deleteEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return;
        }

        // Remove v from u's list
        Node* temp = adj[u];
        Node* prev = NULL;
        while (temp != NULL && temp->vertex != v) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Edge does not exist!\n";
            return;
        }

        if (prev == NULL)
            adj[u] = temp->next;
        else
            prev->next = temp->next;
        delete temp;

        // Remove u from v's list
        temp = adj[v];
        prev = NULL;
        while (temp != NULL && temp->vertex != u) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != NULL) {
            if (prev == NULL)
                adj[v] = temp->next;
            else
                prev->next = temp->next;
            delete temp;
        }

        cout << "Edge deleted!\n";
    }

    bool searchEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= vertices || v >= vertices) {
            cout << "Invalid vertex!\n";
            return false;
        }

        Node* temp = adj[u];
        while (temp != NULL) {
            if (temp->vertex == v)
                return true; 
            temp = temp->next;
        }
        return false;
    }

    void printGraph() {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < vertices; i++) {
            cout << i << " -> ";
            Node* temp = adj[i];
            while (temp != NULL) {
                cout << temp->vertex << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }

    void BFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex!\n";
            return;
        }

        int* visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = 0;

        queue<int> q;
        visited[start] = 1;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            Node* temp = adj[v];
            while (temp != NULL) {
                int n = temp->vertex;
                if (visited[n] == 0) {
                    visited[n] = 1;
                    q.push(n);
                }
                temp = temp->next;
            }
        }
        cout << "\n";

        delete[] visited;
    }

    void DFSUtil(int v, int visited[]) {
        visited[v] = 1;
        cout << v << " ";

        Node* temp = adj[v];
        while (temp != NULL) {
            if (visited[temp->vertex] == 0)
                DFSUtil(temp->vertex, visited);
            temp = temp->next;
        }
    }

    void DFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start vertex!\n";
            return;
        }

        int* visited = new int[vertices];
        for (int i = 0; i < vertices; i++)
            visited[i] = 0;

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << "\n";

        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            Node* temp = adj[i];
            while (temp != NULL) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
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
                break;

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
                cout << "Enter start vertex for BFS: ";
                cin >> start;
                g.BFS(start);
                break;
            }

            case 6: {
                int start;
                cout << "Enter start vertex for DFS: ";
                cin >> start;
                g.DFS(start);
                break;
            }

            default:
                cout << "INVALID OPTION!\n";
        }
    }

    return 0;
}

