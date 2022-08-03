#include <set>
#include <algorithm>

using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> s;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto b = s.lower_bound({start, end});
        if(b != s.end() && b->first < end) return false;
        if(b != s.begin() && start < (--b)->second) return false;
        s.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */