class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<int> pre(m, 0), cur(m, 0);
        for (int i = 0; i < m; i++) {
            pre[i] = matrix[i][0] - '0';
            sz = max(sz, pre[i]);
        }
        for (int j = 1; j < n; j++) {
            cur[0] = matrix[0][j] - '0';
            sz = max(sz, cur[0]);
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] == '1') {
                    cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
                    sz = max(sz, cur[i]);
                } else {
                    cur[i] = 0;
                }
            }
            pre = cur;
        }
        return sz * sz;
    }
};