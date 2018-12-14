class Solution {
public:
    int rob(vector<int>& nums) {
        int size=nums.size();
        if(size==0)
            return 0;
        else if(size==1)
            return nums[0];
        else if(size==2)
            return max(nums[0],nums[1]);
        else
        {
            vector<int> a;
            a.assign(nums.begin(),nums.begin()+size-1);
            vector<int> b;
            b.assign(nums.begin()+1,nums.end());
            int planA=plan(a);
            int planB=plan(b);
            return max(planA,planB);
        }
    }
    int plan(vector<int> nums)
    {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        dp[2]=max(nums[0]+nums[2],nums[1]);
        for(int i=3;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};