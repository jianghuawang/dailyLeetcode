#include <vector>
#include <stack>
#include <numeric>

using std::vector;
using std::stack;

class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int n = nums.size();
        stack<int> incr, decr;
        vector<bool> searchable(n, true);
        for (int i = 0; i < n; ++i) {
            while (decr.size() && decr.top() < nums[i]) {
                decr.pop();
            }
            if (decr.size()) { searchable[i] = false; }
            decr.push(nums[i]);
        }
        for (int j = n - 1; j >= 0; --j) {
            while (incr.size() && incr.top() > nums[j]) {
                incr.pop();
            }
            if (incr.size()) { searchable[j] = false; }
            incr.push(nums[j]);
        }
        return std::accumulate(searchable.begin(), searchable.end(), 0);
    }
};