#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct pnt {
	long long x, y;
	void scan() { scanf("%lld%lld", &x, &y); }
	pnt operator - (const pnt& a) {
		pnt res;
		res.x = x - a.x, res.y = y - a.y;
		return res;
	}
}p[222];
typedef pnt vec;
int n;
inline long long dis(pnt& a, pnt& b) {
	return labs(b.x - a.x) + labs(b.y - a.y);
}
inline long long cross(vec& a, vec& b) {
	return a.x * b.y - a.y * b.x;
}
inline int dir(int i) {
	if (i == n) return 0;
	vec l1 = p[i] - p[i - 1], l2 = p[i + 1] - p[i];
	long long area = cross(l1, l2);
	if (area == 0) return 180;
	return area < 0 ? 90 : 270;
}
long long l[222], r[222], d[222];
vector<int> path[222];
int main() {
	freopen("lightsout.in", "r", stdin);
	freopen("lightsout.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) p[i].scan(); p[n] = p[0];
	for (int i = 1; i < n; ++i) l[i] = l[i - 1] + dis(p[i], p[i - 1]);
	for (int i = n - 1; i > 0; --i) r[i] = r[i + 1] + dis(p[i + 1], p[i]);
	for (int i = 0; i < n; ++i) d[i] = min(l[i], r[i]);
	for (int i = 1; i < n; ++i) {
		path[i].push_back(dir(i));
		for (int j = i + 1; j <= n; ++j) {
			path[i].push_back(dis(p[j], p[j - 1]));
			path[i].push_back(dir(j));
		}
	}
	// for (int i = 1; i < n; ++i) {
	// 	for (int j = 0; j < path[i].size(); ++j) printf("%d ", path[i][j]);
	// 	printf("\n");
	// }
	long long ans = 0;
	for (int i = 1; i < n; ++i) {
		int g = 0;
		long long len = 0;
		for (int j = 1; j < n; ++j) {
			if (j == i) continue;
			int l = min(path[i].size(), path[j].size());
			long long tlen = 0;
			bool flag = false;
			for (int k = 0; k < l; ++k) {
				if (k & 1) tlen += path[i][k];
				if (path[i][k] != path[j][k]) {
					if (g < (k + 1) / 2) {
						g = (k + 1) / 2;
						len = tlen;
					}
					flag = true;
					break;
				}
			}
			if (!flag) {
				if (g < l / 2) {
					g = l / 2;
					len = tlen;
				}
			}
		}
		g = (i + g) % n;
		ans = max(ans, d[g] + len - d[i]);
	}
	printf("%lld\n", ans);
	return 0;
}