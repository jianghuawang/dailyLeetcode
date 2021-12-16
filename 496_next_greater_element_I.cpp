#include <vector>
#include <stack>
#include <unordered_map>

using std::vector;
using std::stack;
using std::unordered_map;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> mp;
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); ++i) {
            while (s.size() && s.top() < nums2[i]) {
                mp[s.top()]= nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (mp.count(nums1[i])) { res[i] = mp[nums1[i]]; }
        }
        return res;
    }
};