class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> dp(nums.size(),1);
        int maxValue=1;
        for(int i=1;i<nums.size();i++)
        {
            int maxTemp=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    if(dp[j]>maxTemp)
                    {
                        maxTemp=dp[j];
                    }
                }
            }
            dp[i]=maxTemp+1;
            if(dp[i]>maxValue)
            {
                maxValue=dp[i];
            }
        }
        return maxValue;
    }
};