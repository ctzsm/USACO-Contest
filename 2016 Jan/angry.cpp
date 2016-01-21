#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, y[100005];
int l[50005], r[50005];
bool check(int x) {
	int i = 0, j = 0;
	while (j + 1 < n && y[j + 1] - y[i] <= x) ++j;
	if ((l[i] + 1) * 2 <= x && (r[j] + 1) * 2 <= x)
		return true;
	for (++i; i < n - 1; ++i) {
		while (j + 1 < n && y[j + 1] - y[i] <= x) ++j;
		if ((l[i] + 1) * 2 <= x && (r[j] + 1) * 2 <= x)
			return true;
	}
	return false;
}
int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", y + i);
	sort(y, y + n);
	for (int i = 1, j = 0; i < n; ++i) {
		int g = max(l[j] + 1, y[i] - y[j]);
		while (j + 1 < i && max(l[j + 1] + 1, y[i] - y[j + 1]) <= g) {
			j ++;
			g = max(l[j] + 1, y[i] - y[j]);
		}
		l[i] = g;
	}
	for (int i = n - 2, j = n - 1; i >= 0; --i) {
		int g = max(r[j] + 1, y[j] - y[i]);
		while (j - 1 > i && max(r[j - 1] + 1, y[j - 1] - y[i]) <= g) {
			j --;
			g = max(r[j] + 1, y[j] - y[i]);
		}
		r[i] = g;
	}
	// for (int i = 0; i < n; ++i) printf("%d ", l[i]); printf("\n");
	// for (int i = 0; i < n; ++i) printf("%d ", r[i]); printf("\n");
	int L = 0, R = (y[n - 1] - y[0]) * 2;
	while (L < R) {
		int M = (L + R) / 2;
		if (check(M)) R = M;
		else L = M + 1;
	}
	printf("%d.%d\n", L / 2, (L & 1) ? 5 : 0);
	return 0;
}
