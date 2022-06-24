#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 1<<21;

struct SegTree{
	int start;
	long long arr[SIZE],lazy[SIZE];
	SegTree() {
		start = SIZE/2;
		fill(arr,arr+SIZE,0);
		fill(lazy,lazy+SIZE,0);
	}
	void construct(){ //세그먼트 트리 구축
		for(int i=start-1; i>0; i--) arr[i]=arr[i*2]+arr[i*2+1];
	}
	void propagate(int node, int ns, int ne){ //node의 lazy값을 propagate
		if(lazy[node]==0) return;
		if(node<start){ //리프노드가 아니면 자식들에게 lazy를 미룸
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		arr[node]+=lazy[node]*(ne-ns+1); //자신에게 해당되는 값만큼 더함
		lazy[node]=0;
	}
	void add(int s,int e,int k){ add(s,e,k,1,1,start); }
	void add(int s,int e,int k,int node,int ns,int ne){
		propagate(node,ns,ne);
		if(e<ns || ne<s) return;
		if(s<=ns && ne<=e){
			lazy[node]+=k;
			propagate(node,ns,ne);
			return;
		}
		int w=(ns+ne)/2;
		add(s,e,k,node*2,ns,w);
		add(s,e,k,node*2+1,w+1,ne);
		arr[node]=arr[node*2]+arr[node*2+1];
	}
	long long sum(int s,int e){ return sum(s,e,1,1,start); }
	long long sum(int s,int e,int node,int ns,int ne){
		propagate(node,ns,ne);
		if(e<ns || ne<s) return 0;
		if(s<=ns && ne<=e) return arr[node];
		int w=(ns+ne)/2;
		return sum(s,e,node*2,ns,w)+sum(s,e,node*2+1,w+1,ne);
	}
};

int main() {
	int n,m,k,i;
	SegTree st;
	
	scanf("%d %d %d",&n,&m,&k);
	for(i=0; i<n; i++){
		scanf("%d",st.arr+st.start+i);
	}
	st.construct();
	int x,y,z,w;
	for(i=0; i<m+k; i++){
		scanf("%d %d %d",&x,&y,&z);
		if(x==1){
			scanf("%d",&w);
			st.add(y,z,w);
		}
		else{
			printf("%lld\n",st.sum(y,z));
		}
	}
	return 0;
}
