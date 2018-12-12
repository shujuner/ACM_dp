class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>> dp(row,vector<int>(row,0));
        int i,j;
        int pre=0;
        dp[0][0]=triangle[0][0];
        for(i=1;i<row;i++)
        {
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            int cur=triangle[i].size();
            dp[i][cur-1]=dp[i-1][pre]+triangle[i][cur-1];
            pre=cur-1;
        }
        for(i=2;i<row;i++)
        {
            int col=triangle[i].size();
            for(j=1;j<col-1;j++)
            {
                dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
            }
            
        }
        int solution=INT_MAX;
        for(i=0;i<triangle[row-1].size();i++)
        {
            if(dp[row-1][i]<solution)
            {
                solution=dp[row-1][i];
            }
        }
        return solution;
    }
};