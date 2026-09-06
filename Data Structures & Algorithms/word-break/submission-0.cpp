#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    // Checks if word matches the substring starting at index i
    bool helper(const string& s, int i, const string& word) {
        int wordLen = word.length();
        int count = 0;
        while (count < wordLen) {
            if (s[count + i] != word[count]) return false;
            count++;
        }
        return true;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        // dp[i] = true means prefix of length i (s[0...i-1]) is valid
        vector<bool> dp(len + 1, false);

        // Base case: empty string prefix of length 0 is always valid
        dp[0] = true;

        for (int i = 0; i < len; i++) {
            // If prefix up to index i cannot be formed, we cannot append any word from here
            if (!dp[i]) continue;

            for (const auto& word : wordDict) {
                int wordLen = word.length();
                // Ensure the word doesn't exceed the bounds of s
                if (i + wordLen > len) continue;

                // Check if the word matches s starting at index i
                bool flag = helper(s, i, word);
                if (flag) {
                    dp[i + wordLen] = true; // Prefix of length (i + wordLen) is valid
                }
            }
        }

        return dp[len];
    }
};