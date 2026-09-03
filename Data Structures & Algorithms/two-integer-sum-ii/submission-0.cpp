class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0 , high = numbers.size() - 1;
        set<int> set;
        while (low<high){
            int sum = numbers[low] + numbers[high];
            if (sum == target){
                set.insert(low+1);
                set.insert(high+1);
                break;
            }
            else if (sum>target){
                high--;
            }
            else{
                low++;
            }
        }
        vector<int> result;
        for (auto it : set){
            result.push_back(it);
        }
        return result;
    }
};
