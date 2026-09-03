class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(n , k ,1 ,subset , res);
        return res;
    }

private:
    void dfs(int n , int k , int curr, vector<int>& subset , vector<vector<int>>& res){
        if (subset.size() == k){
            res.push_back(subset);
            return;
        }

        if (subset.size()>= n || subset.size() > k) return;
        //to prune the nodes where the path has been skipped enough that with the remaining elements
        //we cannot reach k elements (what is the condition for this?)

        int remainingNo = n - curr; //including current


        //taking current no
        subset.push_back(curr);
        dfs(n , k , curr+1 , subset , res);
        
        subset.pop_back();
        //skipping current no (skip only if we can accumulate enough remaining elements to reach  k no of elements)
        if (subset.size() + remainingNo >=k)
            dfs(n , k , curr+1 , subset , res);
    }


};