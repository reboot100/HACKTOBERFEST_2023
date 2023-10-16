#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

namespace greedy_algorithms {
namespace boruvkas_minimum_spanning_tree {

int findParent(std::vector<std::pair<int, int>> parent, const int v) {
    if (parent[v].first != v) {
        parent[v].first = findParent(parent, parent[v].first);
    }
    return parent[v].first;
}

std::vector<std::vector<int>> boruvkas(std::vector<std::vector<int>> adj) {
    size_t size = adj.size();
    size_t total_groups = size;

    if (size <= 1) {
        return adj;
    }

    std::vector<std::vector<int>> MST(size, std::vector<int>(size, INT_MAX));
    for (int i = 0; i < size; i++) {
        MST[i][i] = 0;
    }

    std::vector<std::pair<int, int>> parent(size, std::make_pair(0, 0));

    for (int i = 0; i < size; i++) {
        parent[i].first = i;
    }

    while (total_groups > 1) {
        std::vector<std::pair<int, int>> smallest_edge(
            size, std::make_pair(-1, -1));

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (adj[i][j] == INT_MAX || adj[i][j] == 0) {
                    continue;
                }

                int parentA = findParent(parent, i);
                int parentB = findParent(parent, j);

                if (parentA != parentB) {
                    int start = smallest_edge[parentA].first;
                    int end = smallest_edge[parentA].second;

                    if (start == -1 || adj[i][j] < adj[start][end]) {
                        smallest_edge[parentA].first = i;
                        smallest_edge[parentA].second = j;
                    }

                    start = smallest_edge[parentB].first;
                    end = smallest_edge[parentB].second;

                    if (start == -1 || adj[j][i] < adj[start][end]) {
                        smallest_edge[parentB].first = j;
                        smallest_edge[parentB].second = i;
                    }
                }
            }
        }

        for (int i = 0; i < size; i++) {
            if (smallest_edge[i].first != -1) {
                int start = smallest_edge[i].first;
                int end = smallest_edge[i].second;
                int parentA = i;
                int parentB = findParent(parent, end);

                if (parentA == parentB) {
                    continue;
                }

                if (parent[parentA].second < parent[parentB].second) {
                    parent[parentB].first = parentA;
                    parent[parentB].second++;
                } else {
                    parent[parentA].first = parentB;
                    parent[parentA].second++;
                }

                MST[start][end] = adj[start][end];
                MST[end][start] = adj[end][start];
                total_groups--;
            }
        }
    }
    return MST;
}

int test_findGraphSum(std::vector<std::vector<int>> adj) {
    size_t size = adj.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (adj[i][j] < INT_MAX) {
                sum += adj[i][j];
            }
        }
    }
    return sum;
}
}  // namespace boruvkas_minimum_spanning_tree
}  // namespace greedy_algorithms

static void tests() {
    std::vector<std::vector<int>> graph = {
        {0, 5, INT_MAX, 3, INT_MAX}, {5, 0, 2, INT_MAX, 5},
        {INT_MAX, 2, 0, INT_MAX, 3}, {3, INT_MAX, INT_MAX, 0, INT_MAX},
        {INT_MAX, 5, 3, INT_MAX, 0},
    };
    std::vector<std::vector<int>> MST =
        greedy_algorithms::boruvkas_minimum_spanning_tree::boruvkas(graph);
    assert(greedy_algorithms::boruvkas_minimum_spanning_tree::test_findGraphSum(
               MST) == 13);

    graph = {{0, 2, 0, 6, 0},
             {2, 0, 3, 8, 5},
             {0, 3, 0, 0, 7},
             {6, 8, 0, 0, 9},
             {0, 5, 7, 9, 0}};
    MST = greedy_algorithms::boruvkas_minimum_spanning_tree::boruvkas(graph);
    assert(greedy_algorithms::boruvkas_minimum_spanning_tree::test_findGraphSum(
               MST) == 16);
}

int main() {
    tests();
    return 0;
}