class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        string one  = strs[0];
        string two = strs[strs.size() - 1];
        string ans = "";
        int index = 0;
        while (index<min(one.length() , two.length()) && one[index] == two[index]){
            ans+=one[index];
            index++;
        }
        return ans;
    }
};