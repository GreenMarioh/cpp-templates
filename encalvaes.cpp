#include<bits/stdc++.h>
using namespace std;

// for traversing elements from border (any element not connected to the border will not be marked visited)

class Solution {
void dfs(vector<vector<int>>& board, int row, int col, vector<vector<int>>& vis, vector<int>& delRow, vector<int>& delCol){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m) {
                if(board[nRow][nCol] == 1 && vis[nRow][nCol] == 0) {
                    dfs(board, nRow, nCol, vis, delRow, delCol);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && vis[i][0] == 0){
                dfs(grid, i, 0, vis, delRow, delCol);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] == 0){
                dfs(grid, i, m-1, vis, delRow, delCol);
            }
        }
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1 && vis[0][j] == 0){
                dfs(grid, 0, j, vis, delRow, delCol);
            }
            if(grid[n-1][j] == 1 && vis[n-1][j] == 0){
                dfs(grid, n-1, j, vis, delRow, delCol);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((grid[i][j] == 1) && (vis[i][j] == 0)) count++;
            }
        }
        return count;
    }
};