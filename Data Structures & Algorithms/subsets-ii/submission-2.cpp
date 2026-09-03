class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums , 0 , res , subset);
        return res;
    }

private:
    void dfs(const vector<int>& nums , int idx , vector<vector<int>>& res , vector<int>& subset){
        if (idx == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        dfs(nums , idx+1 , res , subset);
        subset.pop_back();
        int i = idx;
        while (i+1<nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        dfs(nums ,i+1 , res, subset);
   }
};
