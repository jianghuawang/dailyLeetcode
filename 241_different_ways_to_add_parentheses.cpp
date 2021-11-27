#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<int> diffWaysToCompute(const string& expression) {
        if (expression.size() <= 2) {
            return vector<int>({stoi(expression)});
        }
        if (mp.count(expression)) {
            return mp[expression];
        }
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            if (expression[i] >= '0' && expression[i] <= '9') {
                continue;
            }
            auto left = diffWaysToCompute(expression.substr(0, i));
            auto right = diffWaysToCompute(expression.substr(i + 1));
            for (auto left_val : left) {
                for (auto right_val : right) {
                    switch (expression[i]) {
                        case '+':
                            res.push_back(left_val + right_val);
                            break;
                        case '-':
                            res.push_back(left_val - right_val);
                            break;
                        default:
                            res.push_back(left_val * right_val);
                    }
                }
            }
        }
        if (!mp.count(expression)) {
            mp[expression] = res;
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> mp;
};