#include <bits/stdc++.h>
using namespace std;
int findCircleNum(vector<vector<int>> &mat)
{
    int V = mat.size();
    vector<vector<int>> adjLs(V);
    int count = 0;

    // change matrix to list ----vvv----
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
}