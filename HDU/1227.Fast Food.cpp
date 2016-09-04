#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 200 + 5;
int dp[40][maxn];
int a[maxn], dis[maxn][maxn];
int fun(int x){
	return (x < 0 ? -x : x);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, m, cas = 1;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(dis, 0, sizeof(dis));
		for(int i = 1; i <= n; ++i){
			for(int j = i; j <= n; ++j){
				for(int k = i; k <= j; ++k){
					dis[i][j] += fun(a[k] - a[(i+j)>>1]);
				}
			}
		}
		for(int i = 0; i <= m; ++i){
			for(int j = 1; j <= n; ++j) dp[i][j] = INF;
		}
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				for(int k = i-1; k <= j-1; ++k)
					dp[i][j] = min(dp[i][j], dp[i-1][k] + dis[k+1][j]);
			}
		}
		printf("Chain %d\nTotal distance sum = %d\n\n", cas++, dp[m][n]);
	}
	return 0;
}