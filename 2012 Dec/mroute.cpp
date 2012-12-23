#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 0x3fffffffffffffffLL;
typedef pair<int, int> PII;
struct edge{
    int u, L, C;
    edge(){}
    edge(int _u,int _L, int _C): u(_u), L(_L), C(_C){}
    bool operator < (const edge& x) const{
	return L < x.L;
    }
};
int N,M,X;
int cap[505];
vector<edge> edges[505];
long long Dijkstra(int s, int t, int C, int N){
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<long long> dist(N, INF);
    Q.push(make_pair(0, s)); dist[s] = 0;
    while(!Q.empty()){
	PII p = Q.top();
	if(p.second == t) break;
	Q.pop();

	int here = p.second;
	for(int i = 0;i < (int) edges[here].size(); ++i){
	    if(edges[here][i].C < C) continue;
	    int u = edges[here][i].u, L = edges[here][i].L;
	    if(dist[u] > dist[here] + L){
		dist[u] = dist[here] + L;
		Q.push(make_pair(dist[u], u));
	    }
	}
    }
    return dist[t];
}
int main(void){
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
    scanf("%d%d%d", &N, &M, &X);
    for(int i = 0;i < M; ++i){
	int I, J, L, C;
	scanf("%d%d%d%d", &I, &J, &L, &C);
	I--, J--;
	edges[I].push_back(edge(J, L, C));
	edges[J].push_back(edge(I, L, C));
	cap[i] = C;
    }
    long long ans = INF;
    for(int i = 0;i < M; ++i){
	long long dist = Dijkstra(0, N - 1, cap[i], N);
	if(dist == INF) continue;
	ans = min(ans, dist + X / cap[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
