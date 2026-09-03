#include <bits/stdc++.h>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxSize = 0; int size = 0;
        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j <cols ; j++){
                if (grid[i][j] == 1){
                    size = 0;
                    findSize(grid, i , j , size );
                }
                maxSize = (maxSize>size)?maxSize:size;
            }
        }
        return maxSize;
    }
private:
    void findSize(vector<vector<int>>& grid, int i , int j , int& size){
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i>=rows || j<0 || j>=cols || grid[i][j] == 0){
            return;
        }
        size++;
        grid[i][j] = 0;
        findSize(grid,i+1,j,size);
        findSize(grid,i-1,j,size);
        findSize(grid,i,j+1,size);
        findSize(grid,i,j-1,size);
    }
};
