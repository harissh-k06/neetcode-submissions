class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int left = 1 , right = 1;
        while (right < size){
            if (nums[right] != nums[right -1 ]){
                nums[left++] = nums[right];
            }
            right++;
        }
        return left;

    }
};