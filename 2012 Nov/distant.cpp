#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int oo = 0x7f7f7f7f;

struct edge{
	int v,len;
	edge(){}
	edge(int _v,int _len):v(_v),len(_len){}
};
int N,A,B;
char p[35][35];
int ans = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int d[905];
bool visited[905];
vector<edge> adj[905];
void SPFA(int s){
    for(int i = 0;i < N; ++i){
	d[i] = oo;
    }
    d[s] = 0;
    queue<int> q;
    memset(visited,false,sizeof(visited));
    q.push(s);visited[s] = true;
    while(!q.empty()){
	int u = q.front();q.pop();
	visited[u] = false;
	for(int i = 0;i < (int)adj[u].size(); ++i){
	    int v = adj[u][i].v;
	    int len = adj[u][i].len;
	    if(d[v] > d[u] + len){
		d[v] = d[u] + len;
		if(!visited[v]){
		    visited[v] = true;
		    q.push(v);
		}
	    }
	}
    }
    for(int i = 0;i < N; ++i) ans = max(ans,d[i]);
}
int main(void){
    freopen("distant.in","r",stdin);
    freopen("distant.out","w",stdout);
    scanf("%d%d%d",&N,&A,&B);
    for(int i = 0;i < N; ++i) scanf("%s",p[i]);
    for(int i = 0;i < N; ++i) for(int j = 0;j < N; ++j){
	    int s = i * N + j;
	    for(int k = 0;k < 4; ++k){
		int x = j + dx[k];
		int y = i + dy[k];
		if(0 <= x && x < N && 0 <= y && y < N){
		    int t = y * N + x;
		    if(p[i][j] == p[y][x])
			adj[s].push_back(edge(t,A));
		    else
			adj[s].push_back(edge(t,B));
		}
	    }
	}
    N = N * N;
    for(int i = 0;i < N; ++i) SPFA(i);
    printf("%d\n",ans);
    return 0;
}
