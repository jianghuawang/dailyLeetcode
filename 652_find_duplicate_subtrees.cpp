#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        postOrder(root, res);
        return res;
    }
    string postOrder(TreeNode *root, vector<TreeNode*>& res) {
        if (!root) { return "$,"; }
        auto left = postOrder(root->left, res);
        auto right = postOrder(root->right, res);
        string curr = left + right + std::to_string(root->val) + ',';
        bool found = mp.count(curr);
        if (found && !mp[curr]) {
            res.push_back(root);
            mp[curr] = true;
        }
        if (!found) { mp[curr] = false; }
        return curr;
    }
private:
    unordered_map<string, bool> mp;
};