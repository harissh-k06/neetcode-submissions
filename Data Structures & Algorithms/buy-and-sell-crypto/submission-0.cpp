class Solution {
   // unordered_map<int , int> pricesMap;
    /*void populateMap(vector<int>& prices){
        int i = 0;
        for (int cost : prices){
            pricesMap[i++] = cost;
        }
    }*/
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        //populateMap(prices);
        int size = prices.size();
        for (int i = 0 ; i < size -1; i++){
            for (int j = i+1 ; j < size ; j++){
                if (prices[j] > prices[i]) maxProfit = max(prices[j] - prices[i] , maxProfit);
            }
        }
        return maxProfit;
    }
};
