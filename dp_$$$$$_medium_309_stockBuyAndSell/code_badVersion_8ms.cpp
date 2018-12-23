class Solution {
public:
	int maxProfit(vector<int>& prices){
        int size=prices.size();
        if(size==0)
            return 0;
        vector<int> dp(size,0);
        int s0_pre,s1_pre,s2_pre;
        int s0_cur,s1_cur,s2_cur;
        s0_pre=0;
        s1_pre=-prices[0];
        s2_pre=0;
        dp[0]=0;
        for(int i=1;i<size;i++)
        {
            s0_cur=max(s0_pre,s2_pre);
            s1_cur=max(s0_pre-prices[i],s1_pre);
            s2_cur=max(s2_pre,s1_pre+prices[i]);
            s0_pre=s0_cur;
            s1_pre=s1_cur;
            s2_pre=s2_cur;
            dp[i]=max(s0_cur,s2_cur);
        }
        return dp[size-1];
	}
};