#include <map>
#include <algorithm>

using namespace std;

class MyCalendarThree {
private:
    map<int, int> event;
    int answer;
public:
    MyCalendarThree() {
        event[0] = 0;
        event[1e9 + 1] = 0;
        answer = 0;
    }
    void split(int x){
        event[x] = (--event.upper_bound(x))->second;
    }
    int book(int start, int end) {
        split(start);
        split(end);
        for(auto it = event.find(start); it->first < end; it++){
            answer = max(answer, ++(it->second));
        }
        return answer;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */