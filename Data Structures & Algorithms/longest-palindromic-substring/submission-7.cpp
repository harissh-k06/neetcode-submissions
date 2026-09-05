#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        vector<vector<bool>> store(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++)
            store[i][i] = true;
        for (int i = 0; i< n - 1 ; i++) {
            if (s[i] == s[i+1]) {
                store[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        

        int currLen = 3;
        while (currLen <= n){
            for (int i = 0 ; i <= n - currLen ; i++){
                int j = i + currLen - 1;
                if (s[i] == s[j] && store[i+1][j-1]){
                    maxLen = max(maxLen , currLen);
                    start = i;
                    store[i][j] = true;
                }
            }
            currLen+=1;
        }
        return s.substr(start, maxLen);
    }
};
