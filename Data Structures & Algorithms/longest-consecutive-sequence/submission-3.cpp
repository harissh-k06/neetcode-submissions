class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        int lcs = 0;
        for (int i : nums){
            lookup.insert(i);
        }
        for (int i : lookup){
            int currNo;
            if (lookup.find(i-1)==lookup.end()){
                currNo = i;
            }
            int streak = 1;
            while (lookup.find(currNo+1)!=lookup.end()){
                currNo+=1;
                streak+=1;
            }
            lcs = max(streak , lcs);
        }
        return lcs;
    }
};
