#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 5;
#define INF 0x3f3f3f3f
int c[maxn], dp[maxn];

int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n, p, r, cas = 1;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &p, &r);
			c[p-1] = r;
		}

		fill(dp, dp + n, INF);
		for(int i = 0; i < n; ++i){
			*lower_bound(dp, dp + n, c[i]) = c[i];
		}

		int ans = lower_bound(dp, dp + n, INF) - dp;
		printf("Case %d:\nMy king, at most %d %s can be built.\n\n", cas, ans, (ans == 1 ? "road" : "roads"));
		++cas;
	}
	return 0;
}