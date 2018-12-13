class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;
		
        int best = INT_MIN;
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                swap(maxProd, minProd);//目前的结果肯定是个正数，如果再来一个负数，只有使用负数与之相乘才是最大的
            }
            maxProd = max(maxProd*n, n);//存储到n这个数字正数中最大值
            minProd = min(minProd*n, n);//存储到n这个数的时候负数的最大值 存储的是到m这个数最小的和值，可能是一个小的正数，可能是一个负数。
            best = max(best, maxProd); //best是上一次记录的最大值，这一步隐含的判断了，如果负数之间相乘小于原来的数best取上一次的值。存的是目前最大的和值
        }
        
        return best;
    }
};