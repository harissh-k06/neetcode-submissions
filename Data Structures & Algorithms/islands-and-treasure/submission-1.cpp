class Solution {
private:
    int land = INT_MAX;
    int water = -1;
    int treasure = 0;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m , vector<bool>(n , false));
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == treasure){
                    bfs(i+1 , j ,m , n , 1 , grid , visited);
                    bfs(i-1 , j ,m , n , 1 , grid , visited);
                    bfs(i , j+1,m , n , 1 , grid , visited);
                    bfs(i , j-1, m , n ,1 , grid , visited);
                }
            }
        }
}

private:
    void bfs(int i , int j ,int m , int n , int dist ,vector<vector<int>>&  grid , vector<vector<bool>>&  visited){
        if (i>=m || i<0 || j>=n || j<0 || grid[i][j] == water || visited[i][j] == true) return;
        else if (grid[i][j] > dist){
            grid[i][j] = dist;
            visited[i][j] = true;
            bfs(i+1 , j ,m , n , dist+1 , grid , visited);
            bfs(i-1 , j ,m , n , dist+1 , grid , visited);
            bfs(i , j+1,m , n , dist+1 , grid , visited);
            bfs(i , j-1, m , n , dist+1 , grid , visited);
            visited[i][j] = false;
        }
        else{
            return;
        }
    }

};
