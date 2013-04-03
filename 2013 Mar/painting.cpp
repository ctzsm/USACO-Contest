#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int INF = 1000000000;

int N;
int a[50005][4];
vector<pair<int, pair<int, bool> > > x;
multiset<pair<int, bool> > y;
bool in[50005];
int main(void){
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
	for(int j = 0; j < 4; ++j)
	    scanf("%d", &a[i][j]);

    for(int i = 0; i < N; ++i){
	x.push_back(make_pair(a[i][0], make_pair(i, true)));
	x.push_back(make_pair(a[i][2], make_pair(i, false)));
    }
    sort(x.begin(), x.end());

    y.insert(make_pair(INF, true));
    int ans = 0;
    for(int i = 0; i < x.size(); ++i){
	int index = x[i].second.first;
	int flag = x[i].second.second;
	if(flag){
	    bool D = (*y.upper_bound(make_pair(a[index][3], false))).second;
	    if(D){
		ans++;
		y.insert(make_pair(a[index][1], true));
		y.insert(make_pair(a[index][3], false));
		in[index] = true;
	    }
	}else{
	    if(in[index]){
		y.erase(y.find(make_pair(a[index][1], true)));
		y.erase(y.find(make_pair(a[index][3], false)));
	    }
	}
    }
    printf("%d\n", ans);
    return 0;
}
