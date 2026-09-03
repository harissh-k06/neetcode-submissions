

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;

        // Transform S into T with separators (“#”) and sentinels (“^” and “$”)
        // e.g. "abba" -> "^#a#b#b#a#$"
        string T = "^";
        for (char c : s) {
            T += '#';
            T += c;
        }
        T += "#$";

        int m = T.length();
        vector<int> P(m, 0);  // P[i] = radius of palindrome centered at T[i]
        int center = 0, right = 0;

        for (int i = 1; i < m - 1; i++) {
            int mirror = 2*center - i;
            if (i < right)
                P[i] = min(right - i, P[mirror]);

            // Attempt to expand around i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;

            // If palindrome centered at i expands past right,
            // adjust center and right boundary
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }
        }

        // Find the maximum palindrome length and its center index
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < m - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        // Extract the longest palindromic substring from the original string
        int start = (centerIndex - maxLen) / 2;  
        return s.substr(start, maxLen);
    }
};
