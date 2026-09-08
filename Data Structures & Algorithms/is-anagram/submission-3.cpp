class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length(); int n = t.length();
        if (m!=n) return false;
        unordered_map<char , int> freqS;
        unordered_map<char , int> freqT;
        for (char c: s){
            freqS[c]++;
        }
        for (char c: t){
            freqT[c]++;
        }

        for (int i = 0 ; i < m ; i++){
            if (freqS[s[i]]!=freqT[s[i]]) return false;
        }

        return true;

    }
};
