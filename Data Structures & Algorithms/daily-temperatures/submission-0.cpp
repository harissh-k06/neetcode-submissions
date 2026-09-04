class Compare{
    public:
        bool operator()(pair<int , int> temp1 , pair<int,int> temp2){
            if (temp1.first > temp2.first) return true;
            return false;
        } 
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size , 0);
        priority_queue<pair<int , int> , vector<pair<int,int>> , Compare> pq;


        for (int i = 0 ; i < temperatures.size() ; i++){
            //if (pq.empty()) pq.push({temperatures[i], i});
            while (!pq.empty() && pq.top().first < temperatures[i]){
                result[pq.top().second] = i-pq.top().second;
                pq.pop();
            }
            pq.push({temperatures[i], i});
        }

        return result;

    }
};
