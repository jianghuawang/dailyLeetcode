#include <vector>
using std::vector;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size(), root = -1;
        unsigned long score = 0;
        int res = 0;
        vector<vector<int>> adj_list(n);
        vector<int> count(n, 1);
        for (int i = 0; i < n; ++i) {
            if (parents[i] < 0) {
                root = i;
            } else {
                adj_list[parents[i]].push_back(i);
            }
        }
        postOrder(adj_list, count, root);
        unsigned long curr = 1;
        for (int i = 0; i < n; ++i) {
            if (i == root) {
                curr = 1;
            } else {
                curr = n - count[i];
            }
            for (int child : adj_list[i]) {
                curr *= count[child];
            }
            if (curr > score) {
                score = curr;
                res = 1;
            } else if (curr == score) {
                ++res;
            }
        }
        return res;
    }
    
    int postOrder(vector<vector<int>>& adjList, vector<int>& count, int node) {
        for (int child : adjList[node]) {
            count[node] += postOrder(adjList, count, child);
        }
        return count[node];
    }
};