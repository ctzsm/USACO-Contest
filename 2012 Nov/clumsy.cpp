#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

char s[100005];
int main(void){
    freopen("clumsy.in","r",stdin);
    freopen("clumsy.out","w",stdout);
    scanf("%s",s);
    int len = strlen(s),sum = 0,ans = 0;
    for(int i = 0;i < len; ++i){
	if(s[i] == '(')  sum++;
	else sum--;
	if(sum < 0){
	    sum = 1;
	    ans++;
	}
    }
    ans += sum / 2;
    printf("%d\n",ans);
    return 0;
}
