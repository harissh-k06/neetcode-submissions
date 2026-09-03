class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        for (char c:s1){
            freq[c]++;
        }
        int left = 0 , right = 0;
        int len1 = s1.length() , len2 = s2.length();
        int temp = len1;
        while (right < len2){
            if (freq[s2[right]] > 0) temp--;
            freq[s2[right]]--;
            while (right - left+ 1 > len1){
                freq[s2[left]]++;
                if (freq[s2[left]] > 0) temp++;
                left++;
            }
            if (temp == 0) return true;
            right++;
        }
        return false;   
    }
};
