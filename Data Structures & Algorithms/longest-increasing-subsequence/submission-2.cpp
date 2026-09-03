class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 ) return 0;
        if (len == 1) return 1;
        vector<int> dp(len , 1);
        int maxLen = 1;
        for (int i = 0 ;  i < len ; i++){
            for (int j = 0 ; j< i ; j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i] , 1+dp[j]);
                }
            }
            maxLen = max(maxLen , dp[i]);
        }
        return maxLen;
    }
};
