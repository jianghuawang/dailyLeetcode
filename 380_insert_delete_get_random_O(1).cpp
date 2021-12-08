#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val)) { return false; }
        
        mp[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) { return false; }
        
        int val_idx = mp[val];
        mp[vec[vec.size() - 1]] = val_idx;
        std::swap(vec[val_idx], vec[vec.size() - 1]);
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_num = rand() % vec.size();
        return vec[rand_num];
    }
private:
    unordered_map<int, int> mp;
    vector<int> vec;
};
