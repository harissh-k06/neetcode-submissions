class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() ==1) return trust[0][1];
        vector<int> trust1 = trust[0];
        vector<int> trust2 = trust[1];
        int potentialJudg;
        if (trust1[1] == trust2[1]) potentialJudg = trust1[1];
        else return -1;


        for (int i = 2 ; i< trust.size() ; i++){
            if (potentialJudg == trust[i][1]) continue;
            else return -1;
        }

        return potentialJudg;

    }
};