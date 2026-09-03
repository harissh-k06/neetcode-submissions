class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return s;
        string ans = "";
        int maxLen  = 0;
        for (int i = 0 ; i < len ; i++){
            for (int j = i; j<len ; j++){
                int subLen = j-i+1;
                if (subLen > maxLen ){
                    string substr = s.substr(i , subLen);
                    if (isPalin(substr)){
                        ans = substr;
                        maxLen = subLen;
                    } 
                }
            }
        }
        return ans;
    }

private:
    bool isPalin(string s){
        int len = s.length();
        int j = len -1;
        for (int i = 0 ; i <len/2 ; i++){
            if (s[i] == s[j]){
                j--;
            }
            else return false;
        }
        return true;
    }
};
