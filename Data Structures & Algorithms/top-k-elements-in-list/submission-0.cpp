class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i : nums){
            freq[i]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& [k,v] : freq) {
            arr.push_back({k, v});
        }
        sort(arr.begin(), arr.end() , [] (pair<int,int> a , pair<int,int>b){
            return a.second>b.second;
        });

        vector<int> res;
        for (int i = 0 ; i < k ; i++){
            res.push_back(arr[i].first);
        }        

        return res;

    }
};
