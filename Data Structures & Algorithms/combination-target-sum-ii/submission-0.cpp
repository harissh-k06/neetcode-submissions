class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        set<vector<int>> res;
        vector<int> subset;
        dfs(candidates , target , 0 ,res , subset);
        vector<vector<int>> ans;
        for (auto& subset : res){
            ans.push_back(subset);
        }
        return ans;
    }

private:
    void dfs(const vector<int>& candidates,int target,int idx,set<vector<int>>& res,vector<int>& subset){
        if (target == 0) {
            res.insert(subset);
        }

        if (target< 0 || idx>=candidates.size()) return;

        subset.push_back(candidates[idx]);
        dfs(candidates , target-candidates[idx] , idx+1 , res , subset);
        subset.pop_back();
        dfs(candidates , target , idx + 1 , res , subset);
    }
};
