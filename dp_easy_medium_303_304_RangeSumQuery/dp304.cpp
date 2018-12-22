class NumMatrix {
public:
    vector<vector<int>> dp;
    bool empty_flag=false;
    NumMatrix(vector<vector<int>> matrix) 
    {
        if(matrix.size()==0||matrix[0].size()==0) empty_flag=true;
        else
        {
            int row=matrix.size(),col=matrix[0].size();
            dp=vector<vector<int>>(row,vector<int>(col,0));
            dp[0][0]=matrix[0][0];
            for(int i=1;i<row;i++) dp[i][0]=dp[i-1][0]+matrix[i][0];
            for(int i=1;i<col;i++) dp[0][i]=dp[0][i-1]+matrix[0][i];
            for(int i=1;i<row;i++)
            {
                for(int j=1;j<col;j++)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(empty_flag) return 0;
        if(row1==0&&col1==0) return dp[row2][col2];
        if(row1==0) return dp[row2][col2]-dp[row2][col1-1];
        if(col1==0) return dp[row2][col2]-dp[row1-1][col2];
        else return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
        
    }
};