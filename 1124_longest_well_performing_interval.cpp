#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), res = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            sum += (hours[i] > 8) ? 1 : -1;
            if (sum > 0) {
                res = i + 1;
            } else {
                if (mp.count(sum - 1)) {
                    res = std::max(res, i - mp[sum - 1]);
                }
                if (!mp.count(sum)) {
                    mp[sum] = i;
                }
            }
        }
        return res;
    }
};
