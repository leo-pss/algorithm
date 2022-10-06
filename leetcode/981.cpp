#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class TimeMap {
public:
    unordered_map<string, map<int, string>> tmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(tmap.find(key) == tmap.end()) return "";
        auto it = tmap[key].upper_bound(timestamp);
        if(it == tmap[key].begin()) return "";
        it--;
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */