#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) : curr(root) {
        
    }
    
    int next() {
        TreeNode *ret;
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        ret = s.top();
        s.pop();
        curr = ret->right;
        return ret->val;
    }
    
    bool hasNext() {
        if (curr || s.size()) { return true; }
        return false;
    }
private:
    TreeNode *curr{nullptr};
    stack<TreeNode*> s;
};
