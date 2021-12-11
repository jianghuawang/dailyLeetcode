#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

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
    vector<vector<string>> printTree(TreeNode* root) {
        int row = level(root);
        int col = pow(2, row) - 1;
        vector<vector<string>> res(row, vector<string>(col));
        preorder(res, root, 0, col - 1, 0);
        return res;
    }
    int level(TreeNode *root) {
        if (!root) { return 0; }
        return 1 + std::max(level(root->left), level(root->right));
    }
    void preorder(vector<vector<string>>& res, TreeNode* root, int left, int right, int level) {
        if (!root) { return; }
        int pos = left + (right - left) / 2;
        res[level][pos] = std::to_string(root->val);
        preorder(res, root->left, left, pos - 1, level + 1);
        preorder(res, root->right, pos + 1, right, level + 1);
    }
};