class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        //populateMap(prices);
        int size = prices.size();
        int buyMin = prices[0] ,  buy=0 , sell = 0;
        for (int i = 0 ; i < size-1 ; i++){
            if (prices[i] <= buyMin){
                buyMin = prices[i];
                int sell = *max_element(prices.begin() + i , prices.end());
                maxProfit = max(maxProfit , sell - buyMin);
            }
        }
        return maxProfit;
    }
};
