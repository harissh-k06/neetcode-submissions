class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int left = 0 , right = 0;
        int maxSize = 0;
        unordered_set<char> unique;
        /*for (char c : s){
            unique.insert(c);
        }*/
//4
//{ 3, 4, 5, 9} ....

        while (right < len){
            while (unique.find(s[right])!=unique.end()){
                unique.erase(s[left++]);
            }
            unique.insert(s[right]);
            maxSize = max(maxSize , right - left+1);
            right++;
        }

        return maxSize;

    }
};
