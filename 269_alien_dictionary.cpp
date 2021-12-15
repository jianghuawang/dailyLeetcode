#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::queue;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        unordered_map<char, int> indegree;
        unordered_map<char, vector<char>> adj_list;
        
        for (auto& str : words) {
            for (auto c : str) {
                indegree[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            string& lhs = words[i];
            string& rhs = words[i + 1];
            
            if (lhs.size() > rhs.size() && lhs.rfind(rhs, 0) == 0) { return ""; }
            for (int j = 0; j < std::min(lhs.size(), rhs.size()); ++j) {
                if (lhs[j] != rhs[j]) {
                    adj_list[lhs[j]].push_back(rhs[j]);
                    ++indegree[rhs[j]];
                    break;
                }
            }
        }
      
        queue<char> q;
        for (auto& [ch, cnt] : indegree) {
            if (!cnt) { q.push(ch); }
        }
        
        while (q.size()) {
            char c = q.front();
            q.pop();
            res.push_back(c);
            for (auto neighbor : adj_list[c]) {
                --indegree[neighbor];
                if (!indegree[neighbor]) { q.push(neighbor); }
            }
        }
        
        if (res.size() < indegree.size()) { return ""; }
        return res;
    }
};