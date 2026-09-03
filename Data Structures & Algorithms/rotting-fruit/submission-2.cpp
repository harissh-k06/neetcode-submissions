class Solution {
private:
    // your helper function is perfectly fine
    bool checkFresh(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> bfsQ;
        int fresh = 0;
        int time = 0;

        // init: count fresh and add all initial rotten oranges to the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    bfsQ.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // edge case

        // multi-source BFS
        while (!bfsQ.empty()) {
            int size = bfsQ.size();
            bool changed = false; // track if any orange rots this minute
            for (int k = 0; k < size; k++) {
                pair<int, int> rottedPair = bfsQ.front();
                bfsQ.pop();
                int r = rottedPair.first;
                int c = rottedPair.second;

                // Check all 4 neighbors
                if (checkFresh(grid, r + 1, c)) {
                    grid[r + 1][c] = 2; // mark rotten
                    bfsQ.push({r + 1, c});
                    fresh--;
                    changed = true;
                }
                if (checkFresh(grid, r - 1, c)) {
                    grid[r - 1][c] = 2; // mark rotten
                    bfsQ.push({r - 1, c});
                    fresh--;
                    changed = true;
                }
                if (checkFresh(grid, r, c + 1)) {
                    grid[r][c + 1] = 2; // mark rotten
                    bfsQ.push({r, c + 1});
                    fresh--;
                    changed = true;
                }
                if (checkFresh(grid, r, c - 1)) {
                    grid[r][c - 1] = 2; // mark rotten
                    bfsQ.push({r, c - 1});
                    fresh--;
                    changed = true;
                }
            }
            if (changed) time++; // increment time only if a change occurred
        }

        return fresh == 0 ? time : -1;
    }
};