#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int left = 0;
        // Expand right end of window
        for (int right = 0; right < nums.size(); right++) {
            // If already in window, we've found a duplicate within distance k
            if (window.count(nums[right])) 
                return true;
            
            // Add current number
            window.insert(nums[right]);
            
            // If window size exceeds k, slide it forward
            if (right - left == k) {
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
