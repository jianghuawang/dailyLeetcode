#include <vector>
using std::vector;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size(), root = -1;
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < n; ++i) {
            if (parents[i] < 0) {
                root = i;
            } else {
                adj_list[parents[i]].push_back(i);
            }
        }
        postOrder(adj_list, root);
        return res;
    }
    
    int postOrder(vector<vector<int>>& adjList, int node) {
        unsigned long curr_score = 1;
        int sub_tree_size = 1;
        for (int child : adjList[node]) {
            int child_size = postOrder(adjList, child);
            sub_tree_size += child_size;
            curr_score *= child_size;
        }
        if (adjList.size() != sub_tree_size) {
            curr_score *= (adjList.size() - sub_tree_size);
        }
        if (curr_score > score) {
            score = curr_score;
            res = 1;
        } else if (curr_score == score) {
            ++res;
        }
        return sub_tree_size;
    }
private:
    int res{0};
    unsigned long score{0};
};