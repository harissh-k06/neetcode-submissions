class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> uniq;
        int prevNum = nums[0];
        uniq.push_back(nums[0]);
        for (int i = 1 ; i < size ; i++){
            if (prevNum != nums[i]){
                uniq.push_back(nums[i]);
            }
            prevNum = nums[i];
        }

        nums = uniq;
        return nums.size();


    }
};