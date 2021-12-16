#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            while(s.size() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < nums.size() && s.size(); ++i) {
            while(s.size() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
        }
        return res;
    }
};