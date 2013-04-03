#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, a[100005];
long long ans = 0;
int main(void){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &N);
    a[0] = a[N + 1] = 0;
    for(int i = 1; i <= N; ++i) scanf("%d", &a[i]);
    for(int i = 0; i <= N; ++i) ans += abs(a[i + 1] - a[i]);
    printf("%lld\n", ans / 2);
    return 0;
}
