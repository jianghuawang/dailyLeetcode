#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;

class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        int min_val = nums[n - 1], max_val = nums[0];
        vector<bool> searchable(n, true);
        for (int i = 1; i < n; ++i) {
            if (max_val > nums[i]) { searchable[i] = false; }
            max_val = std::max(max_val, nums[i]);
        }
        for (int j = n - 1; j >= 0; --j) {
            if (min_val < nums[j]) { searchable[j] = false; }
            res += searchable[j];
            min_val = std::min(min_val, nums[j]);
        }
        return res;
    }
};