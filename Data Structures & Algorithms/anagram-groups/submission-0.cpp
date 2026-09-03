class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int size = strs.size();
        unordered_set<string> unique;
        unordered_map<string,vector<string>> maintain;
        for (int i = 0 ; i < size ; i++ ){
            string current = strs[i];
            sort(current.begin() , current.end());
            if (unique.find(current)==unique.end()){
                unique.insert(current);
                vector<string> newAnagram;
                newAnagram.push_back(strs[i]);
                maintain[current] = newAnagram;
            }
            else{
                maintain[current].push_back(strs[i]);
            }
        }

        for (auto [k,v]: maintain){
            result.push_back(v);
        }
        return result;
    }
};
