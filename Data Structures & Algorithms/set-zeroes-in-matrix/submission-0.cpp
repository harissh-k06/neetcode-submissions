class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        set<int> rowTrack;
        set<int> colTrack;
        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
            if (matrix[i][j] == 0){
                rowTrack.insert(i);
                colTrack.insert(j);
            }
            }
        }

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                if (rowTrack.find(i)!=rowTrack.end() || colTrack.find(j)!=colTrack.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
