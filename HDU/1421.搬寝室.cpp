#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
typedef int LL;
const int maxn = 2100;
LL w[maxn], ww[maxn], dp[maxn][maxn];

inline LL fun(LL x){
	return x * x;
}
inline LL Min(LL x, LL y){
	return (x < y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	LL n, k;
	while(~scanf("%d%d", &n, &k)){
		for(int i = 1; i <= n; ++i){
			scanf("%d", &w[i]);
		}
		sort(w + 1, w + n + 1);
		memset(dp, 0, sizeof(dp));
		for(int j = 1; j <= k; ++j){
			for(int i = 2 * j; i <= n; ++i){
				if(i == 2 * j){
					dp[i][j] = dp[i-2][j-1] + fun(w[i] - w[i-1]);
				}else if(i > 2 * j){
					dp[i][j] = Min(dp[i-1][j], dp[i-2][j-1] + fun(w[i] - w[i-1]));
				}
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}
