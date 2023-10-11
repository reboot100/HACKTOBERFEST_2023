#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

int primMST(vector<vector<pair<int, int>>> &graph, int V) {
    int minCost = 0;
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        minCost += key[u];

        for (const auto &pair : graph[u]) {
            int v = pair.first;
            int weight = pair.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return minCost;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int minCost = primMST(graph, V);
    cout << "Minimum Cost of Spanning Tree: " << minCost << endl;

    return 0;
}
