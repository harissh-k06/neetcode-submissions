class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size , 1);
        vector<int> suffix(size , 1);
        for (int i = 1 ; i < nums.size() ; i++){
            prefix[i] = prefix[i-1]*nums[i-1]; //1*0
        }

        for (int i = nums.size() - 2 ; i>= 0 ; i--){
            suffix[i] = suffix[i+1] *nums[i+1];
        }
        vector<int> res(size , 1);
        for (int i = 0 ; i < nums.size() ; i++){
            res[i] = prefix[i]*suffix[i];
        }
        return res;
    }
};
