#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int N, S;
int cow[1005];
queue<pair<int, int> > q;
long long dp[1005][1005][2]; // 0 for left, 1 for right
bool in[1005][1005];
int main(int argc, char** argv) {
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) scanf("%d", &cow[i]);
	cow[++N] = 0;
	sort(cow + 1, cow + 1 + N);
	for(int i = 1; i <= N; ++i) if(cow[i] == 0){
		S = i;break;
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[S][S][0] = dp[S][S][1] = 0;
	q.push(make_pair(S, S));
	in[S][S] = true;
	while(!q.empty()){
		pair<int, int> now = q.front(); q.pop();
		int tL = now.first, tR = now.second;
		if(tL - 1 >= 1){
			int L = tL - 1;
			int R = tR;
			int C = N - (tR - tL + 1);
			dp[L][R][0] = min(1LL * (cow[tL] - cow[L]) * C + dp[tL][tR][0], dp[L][R][0]);
			dp[L][R][0] = min(1LL * (cow[tR] - cow[L]) * C + dp[tL][tR][1], dp[L][R][0]);
			if(!in[L][R]){
			    q.push(make_pair(L, R));
			    in[L][R] = true;
			}
		}
		if(tR + 1 <= N){
			int L = tL;
			int R = tR + 1;
			dp[L][R][1] = min(1LL * (cow[R] - cow[tR]) * (N - (tR - tL + 1)) + dp[tL][tR][1], dp[L][R][1]);
			dp[L][R][1] = min(1LL * (cow[R] - cow[tL]) * (N - (tR - tL + 1)) + dp[tL][tR][0], dp[L][R][1]);
			if(!in[L][R]){
			    q.push(make_pair(L, R));
			    in[L][R] = true;
			}
		}
	}
	cout << min(dp[1][N][0], dp[1][N][1]) << endl;
	return 0;
}
