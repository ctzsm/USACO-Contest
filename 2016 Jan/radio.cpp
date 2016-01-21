#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
struct pnt {
	int x, y;
	void scan() { scanf("%d%d", &x, &y); }
}f[1005], b[1005];
int n, m;
int I(char x) {
	switch (x) {
		case 'E': return 0;
		case 'S': return 1;
		case 'W': return 2;
		case 'N': return 3;
		default: return -1;
	}
	return -1;
}
char s[1005];
long long g[1005][1005];
inline long long dis(pnt& a, pnt& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	scanf("%d%d", &n, &m);
	f[0].scan();
	b[0].scan();
	scanf("%s", s);
	for (int i = 0; i < n; ++i) {
		int k = I(s[i]);
		f[i + 1].x = f[i].x + dx[k];
		f[i + 1].y = f[i].y + dy[k];
	}
	scanf("%s", s);
	for (int i = 0; i < m; ++i) {
		int k = I(s[i]);
		b[i + 1].x = b[i].x + dx[k];
		b[i + 1].y = b[i].y + dy[k];
	}
	for (int i = 1; i <= n; ++i) g[i][0] = g[i - 1][0] + dis(f[i], b[0]);
	for (int i = 1; i <= m; ++i) g[0][i] = g[0][i - 1] + dis(f[0], b[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			g[i][j] = min(min(g[i - 1][j], g[i][j - 1]), g[i - 1][j - 1]) + dis(f[i], b[j]);
		}
	}
	printf("%lld\n", g[n][m]);
	return 0;
}
