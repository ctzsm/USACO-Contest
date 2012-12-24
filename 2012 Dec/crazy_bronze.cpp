#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
int x[3005], y[3005], t[3005];
int xz, yz, gz, n, c;
char arr[6005][6005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int compress(int a[], int z) {
    memcpy(t, a, sizeof(t));
    sort(t, t + z);
    int nz = unique(t, t + z) - t;
    for(int i = 0;i < z; ++i)
	a[i] = (lower_bound(t, t + nz, a[i]) - t) * 2;
    return nz * 2;
}
void dfs(int x,int y){
    if(x < 0 || x >= xz || y < 0 || y >= yz) return;
    if(arr[x][y] == 'X') return;
    gz += (arr[x][y] == 'C');
    arr[x][y] = 'X';
    for(int i = 0;i < 4; ++i) dfs(x + dx[i], y + dy[i]);
}
int main(void) {
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
    scanf("%d%d", &n, &c);
    int z = 0;
    x[z] = y[z] = -inf; z++;
    x[z] = y[z] = inf; z++;
    for(int i = 0;i < n * 2; ++i){
	scanf("%d%d", &x[z], &y[z]); z++;
    }
    for(int i = 0;i < c; ++i){
	scanf("%d%d", &x[z], &y[z]); z++;
    }
    xz = compress(x, z);
    yz = compress(y, z);

    for(int i = 0;i < n; ++i){
	int a = i * 2 + 2;
	int b = i * 2 + 3;
	int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
	if(x1 == x2) {
	    if(y1 > y2) swap(y1, y2);
	    while(y1 <= y2) arr[x1][y1++] = 'X';
	}else{
	    if(x1 > x2) swap(x1, x2);
	    while(x1 <= x2) arr[x1++][y1] = 'X';
	}
    }

    for(int i = 0;i < c; ++i) {
	int a = i + 2 * n + 2;
	arr[x[a]][y[a]] = 'C';
    }
    int ans = 0;
    for(int i = 0;i < c; ++i) {
	int a = i + 2 * n + 2;
	gz = 0;
	dfs(x[a], y[a]);
	ans = max(ans, gz);
    }
    printf("%d\n", ans);
    return 0;
}

// This code is almost copied from the official solution.
// The original code was written by Johnny Ho.
