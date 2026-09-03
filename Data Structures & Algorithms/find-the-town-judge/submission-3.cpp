class Solution {

private:
    unordered_map<int , unordered_set<int>> trustMap;

    void populateTrustMap(vector<vector<int>>& trust){
        for (const auto& pair : trust){
            trustMap[pair[0]].insert(pair[1]);
        }
    }

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_set<int> uniqueTrustingPeople ;
        for (const auto& pair : trust){
            uniqueTrustingPeople.insert(pair[0]);
        }
        int judge = -1;
        populateTrustMap(trust);
        for (int i = 1 ; i<=n ; i++){
            if (uniqueTrustingPeople.find(i)==uniqueTrustingPeople.end()){
                judge = i;
                break;
            }
        }   
        
        for (const auto& pair : trust){
            if (trustMap[pair[0]].find(judge)==trustMap[pair[0]].end()) return -1;
        }
        return judge;

    }
};