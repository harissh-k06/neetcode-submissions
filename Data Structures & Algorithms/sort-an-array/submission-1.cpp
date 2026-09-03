class Solution {
private:
    void quickSort(std::vector<int>& nums, int low, int high) {
        while (low < high) { 
            int q = rand_partition(nums, low, high);

            
            if (q - low < high - q) {
                quickSort(nums, low, q - 1);
                low = q + 1; 
            } else {
                quickSort(nums, q + 1, high); 
                high = q - 1; 
            }
        }
    }

    int rand_partition(std::vector<int>& nums, int low, int high) {
        int random = low + rand() % (high - low + 1);
        swap(nums[high], nums[random]);
        return partition(nums, low, high);
    }

    int partition(std::vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[++i], nums[high]);
        return i;
    }

public:
    vector<int> sortArray(std::vector<int>& nums) {
        srand(time(nullptr));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};