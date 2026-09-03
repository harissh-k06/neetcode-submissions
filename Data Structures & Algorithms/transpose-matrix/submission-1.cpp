class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size() , c = matrix[0].size();
        vector<vector<int>> transpose;
        for (int j = 0 ; j< c ; j++){
            vector<int> col;
            for (int i = 0 ; i<r; i++){
                col.push_back(matrix[i][j]);
            }
            transpose.push_back(col);
        }
        return transpose;
    }
};