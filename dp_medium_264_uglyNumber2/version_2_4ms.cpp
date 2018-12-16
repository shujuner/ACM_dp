class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> results(1,1);
        int i=0,j=0,k=0;
        while(results.size()<n)
        {
            int a=min(results[i]*2,min(results[j]*5,results[k]*3));
            results.push_back(a);
            if(a==results[i]*2)
                i++;
            if(a==results[j]*5)
                j++;
            if(a==results[k]*3)
                k++;
        }
        return results.back();
    }
};