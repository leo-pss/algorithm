#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        v.emplace_back(val);
        m[val] = v.size() - 1;
        return true;        
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int ed = v.back();
        m[ed] = m[val];
        v[m[val]] = ed; v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
private:
    vector<int> v;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */