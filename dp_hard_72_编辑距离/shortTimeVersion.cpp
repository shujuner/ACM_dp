class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();  
        int* dp = new int[m+1];     // DP on one row at a time.
        int* dp_tmp = new int[m+1]; // Keep track of previous row before overwriting.
        dp_tmp[0] = 0;
        for (int j = 1; j <= m; j++)
            dp[j] = j;
        for (int i = 1; i <= n; i++) {
            dp[0] = i;
            for (int j = 1; j < m+1; j++) {
                dp_tmp[j] = dp[j];
                int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;
                dp[j] = min(min(dp[j-1] + 1, dp[j] + 1),dp_tmp[j-1] + cost);
            }
            dp_tmp[0] = i;
        }
        return dp[m];
    }
};