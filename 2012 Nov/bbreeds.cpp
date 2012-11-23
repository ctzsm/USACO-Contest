#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 2012;

char s[1005];
int dp[1005][1005];

int main(void){
    freopen("bbreeds.in","r",stdin);
    freopen("bbreeds.out","w",stdout);
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    dp[0][1] = 1;
    int L = 0;
    for(int i = 1;i <= n; ++i){
	if(s[i] == '('){
	    L ++;
	    for(int j = 1;j <= L + 1; ++j) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
	}else{
	    L --;
	    for(int j = 1;j <= L + 1; ++j) dp[i][j] = (dp[i-1][j+1] + dp[i-1][j]) % mod;
	}
    }
    printf("%d\n",L == 0 ? dp[n][1] : 0);
    return 0;
}
