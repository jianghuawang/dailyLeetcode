#include <iostream>
#include <algorithm>
#include <queue>

using std::vector;
using std::priority_queue;

class Solution {
public:
    static bool intervalCmp(vector<int>& lhs, vector<int>& rhs) {
        return lhs[0] < rhs[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        std::sort(intervals.begin(), intervals.end(), intervalCmp);
        
        pq.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); ++i) {
            int min_end = pq.top();
            if (intervals[i][0] >= min_end) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};