#include <iostream>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int vertices, edges;
    Edge* edgeList;

    Graph(int v, int e) {
        vertices = v;
        edges = e;
        edgeList = new Edge[e];
    }

    void addEdge(int index, int u, int v, int w) {
        edgeList[index].src = u;
        edgeList[index].dest = v;
        edgeList[index].weight = w;
    }

    int findParent(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findParent(parent, parent[i]);
    }

    void unionSet(int parent[], int rank[], int x, int y) {
        int xroot = findParent(parent, x);
        int yroot = findParent(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void kruskalMST() {
        Edge result[100];
        int e = 0; // index for result[]
        int i = 0; // index for sorted edges

        // sort edges by weight (simple bubble sort)
        for (int a = 0; a < edges - 1; a++) {
            for (int b = 0; b < edges - a - 1; b++) {
                if (edgeList[b].weight > edgeList[b + 1].weight) {
                    Edge temp = edgeList[b];
                    edgeList[b] = edgeList[b + 1];
                    edgeList[b + 1] = temp;
                }
            }
        }

        int* parent = new int[vertices];
        int* rank = new int[vertices];

        for (int v = 0; v < vertices; v++) {
            parent[v] = v;
            rank[v] = 0;
        }

        while (e < vertices - 1 && i < edges) {
            Edge nextEdge = edgeList[i++];

            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);

            if (x != y) {
                result[e++] = nextEdge;
                unionSet(parent, rank, x, y);
            }
        }

        cout << "\nEdges in MST (Kruskal):\n";
        int totalWeight = 0;
        for (i = 0; i < e; i++) {
            cout << result[i].src << " -- " << result[i].dest
                 << " == " << result[i].weight << endl;
            totalWeight += result[i].weight;
        }
        cout << "Total Weight of MST: " << totalWeight << "\n";

        delete[] parent;
        delete[] rank;
    }

    ~Graph() {
        delete[] edgeList;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V, E);

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(i, u, v, w);
    }

    g.kruskalMST();

    return 0;
}
