#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    // traverse all its neighbours
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}