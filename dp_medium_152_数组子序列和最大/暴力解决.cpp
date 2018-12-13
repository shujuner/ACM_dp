class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
            return nums[0];
        vector<vector<int>> dp(size,vector<int>(size,0));
        int result=INT_MIN;
        for(int i=0;i<size;i++)
        {
            dp[i][i]=nums[i];
            if(dp[i][i]>result)
                result=dp[i][i];
        }
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                dp[i][j]=dp[i][j-1]*nums[j];
                if(dp[i][j]>result)
                    result=dp[i][j];
            }
            
        }
        return result;
    }
};
能保证结果正确，但是时间和空间占用过大。失败