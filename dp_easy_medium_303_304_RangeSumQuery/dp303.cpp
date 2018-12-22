class NumArray {
public:
    vector<int> dp {0};
    NumArray(vector<int> nums) {
        int sum=0;
        for(int it:nums)
        {
            sum+=it;
            dp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
    
};