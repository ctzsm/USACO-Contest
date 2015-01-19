#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int B, E, P, N, M;
vector<int> adj[40005];
long long dB[40005], dE[40005], dN[40005];
bool inqueue[40005];
void SPFA(int S, long long d[]) {
	memset(d, 0x3f, (sizeof (long long)) * 40005);
	memset(inqueue, false, sizeof inqueue);
	d[S] = 0, inqueue[S] = true;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inqueue[u] = false;
		for (int i = 0; i < (int)adj[u].size(); ++i) {
			int v = adj[u][i];
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				if (!inqueue[v]) {
					q.push(v);
					inqueue[v] = true;
				}
			}
		}
	}
}
int main() {
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	scanf("%d%d%d%d%d", &B, &E, &P, &N, &M);
	for (int i = 0; i < M; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	SPFA(1, dB);
	SPFA(2, dE);
	SPFA(N, dN);
	long long ans = dB[N] * B + dE[N] * E;
	for (int i = 1; i <= N; ++i)
		ans = min(ans, dB[i] * B + dE[i] * E + dN[i] * P);
	printf("%lld\n", ans);
	return 0;
}