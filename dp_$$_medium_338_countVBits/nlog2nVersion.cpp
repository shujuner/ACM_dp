class Solution {
public:
    int log(int n)
    {
        return log10(n)/log10(2);
    }
    vector<int> countBits(int num) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1;i<=num;i++)
        {
            if(pow(2,log(i))==i)
            {
                dp.push_back(1);
            }
            else
            {
                int sum=0;
                int temp=i;
                while(temp>0)
                {
                    sum++;
                    temp=i-pow(2,log(temp));
                }
                dp.push_back(sum);
            }
        }
        return dp;
        
    }
};