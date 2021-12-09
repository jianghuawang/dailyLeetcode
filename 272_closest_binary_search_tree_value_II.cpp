#include <vector>
#include <algorithm>

using std::vector;

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        TreeNode* close = binarySearch(root, target);
        res.push_back(close->val);
        TreeNode *pred = getPredecessor(close, root);
        TreeNode *succ = getSuccessor(close, root);
        k--;
        while (k--) {
            if (pred && (!succ || std::abs(target - pred->val) < std::abs(target - succ->val))) {
                res.push_back(pred->val);
                pred = getPredecessor(pred, root);
            } else {
                res.push_back(succ->val);
                succ = getSuccessor(succ, root);
            }
        }
        return res;
    }
    TreeNode* binarySearch(TreeNode *root, double target) {
        TreeNode *close_node = nullptr;
        double diff;
        while (root) {
            diff = abs(target - root->val);
            if (!close_node || diff < std::abs(target-close_node->val)) {
                close_node = root;
            }
            if (target - root->val > 0) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return close_node;
    }
    TreeNode* getPredecessor(TreeNode *curr, TreeNode *root) {
        TreeNode *node = nullptr;
        if (curr->left) {
            node = curr->left;
            while (node->right) {
                node = node->right;
            }
        } else {
            while (root != curr) {
                if (root->val < curr->val) {
                    node = root;
                    root = root->right;
                } else {
                    root = root->left;
                }
            }
        }
        return node;
    }
    TreeNode* getSuccessor(TreeNode *curr, TreeNode *root) {
        TreeNode *node = nullptr;
        if (curr->right) {
            node = curr->right;
            while (node->left) {
                node = node->left;
            }
        } else {
            while (root != curr) {
                if (root->val < curr->val) {
                    root = root->right;
                } else {
                    node = root;
                    root = root->left;
                }
            }
        }
        return node;
    }
};