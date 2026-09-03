class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin() , nums.end());
        set<vector<int>> set;
        for (int i = 0 ; i< len -1 ; i++){
            int low = i +1;
            int high = len-1;
            while (low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if (sum == 0){
                    set.insert({nums[i] , nums[low] , nums[high]});
                    low++; high--;
                }
                else if (sum>0) high--;
                else low++;
            }
        }
        vector<vector<int>> result;
        for (auto it : set){
            result.push_back(it);
        }
        return result;
    }
};
