class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int n = prices.size();
        int minValue = INT_MAX;

        for(int i=0; i<n; i++){
            minValue = min(minValue, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minValue);
        }

        return maxProfit;
    }
};