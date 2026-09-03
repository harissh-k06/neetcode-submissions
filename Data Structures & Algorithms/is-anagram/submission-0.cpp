class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1!=len2) return false;
        unordered_map<char,int> map1;
        for (char i : s){
            map1[i]++;
        }
        unordered_map<char,int> map2;
        for (char j : t){
            map2[j]++;
        }
        for (int i = 0 ; i<len1 ; i++){
            if (map1[s[i]] == map2[s[i]]) continue;
            else return false;
        }
        return true;
    }
};
