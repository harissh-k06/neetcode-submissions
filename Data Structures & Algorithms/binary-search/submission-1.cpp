class Solution { 
public: 
    int search(vector<int>& nums, int target) { 
        int low = 0, high = nums.size() - 1; 
        
        while (low <= high) { 
            int mid = low + (high - low) / 2; 
            
            if (nums[mid] == target) {
                return mid; 
            }
            // Assumes nums is sorted in ascending order
            else if (nums[mid] > target) { 
                high = mid - 1; // Fix 1: Move high pointer left
            } 
            else { 
                low = mid + 1;  // Fix 2: Move low pointer right
            } 
        } 
        return -1; // Fix 3: Return integer instead of string
    } 
};
