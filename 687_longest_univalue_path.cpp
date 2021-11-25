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
    int longestUnivaluePath(TreeNode* root) {
        postOrder(root);
        return res;
    }
    
    int postOrder(TreeNode* root) {
        if (!root) { return 0; }
        
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        int ret = 0;
        int path = 0;
        if (root->left && root->val == root->left->val) {
            path = 1 + left;
            ret = 1 + left;
        }
        if (root->right && root->val == root->right->val) {
            path += 1 + right;
            ret = max(ret, 1 + right);
        }
        res = max(res, path);
        return ret;
    }
private:
    int res{0};
};