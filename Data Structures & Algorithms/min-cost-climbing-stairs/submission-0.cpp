class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if (len == 0) return 0;
        if (len == 1) return cost[0];
        vector<int> dp(len ,0); 
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2 ; i < len ; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[len-2] , dp[len - 1]);
    }
};
