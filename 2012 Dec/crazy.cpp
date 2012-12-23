#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<pair<int,int>, vector<int> > pointMap;
pair<pair<int,int>, pair<int,int> > fences[1005];
int cycle[1005];
char parties[1005][1005];
char* partyptrs[1005];
int N,C;
inline bool ptrcmp(char* a, char* b) { return strcmp(a, b) < 0; }

bool rayHits(long long cx, long long cy,
	     long long f1x, long long f1y,
	     long long f2x, long long f2y) {
    if((f1y > cy) ^ (f2y > cy))
	return (f1y - f2y < 0) ^ (f2x * (f1y - cy) + f1x * (cy - f2y) > cx * (f1y - f2y));
    else
	return false;
}

int main(void){
    freopen("crazy.in","r",stdin);
    freopen("crazy.out","w",stdout);
    scanf("%d%d",&N,&C);
    for(int i = 0;i < N; ++i) {
	pair<int,int> p1, p2;
	scanf("%d%d%d%d",&p1.first,&p1.second,&p2.first,&p2.second);
	pointMap[p1].push_back(i);
	pointMap[p2].push_back(i);
	fences[i] = make_pair(p1, p2);
    }
    memset(cycle, -1, sizeof(cycle));
    memset(parties, 0 ,sizeof(parties));

    int nCycles = 0;
    for(int i = 0;i < N; ++i) {
	if(cycle[i] == -1) {
	    int j = i;
	    pair<int,int> last = fences[i].first;
	    do {
		cycle[j] = nCycles;
		last = fences[j].first == last ? fences[j].second : fences[j].first;
		vector<int> const& v = pointMap[last];
		j = v[0] == j ? v[1] : v[0];
	    } while(j != i);
	    nCycles ++;
	}
    }

    for(int i = 0;i < C; ++i){
	int cx, cy; scanf("%d%d", &cx, &cy);
	for(int j = 0;j < N; ++j) {
	    pair<int, int>& p1 = fences[j].first;
	    pair<int, int>& p2 = fences[j].second;
	    parties[i][cycle[j]] ^=
		(char)rayHits(cx, cy, p1.first, p1.second, p2.first, p2.second);
	}
	for(int j = 0;j < nCycles; ++j)
	    parties[i][j] = parties[i][j] ? '1' : '0';
	parties[i][nCycles] = '\0';
    }
    for(int i = 0;i < C; ++i) partyptrs[i] = parties[i];
    sort(partyptrs, partyptrs + C, ptrcmp);
    int ans = 0, cnt = 0;
    for(int i = 0;i < C; ++i) {
	if(i == 0 || strcmp(partyptrs[i], partyptrs[i - 1]) != 0) cnt = 1;
	else cnt++;
	ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
