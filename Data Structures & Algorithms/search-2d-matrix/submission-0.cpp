class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0 ; 
        int high = rows*cols - 1;
        int row = 0 , col = 0;
        int count = 0;
        while (count<rows*cols && row<rows && rows>=0){  
            if (matrix[row] [0] <= target && matrix[row][cols-1]>=target){
                return binarySearch(matrix , row , 0,cols-1,target);
            }
            else if (matrix[row][0]<target){
                row++;
            }
            else if (matrix[row][col-1]>target){
                row--;
            }
            else{

            }
            count++;
        }
        return false; 
    }

    bool binarySearch(vector<vector<int>>& matrix ,int r , int low , int high , int target ){
        while (low<=high){
            int mid = low + (high - low)/2;
            if (matrix[r][mid] == target) return true;
            else if (matrix[r][mid]>target){
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }

};
