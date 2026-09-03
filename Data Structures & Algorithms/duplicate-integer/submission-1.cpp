class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        int no = nums.size();
        for (int i = 0 ; i< no ; i++){
            if (set.find(nums[i])!=set.end()) return true;
            set.insert(nums[i]);
        }
        return false;
    }
};