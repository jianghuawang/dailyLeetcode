#include <algorithm>
#include <vector>
#include <numeric>

using std::vector;
using std::lower_bound;
using std::accumulate;

class Solution {
public:
    Solution(vector<int>& w) : prob(w.size()) {
        int sum = accumulate(w.begin(), w.end(), 0);
        int accum_sum = 0;
        for (int i = 0; i < w.size(); ++i) {
            accum_sum += w[i];
            prob[i] = (double)accum_sum / sum;
        }
    }
    
    int pickIndex() {
        double random = ((double)rand() / (double)RAND_MAX);
        return (lower_bound(prob.begin(), prob.end(), random) - prob.begin());
    }
private:
    vector<double> prob;
};