class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,j;
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(i=0;i<=len2;i++)//word1 从空变为word2[0,i]花费的步数
        {
            dp[0][i]=i;
        }
        for(j=0;j<=len1;j++)//word从非空字符串变为空字符串需要花费的步数
        {
            dp[j][0]=j;
        }
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
                }
            }
        }
        return dp[len1][len2];
    }
};