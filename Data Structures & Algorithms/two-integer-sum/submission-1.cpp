#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (mp.count(comp) && mp[comp]!=i) {
                return {mp[comp], i};
            }
            mp[nums[i]] = i;
        }
        return {}; // in case there's no solution
    }
};
