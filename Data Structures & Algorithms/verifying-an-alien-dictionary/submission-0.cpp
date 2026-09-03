class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char , int> priority;
        for (int i = 0 ; i < order.length() ; i++){ 
            priority[order[i]] = i;
        }

        for (int i = 0 ; i < words.size()-1 ; i++){
            if(isSorted(words[i] , words[i+1] , priority)) continue;
            else return false;
        }

        return true;
    }
private:
    bool isSorted(string a , string b,map<char , int> priority){
        for (int i = 0 ; i < min(a.length() , b.length() ) ; i++){
            if (a[i] != b[i]){
                return priority[a[i]] <= priority[b[i]];
            }
        }
        return a.length() <= b.length();

    }


};