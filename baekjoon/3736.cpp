 #include <cstdio>
 #include <vector>
 #include <queue>
 #include <algorithm>

 using namespace std;

 const int MAX = 10001;
 const int INF = 1e9;

 int n;
 int a[MAX], b[MAX]; //매칭된 상대그룹 정점 번호
 int dist[MAX]; //a그룹 정점의 level
 bool used[MAX]; //a그룹 정점이 매칭에 속해있는가?
 vector<int> adj[MAX];

 void bfs(){ //a그룹의 각 정점의 레벨 구함
    queue<int> Q;
    int i;

    for(i=0; i<n; i++){
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
     int i,j,job,job_count,server;
     while(scanf("%d",&n)>0){
         for(i=0; i<n; i++){
             scanf("%d : (%d)",&job,&job_count);
             for(j=0; j<job_count; j++){
                 scanf("%d",&server);
                 adj[job].push_back(server-n);
            }
         }

         //호프크로프트 카프 알고리즘

         int match = 0;
         fill(a,a+MAX,-1);
         fill(b,b+MAX,-1);
         while(1){
             bfs(); //레벨 구하고 시작

             int flow = 0;
             for(i=0; i<n; i++){
                 if(!used[i] && dfs(i)) flow++;
             }

             if(flow==0) break; //증가경로 없으면 알고리즘 종료

             match+=flow;
         }
         printf("%d\n",match);

         fill(used,used+MAX,false);
         for(i=0; i<n; i++) adj[i].clear();
     }
     return 0;
 }