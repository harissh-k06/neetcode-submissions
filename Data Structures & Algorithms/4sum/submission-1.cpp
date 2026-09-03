#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> unique;
        int n = nums.size();

        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                int low = j+1, high = n-1;
                long long required = (long long)target - nums[i] - nums[j];
                while (low < high) {
                    long long sum = (long long)nums[low] + nums[high];
                    if (sum == required) {
                        unique.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    } else if (sum > required) {
                        high--;
                    } else {
                        low++;
                    }
                }
            }
        }

        vector<vector<int>> result;
        for (auto& it : unique) {
            result.push_back(it);
        }
        return result;
    }
};
