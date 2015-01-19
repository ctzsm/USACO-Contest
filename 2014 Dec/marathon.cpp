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

int N, K, x[505], y[505];
int dp[505][505];
int dis(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int main() {
	freopen("marathon.in", "r", stdin);
	freopen("marathon.out", "w", stdout);
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &x[i], &y[i]);
	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
			for (int k = 0; k + j - 1 - i <= K; ++k)
				dp[j][k + j - 1 - i] = min(dp[j][k + j - 1 - i], dp[i][k] + dis(i, j));
	int ans = 0x3fffffff;
	for (int i = 0; i <= min(K, N - 2); ++i) ans = min(ans, dp[N][i]);
	printf("%d\n", ans);
	return 0;
}