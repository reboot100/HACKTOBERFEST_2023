#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
};

class DisjointSet {
public:
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (rank[x] < rank[y])
                swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

void kruskalMST(Graph &graph) {
    int V = graph.V;
    vector<Edge> result(V);
    int e = 0, i = 0;

    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    DisjointSet ds(V);

    while (e < V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];
        int x = ds.find(next_edge.src);
        int y = ds.find(next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            ds.unionSet(x, y);
        }
    }

    for (i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

int main() {
    Graph graph;
    cin >> graph.V >> graph.E;
    graph.edges.resize(graph.E);

    for (int i = 0; i < graph.E; i++) {
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
    }

    kruskalMST(graph);

    return 0;
}
