class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        //( )   { } [ ] .
        map <char , char> map;
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';
        stack<char> stack;
        for (int i = 0 ; i < len ; i++){
            if (isOpen(s[i])){
                stack.push(s[i]);
            }
            else{
                if (stack.empty()) return false;

                if (map[stack.top()] == s[i]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return stack.empty();
    }

    bool isOpen(char c){
        if (c == '(' ||  c == '[' || c== '{') return true;
        return false;
    }
};
