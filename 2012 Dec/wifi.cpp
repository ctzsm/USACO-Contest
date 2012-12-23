#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;


int N;
long long A, B;
long long cow[2005];
long long dp[2005];

long long DP(int id){
    if(dp[id] != -1) return dp[id];
    long long res = 0x3fffffffffffffffLL;
    for(int i = id;i <= N; ++i)
	res = min(res, A + B * (cow[i] - cow[id]) / 2 + DP(i + 1));
    return dp[id] = res;
}
int main(void) {
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);
    cin >> N >> A >> B; A <<= 1;
    for(int i = 1;i <= N; ++i){ cin >> cow[i]; cow[i] <<= 1; }
    sort(cow + 1,cow + N + 1);
    memset(dp,-1,sizeof(dp));dp[N + 1] = 0;
    long long ans = DP(1);
    if (ans & 1) cout << (ans / 2) << ".5" << endl;
    else cout << (ans / 2) << endl;
    return 0;
}
