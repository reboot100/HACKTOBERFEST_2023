#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int findSet(vector<int>& parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return findSet(parent, parent[node]);
}

void unionSets(vector<int>& parent, int u, int v) {
    int rootU = findSet(parent, u);
    int rootV = findSet(parent, v);
    if (rootU != rootV) {
        parent[rootU] = rootV;
    }
}

int kargerMinCut(vector<vector<int>>& graph) {
    int numNodes = graph.size();

    vector<int> parent(numNodes);
    for (int i = 0; i < numNodes; i++) {
        parent[i] = i;
    }

    while (numNodes > 2) {
        int randomEdge = rand() % (numNodes * (numNodes - 1) / 2);
        int u, v;
        for (u = 0; u < numNodes; u++) {
            for (v = u + 1; v < numNodes; v++) {
                if (randomEdge == 0) {
                    break;
                }
                randomEdge--;
            }
            if (randomEdge == 0) {
                break;
            }
        }

        while (findSet(parent, u) == findSet(parent, v)) {
            randomEdge = rand() % (numNodes * (numNodes - 1) / 2);
            for (u = 0; u < numNodes; u++) {
                for (v = u + 1; v < numNodes; v++) {
                    if (randomEdge == 0) {
                        break;
                    }
                    randomEdge--;
                }
                if (randomEdge == 0) {
                    break;
                }
            }
        }

        unionSets(parent, u, v);

        numNodes--;
    }

    int minCutEdges = 0;
    for (int u = 0; u < graph.size(); u++) {
        for (int v = u + 1; v < graph.size(); v++) {
            if (findSet(parent, u) != findSet(parent, v)) {
                minCutEdges++;
            }
        }
    }

    return minCutEdges;
}

int main() {
    srand(time(nullptr));

    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    int minCut = INT_MAX;
    for (int i = 0; i < numNodes * numNodes; i++) {
        int cut = kargerMinCut(graph);
        if (cut < minCut) {
            minCut = cut;
        }
    }

    cout << "Minimum Cut: " << minCut << endl;

    return 0;
}
