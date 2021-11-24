#include <algorithm>
using std::max;


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
    int maxPathSum(TreeNode* root) {
        postOrder(root);
        return res;
    }
    int postOrder(TreeNode* root) {
        if (!root) { return 0; }
        
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        
        int val = root->val;
        int ret = max(val, max(val + left, val + right));
        int path = max(ret, val + left + right);
        res = max(res, path);
        return ret;
    }
private:
    int res{-1000};
};