class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stackL;  // stores indices of '('
        stack<int> stackSt; // stores indices of '*'

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stackL.push(i);
            } else if (s[i] == '*') {
                stackSt.push(i);
            } else { // s[i] == ')'
                if (!stackL.empty()) {
                    stackL.pop();
                } else if (!stackSt.empty()) {
                    stackSt.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining '(' with '*' acting as ')'
        while (!stackL.empty() && !stackSt.empty()) {
            int lIndex = stackL.top();
            int starIndex = stackSt.top();
            // star must be after '(' to act as ')'
            if (lIndex < starIndex) {
                stackL.pop();
                stackSt.pop();
            } else {
                break;
            }
        }

        return stackL.empty();
    }
};
