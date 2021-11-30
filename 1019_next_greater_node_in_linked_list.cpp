#include <vector>
#include <stack>
#include <utility>

using std::vector;
using std::stack;
using std::pair;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        auto *node = head;
        int n = 0;
        while (node) {
            ++n;
            node = node->next;
        }
        vector<int> res(n);
        int i = 0;
        while (head) {
            while (s.size() && head->val > s.top().first) {
                res[s.top().second] = head->val;
                s.pop();
            }
            s.push(std::make_pair(head->val, i++));
            head = head->next;
        }
        return res;
    }
};