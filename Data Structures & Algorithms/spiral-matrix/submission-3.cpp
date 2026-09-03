#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int startRow = 0, startCol = 0, endRow = rows - 1, endCol = cols - 1;
        vector<int> result;

        while(startRow <= endRow && startCol <= endCol){
            for(int j = startCol; j <= endCol; j++)
                result.push_back(matrix[startRow][j]);
            startRow++;
            for(int i = startRow; i <= endRow; i++)
                result.push_back(matrix[i][endCol]);
            endCol--;
            if(startRow <= endRow){
                for(int j = endCol; j >= startCol; j--)
                    result.push_back(matrix[endRow][j]);
                endRow--;
            }
            if(startCol <= endCol){
                for(int i = endRow; i >= startRow; i--)
                    result.push_back(matrix[i][startCol]);
                startCol++;
            }
        }
        return result;
    }
};
