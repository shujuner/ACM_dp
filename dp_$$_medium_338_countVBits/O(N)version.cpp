class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp;
        int i;
        int offset=1;
        dp.push_back(0);
        for(i=1;i<=num;i++)
        {
            if(offset*2==i)
            {
                offset=offset*2;
            }
            dp.push_back(dp[i-offset]+1);
        }
        return dp;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        int i;
        dp[0]=0;
        for(i=1;i<=num;i++)
        {
            dp[i]=dp[i&i-1]+1;
        }
        return dp;
    }
};