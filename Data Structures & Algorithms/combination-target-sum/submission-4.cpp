class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       // sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums , target , 0 ,subset , res);
        return res;
    }
private:
    void dfs(const vector<int>& nums , int target , int idx ,vector<int> &subset,vector<vector<int>>& res){
        //base condtions
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        if (idx>=nums.size() || target < 0){
            return;
        } //non promising nodes

        //adding current element -> index not incremented
        subset.push_back(nums[idx]);
        dfs(nums , target-nums[idx] , idx, subset , res);
        //skipping current element -> index incremented
        subset.pop_back();
        dfs(nums , target , idx+1 , subset , res);
    }
};
