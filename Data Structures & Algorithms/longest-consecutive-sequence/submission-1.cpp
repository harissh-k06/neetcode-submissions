class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int maxSize  = 1;
        sort(nums.begin() , nums.end());
        for (int i  = 0 ;  i< size - 1 ; i++){
            int sizeSoFar = 1; int nextInc = 1;
            for (int j = i + 1 ; j < size ; j++){
                if (nums[j] == nums[i]+nextInc ){
                    sizeSoFar++;
                    nextInc++;
                }
            }
            maxSize = max(maxSize , sizeSoFar);
        }

        return maxSize;

    }
};
