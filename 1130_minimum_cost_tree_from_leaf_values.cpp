#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> max_val(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            max_val[i][i] = arr[i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int min_res = 0x7fffffff;
                max_val[j][i] = std::max(arr[j], max_val[j + 1][i]);
                for (int l = j; l < i; ++l) {
                    min_res = std::min(min_res, dp[j][l] + dp[l + 1][i] + max_val[j][l] * max_val[l + 1][i]);
                }
                dp[j][i] = min_res;
            }
        }
        return dp[0][n - 1];
    }
};