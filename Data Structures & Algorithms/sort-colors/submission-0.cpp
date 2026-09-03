//#include <utility> // Required for std::swap

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int i = 0;
        int right = nums.size() - 1;

        while (i <= right) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[left]);
                left++;
                i++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[right]);
                right--;
                // Note: 'i' does not advance here because the new nums[i] needs to be checked.
            } else { // nums[i] == 1
                i++;
            }
        }
    }
};