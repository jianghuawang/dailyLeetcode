#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        int col = board[0].size();
        TrieNode root;
        for (auto& word : words) {
            auto* node = &root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children.insert({c, new TrieNode});
                }
                node = node->children.at(c);
            }
            node->word = word;
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (root.children.count(board[i][j])) {
                    dfs(board, res, i, j, &root);
                }
            }
        }
        return res;
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word{""};
    };
    void dfs(vector<vector<char>>& board, vector<string>& res, int x, int y, TrieNode *parent) {
        auto* curr_node = parent->children.at(board[x][y]);
        
        if (curr_node->word != "") {
            res.push_back(curr_node->word);
            curr_node->word = "";
        } 
        
        char orig_val = board[x][y];
        board[x][y] = '#';
        
        for (int i = 0; i < direction.size() - 1; ++i) {
            int new_x = x + direction[i];
            int new_y = y + direction[i + 1];
            
            if (new_x < 0 || new_x == board.size() || new_y < 0 || new_y == board[0].size()
               || !curr_node->children.count(board[new_x][new_y])) { continue; }
            
            dfs(board, res, new_x, new_y, curr_node);
        }
        board[x][y] = orig_val;
        if (!curr_node->children.size()) { parent->children.erase(orig_val); }
    }    
    vector<int> direction{-1, 0, 1, 0, -1};
};