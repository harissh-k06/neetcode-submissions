class Solution {

private:   
    set<pair<int,int>> seen;
    bool dfs(vector<vector<char>>& board, int idx, int i, int j, string word){
        int m = board.size();
        int n = board[0].size();
        // Check out of bounds, mismatch, or if already visited in current path
        if (i < 0 || i >= m || j < 0 || j>= n || word[idx]!=board[i][j] || seen.find({i, j}) != seen.end()) return false;
        // Base case: matched full word up to last character
        if (idx == word.length() - 1) return true;

        // 1. Mark current cell as visited
        seen.insert({i, j});

        int flag = false;
        // 2. Explore 4 directions
        flag = flag || dfs(board, idx + 1, i + 1 , j , word);
        flag = flag || dfs(board, idx + 1, i - 1 , j , word);
        flag = flag || dfs(board, idx + 1, i, j+1, word);
        flag = flag || dfs(board, idx + 1, i ,j-1, word);
            
        // 3. Backtrack: unmark current cell for other alternative paths
        seen.erase({i, j});

        return flag;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int flag = false;
        for (int i = 0 ; i < m ; i ++){
            for (int j = 0 ; j  < n ; j++){
                if (word[0] == board[i][j]){
                    flag = flag || dfs(board , 0 , i , j, word);
                    if (flag) return true; // Early return once found
                }
            }
        }
        return flag;
    }
};