class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int size = nums.size();
        for (int idx = 0 ;  idx< nums.size(); idx++){
            if (nums[idx] == val){
                nums.erase(nums.begin() + idx);
                idx--;
            }
        }
        return nums.size();    
    }
};