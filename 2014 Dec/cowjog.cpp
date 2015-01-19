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

int N, T;
long long pos[100005];
int f[100005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	f[fy] = fx;
}
int main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	scanf("%d%d", &N, &T);
	for (int i = 0; i < N; ++i) {
		long long p, s; scanf("%lld%lld", &p, &s);
		pos[i] = p + s * T;
	}
	for (int i = 0; i < N; ++i) f[i] = i;
	for (int i = N - 2; i >= 0; --i) {
		if (pos[i] >= pos[i + 1]) {
			pos[i] = pos[i + 1];
			merge(i + 1, i);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i)
		if (f[i] == i) ans++;
	printf("%d\n", ans);
	return 0;
}