class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size();
        if(size==0||amount<1)
            return 0;
        int count=0;
        int dp[amount+1];
        dp[0]=0;
        int temp;
        while(++count<=amount)
        {
            int minVal=-1;
            for(int i=0;i<size;i++)
            {
                if(count>=coins[i]&&dp[count-coins[i]]!=-1)
                {
                    temp=dp[count-coins[i]]+1;
                    minVal=minVal<0?temp:(temp < minVal ? temp : minVal);
                }
            }
            dp[count]=minVal;
        }
        return dp[amount];
    }
};