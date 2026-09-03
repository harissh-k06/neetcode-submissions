class Solution {
public:
    string convertToTitle(int columnNumber) {
        int temp = columnNumber;
        map<int, char> map;
        int ascii = 65;
        for (int i = 1; i <= 26; i++) {
            map[i] = (char) ascii;
            ascii++;
        }
        string result = "";
        while (temp > 0) {
            if (temp % 26 == 0) {
                result += 'Z';
                temp = (temp / 26) - 1;
            } else {
                result += map[temp % 26];
                temp /= 26;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};