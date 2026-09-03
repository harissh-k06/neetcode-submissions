class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int j = len - 1;
        for (int i = 0 ; i < len ; i++){
            while (i < len && !isalnum(s[i])) i++;
            while (j >= 0 && !isalnum(s[j])) j--;
            if (tolower(s[i])!=tolower(s[j])) return false;
            j--;
        }
        return true;

    }
};
