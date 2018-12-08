class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
        {
            return 0;
        }
        int rowNum=obstacleGrid.size();
        int colNum=obstacleGrid[0].size();
        vector< vector<int>> record(rowNum,vector<int>(colNum,0));
        for(int i=0;i<rowNum&&obstacleGrid[i][0]==0;i++)
        {
                record[i][0]=1;
        }
        for(int i=0;i<colNum&&obstacleGrid[0][i]==0;i++)
        {
                record[0][i]=1;
        }
        for(int i=1;i<rowNum;i++)
        {
            for(int j=1;j<colNum;j++)
            {
                record[i][j]=(obstacleGrid[i][j]==0?record[i-1][j]+record[i][j-1]:0);
            }
        }
        return record[rowNum-1][colNum-1];
    }
};