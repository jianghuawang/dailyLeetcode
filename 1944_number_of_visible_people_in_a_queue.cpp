#include <stack>
#include <vector>

using std::vector;
using std::stack;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        vector<int> res(heights.size());
        for (int i = 0; i < heights.size(); ++i) {
            while (s.size() && heights[s.top()] < heights[i]) {
                ++res[s.top()];
                s.pop();
            }
            if (s.size()) { ++res[s.top()]; }
            s.push(i);
        }
        return res;
    }
};