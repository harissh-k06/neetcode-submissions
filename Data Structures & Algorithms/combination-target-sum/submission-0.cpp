class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = nums.size();
        vector<int> subset;
        dfs(nums , target , 0 , subset , res);
        return res;
    }
private:
    void dfs(const vector<int>& nums, int target, int idx, vector<int>& subset, vector<vector<int>>& res) {
        // Base case: target met
        if (target == 0) {
            res.push_back(subset);
            return;
        }

        // Base case: invalid state
        if (target < 0 || idx >= nums.size()) {
            return;
        }

        // --- Branch 1: Skip the current element ---
        dfs(nums, target, idx + 1, subset, res); // move on

        // --- Branch 2: Pick the current element ---
        subset.push_back(nums[idx]); // pick
        dfs(nums, target - nums[idx], idx, subset, res); // reuse
        subset.pop_back();
    }
};
