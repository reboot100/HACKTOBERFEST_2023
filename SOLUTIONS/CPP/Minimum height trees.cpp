#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int bfs(int src, int n, vector<vector<int>& adj, vector<int>& par) {
        vector<int> dis(n, 1e8);
        int mx = 0, ind = src;
        queue<pair<int, int>> q;
        q.push({src, 0});
        dis[src] = 0;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto neg : adj[curr.first]) {
                if (dis[neg] <= dis[curr.first]) continue;
                dis[neg] = curr.second + 1;
                q.push({neg, curr.second + 1});
                par[neg] = curr.first;
                if (dis[neg] > mx) {
                    mx = dis[neg];
                    ind = neg;
                }
            }
        }
        return ind;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> par2(n, -1);

        int first = bfs(0, n, adj, par2);
        for (int i = 0; i < n; i++) par2[i] = -1;
        int sec = bfs(first, n, adj, par2);

        vector<int> path;

        while (par2[sec] != -1) {
            path.push_back(sec);
            sec = par2[sec];
        }
        path.push_back(sec);
        int sz = path.size();
        if (sz % 2 == 0) {
            return {path[(sz - 1) / 2], path[sz / 2]};
        }
        return {path[sz / 2]};
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution solution;
    vector<int> result = solution.findMinHeightTrees(n, edges);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
