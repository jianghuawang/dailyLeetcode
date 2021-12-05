#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int res = nums.size();
        stack<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            while (s.size() && s.top() > nums[i]) {
                s.pop();
            }
            res += s.size();
            s.push(nums[i]);
        }
        return res;
    }
};