class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort
        vector<vector<int>> res;
        vector<int> currentPerm;
        vector<bool> used(nums.size(), false); // track used elements
        dfs(nums, currentPerm, used, res);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<int>& currentPerm, vector<bool>& used, vector<vector<int>>& res) {
        if (currentPerm.size() == nums.size()) { // goal
            res.push_back(currentPerm);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) { // already used
                continue;
            }
            // Key part: skip duplicates
            // only use the first of the duplicates to start a new permutation path
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }

            used[i] = true; // choose
            currentPerm.push_back(nums[i]);

            dfs(nums, currentPerm, used, res); // explore

            currentPerm.pop_back(); // unchoose (backtrack)
            used[i] = false;
        }
    }
};