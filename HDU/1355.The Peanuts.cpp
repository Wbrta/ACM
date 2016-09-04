#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 3000 + 5;
struct Peanuts{
	int x, y;
	int val;
}pnt[maxn];
bool cmp(Peanuts a, Peanuts b){
	return a.val > b.val;
}
inline int f(int x){
	return x > 0 ? x : -x;
}
int main()
{
	int cas, n, m, k;
	scanf("%d", &cas);
	while(cas--){
		int tt, cur = 0;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				scanf("%d", &tt);
				pnt[cur].x = i;
				pnt[cur].y = j;
				pnt[cur++].val = tt;
			}
		}
		sort(pnt, pnt + cur, cmp);
		
		int ans = 0, time = 0, nx = 0, ny = pnt[0].y;
		for(int i = 0; i < cur; ++i){
			time += f(pnt[i].x - nx) + f(pnt[i].y - ny);
			++time;
			time += pnt[i].x;
			
			if(time <= k){
				ans += pnt[i].val;
				time -= pnt[i].x;
				
				nx = pnt[i].x;
				ny = pnt[i].y;
			}else break;
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
