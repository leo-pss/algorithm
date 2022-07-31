#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 1<<21;
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

class NumArray {
public:
    SegTree st;
    vector<int> num;
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            st.arr[i + st.start] = nums[i];
        }
        st.construct();
        num = nums;
    }
    
    void update(int index, int val) {
        st.inc(index, val - num[index]);
        num[index] = val;
    }
    
    int sumRange(int left, int right) {
        return st.sum(left, right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */