class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> newArray(nums.begin() , nums.end()); 
        for (int num : nums){
            newArray.emplace_back(num);
        }
        return newArray;
    }
};