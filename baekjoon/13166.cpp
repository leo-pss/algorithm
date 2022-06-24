 #include <cstdio>
 #include <vector>
 #include <queue>
 #include <algorithm>

 using namespace std;

 const int MAX = 400001;
 const int INF = 1e9;

 int n;
 int a[MAX], b[MAX]; //매칭된 상대그룹 정점 번호
 int dist[MAX]; //a그룹 정점의 level
 bool used[MAX]; //a그룹 정점이 매칭에 속해있는가?
 vector<int> adj[MAX];
 pair<int,int> f[MAX][2];

 void bfs(){ //a그룹의 각 정점의 레벨 구함
    queue<int> Q;
    int i;

    for(i=1; i<=n; i++){
        if(!used[i]){
            dist[i]=0;
            Q.push(i);
        }
        else dist[i]=INF;
    }

    while(!Q.empty()){
        int A = Q.front(); Q.pop();
        for(int B : adj[A]){
            if(b[B] != -1 && dist[b[B]] == INF){
                dist[b[B]] = dist[A]+1;
                Q.push(b[B]);
            }
        }
    } 
 } 

 bool dfs(int A){ //새 매칭을 발견하면 true
    for(int B : adj[A]){
        if(b[B]==-1 || dist[b[B]] == dist[A]+1 && dfs(b[B]) ){ //끝점(매칭에 안속함) or 증가경로 연장
            used[A]=true;
            a[A]=B;
            b[B]=A;
            return true;
        }
    }
    return false;
 }

 int main(void){
    int i,j,l=0,r=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d %d %d %d",&f[i][0].first,&f[i][0].second,&f[i][1].first,&f[i][1].second);
        r=max(r,f[i][0].second);
        r=max(r,f[i][1].second);
    }

    int answer=INF;
    while(l<=r){
        int w = (l+r)/2;
        for(i=1; i<=n; i++){
            if(f[i][0].second<=w) adj[i].push_back(f[i][0].first);
            if(f[i][1].second<=w) adj[i].push_back(f[i][1].first);
        }

        //호프크로프트 카프 알고리즘
        int match = 0;
        fill(a,a+MAX,-1);
        fill(b,b+MAX,-1);
        while(1){
            bfs(); //레벨 구하고 시작

            int flow = 0;
            for(i=1; i<=n; i++){
                if(!used[i] && dfs(i)) flow++;
            }

            if(flow==0) break; //증가경로 없으면 알고리즘 종료

            match+=flow;
        }
        if(match==n){
            answer=min(answer,w);
            r=w-1;
        }
        else{
            l=w+1;
        }
    
        fill(used,used+MAX,false);
        for(i=1; i<=n; i++) adj[i].clear();
    }
    printf("%d",answer==INF?-1:answer);
    return 0;
 }