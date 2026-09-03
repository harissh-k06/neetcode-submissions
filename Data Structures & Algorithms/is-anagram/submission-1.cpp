class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length() , len2 = t.length();
        if (len1!=len2) return false;
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        for (int i = 0 ; i< len1 ; i++){
            if (s[i] == t[i]) continue;
            else return false;
        }
        return true;
    }
};
