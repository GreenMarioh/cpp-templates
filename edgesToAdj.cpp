#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> createAdj(int n, vector<vector<int>> &edges)
{
    // Create an adjacency list from the edges with weights
    vector<vector<pair<int, int>>> adj(n);
    for (const auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return adj;
}