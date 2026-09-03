class Solution {
public:
    int uniquePaths(int m, int n) {
            int paths = 0;
            dfs(m , n , 0 , 0 , paths);
            return paths;
    }
private:
    void dfs(int m , int n , int i , int j , int& paths){
        if (i< 0 || i>= m || j<0 || j >=n) return;
        if (i== m-1 && j==n-1){
            paths++;
            return;
        }
        dfs(m , n , i+1 , j , paths);
        dfs(m , n , i , j+1 , paths);
    }
};
