class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> tracker(26, 0);
        /*for (char c : s){
            tracker.insert(c);
        }*/
        int result = 0;
        int maxFreq = 0;
        int len = s.length();
        int left= 0 , right = 0;
        while (right < len){
            tracker[((int)s[right]) - 65]++;
            maxFreq = max(maxFreq , tracker[((int)s[right]) - 65]);
            while (right - left + 1 - maxFreq > k){
                tracker[((int)s[left]) - 65]--;
                left++;
            }
            result = max(result , right - left + 1);
            right++;
        }
        return result;
    }
};
