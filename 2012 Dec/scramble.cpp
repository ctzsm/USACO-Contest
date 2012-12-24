#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct cow{
    int id,len;
    char name[21];
    bool operator < (const cow& x) const{
	return strcmp(name, x.name) < 0;
    }
}c[50005];
int N;
int ans[50005][2];
int main(void){
    freopen("scramble.in", "r", stdin);
    freopen("scramble.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0;i < N; ++i) {
	c[i].id = i;
	scanf("%s", c[i].name);
	c[i].len = strlen(c[i].name);
	sort(c[i].name, c[i].name + c[i].len);
    }
    sort(c, c + N);
    for(int i = 0;i < N; ++i) {
	cow t = c[i];sort(t.name, t.name + t.len, greater<char>());
	ans[t.id][1] = upper_bound(c, c + N, t) - c;
    }
    for(int i = 0;i < N; ++i) {
	sort(c[i].name, c[i].name + c[i].len, greater<char>());
    }
    sort(c, c + N);
    for(int i = 0;i < N; ++i) {
	cow t = c[i];sort(t.name, t.name + t.len);
	ans[t.id][0] = lower_bound(c, c + N, t) - c + 1;
    }
    for(int i = 0;i < N; ++i) printf("%d %d\n", ans[i][0], ans[i][1]);
    return 0;
}
