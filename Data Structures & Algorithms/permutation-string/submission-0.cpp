class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int flag = false;
        int len2 = s2.length() , len1 = s1.length();
        sort(s1.begin() , s1.end());
        int right = len1-1 , left = 0;
        while (right < len2 ){
            string substr = s2.substr(left, right-left+1);
            sort(substr.begin() , substr.end());
            if (s1 == substr){
                flag = true;
                break;
            }      
            left++;
            right++;
        } 
        return flag;

    }
};
