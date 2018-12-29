class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0;i<size;i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
        }
        return maxProfit;
    }
};