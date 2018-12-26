class Solution {
public:
    int integerBreak(int n) {  
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int maxVal = 1; 
    for (int i = 2; i <= n / 2; i++) {
        int num1 = n / i, num2 = n / i + 1;
        int count1 = i - n % i, count2 = n % i;
        int part1 = 1, part2 = 1;
        while (count1 > 0) {
            part1 *= num1;
            count1--;
        }
        while (count2 > 0) {
            part2 *= num2;
            count2--;
        }
        maxVal = max(maxVal, part1 * part2);
    }
    
    return maxVal;
}
};