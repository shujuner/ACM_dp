int best = INT_MIN;
int runningProduct = 1;
for (int n: nums) {
    // Pick the larger of current number and the result of the multiplication
    // Picking n means we start considering a new sub-array
    runningProduct = max(runningProduct * n, n);                         // 可以做到从0后面第一位数重新计数
    // Keep track of the max runningProduct that we find
    best = max(runningProduct, best);
}
return best;