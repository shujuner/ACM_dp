class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> results(1,1);
        int i=0,j=0,k=0;
        while(results.size()<n)
        {
            results.push_back(min(results[i]*2,min(results[j]*5,results[k]*3)));
            if(results.back()==results[i]*2)
                i++;
            if(results.back()==results[j]*5)
                j++;
            if(results.back()==results[k]*3)
                k++;
        }
        return results.back();
    }
};