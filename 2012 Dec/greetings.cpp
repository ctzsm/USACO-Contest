#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int B, E;
int position[1000005][2]; // Notice the total time is less than 10^6.
int read(int cow,int N){
    char s[2];int x, d, res = 0;
    for(int i = 1;i <= N; ++i) {
	scanf("%d%s", &x, s);
	if(s[0] == 'L') d = -1;
	else d = 1;
	for(int j = res + 1;j <= res + x; ++j) position[j][cow] = position[j - 1][cow] + d;
	res += x;
    }
    return res;
}
int main(void){
    freopen("greetings.in", "r", stdin);
    freopen("greetings.out", "w", stdout);
    scanf("%d%d", &B, &E);
    int lB = read(0, B);
    int lE = read(1, E);
    int limit = max(lB, lE);
    for(int i = lB + 1; i <= limit; ++i) position[i][0] = position[i - 1][0];
    for(int i = lE + 1; i <= limit; ++i) position[i][1] = position[i - 1][1];
    int ans = 0;
    for(int i = 1;i <= limit; ++i)
	ans += (position[i][0] == position[i][1] && position[i - 1][0] != position[i - 1][1]);
    printf("%d\n", ans);
    return 0;
}

// The official solution used sorting method which can deal larger data.
