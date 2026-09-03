#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int per = 0;
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    dfs(grid, seen, i, j, per);
                }
            }
        }
        return per;
    }

private:
    void dfs(const vector<vector<int>>& grid,
             vector<vector<bool>>& seen,
             int i, int j, int& per) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Out of bounds → perimeter edge
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            per++;
            return;
        }
        // Water cell → perimeter edge
        if (grid[i][j] == 0) {
            per++;
            return;
        }
        // Already processed land → do NOT count again
        if (seen[i][j]) {
            return;
        }
        
        seen[i][j] = true;
        dfs(grid, seen, i + 1, j, per);
        dfs(grid, seen, i - 1, j, per);
        dfs(grid, seen, i, j + 1, per);
        dfs(grid, seen, i, j - 1, per);
    }
};
