#include <vector>

using namespace std;

const int ADD = 10000;
const int SIZE = 1<<16;
struct SegTree{
    int arr[SIZE];
    int start;
    SegTree(){ start = SIZE/2; fill(arr,arr+SIZE,0); }
    void construct(){
        for(int i=start-1; i>0; i--) arr[i]=arr[i*2]+arr[i*2+1];
    }
    void inc(int n, int k){
        n+=start;
        while(n>0){
            arr[n]+=k;
            n/=2;
        }
    }
    int sum(int s,int e) { return sum(s,e,1,0,SIZE/2); }
    int sum(int s,int e,int node,int ns,int ne){
        if(e<=ns || s>=ne) return 0;
        if(s<=ns && ne<=e) return arr[node];
        int mid=(ns+ne)/2;
        return sum(s,e,node*2,ns,mid)+sum(s,e,node*2+1,mid,ne);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree st;
        int n = nums.size();
        vector<int> answer(n, 0);
        for(int i = n-1; i >= 0; i--){
            answer[i] = st.sum(0, nums[i] + ADD);
            st.inc(nums[i] + ADD, 1);
        }
        return answer;
    }
};