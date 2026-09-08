class Solution {
public:
    int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        // If mid is greater than high, the pivot (smallest) is to the right
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            // Minimum is at mid or to its left
            high = mid;
        }
    }
    return nums[low];
}
};
