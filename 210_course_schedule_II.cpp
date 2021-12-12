#include <vector>
#include <queue>

using std::vector;
using std::queue;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<int> indegree(numCourses);
        
        vector<int> res(numCourses);
        for (auto& vec : prerequisites) {
            adj_list[vec[1]].push_back(vec[0]);
            ++indegree[vec[0]];
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i) {
            if (!indegree[i]) { q.push(i); }
        }
        int idx = 0;
        while (q.size()) {
            int node = q.front();
            q.pop();
            res[idx++] = node;
            for (auto neighbor : adj_list[node]) {
                --indegree[neighbor];
                if (!indegree[neighbor]) { q.push(neighbor); }
            }
        }
        if (idx != numCourses) { return vector<int>(); }
        return res;
    }
};