#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 15;
const int maxm = 1000;
int dp[maxn][maxm], num[maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
inline int Min(int x, int y){
	return (x < y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, h, s, f, len;
	while(~scanf("%d", &n) && n){
		scanf("%d%d%d", &h, &s, &f);

		len = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &num[i]);
			len = Max(len, num[i]);
		}

		for(int j = num[0]; j <= len; ++j){
			dp[0][j] = j * (s + h);
		}
		for(int i = 1; i < n; ++i){
			for(int j = num[i]; j <= len; ++j){
				int res = INF;
				for(int k = num[i-1]; k <= len; ++k){
					if(j >= k){
						res = Min(res, (j - k) * h + j * s + dp[i-1][k]);
					}else{
						res = Min(res, (k - j) * f + j * s + dp[i-1][k]);
					}
				}
				dp[i][j] = res;
			}
		}
		int ans = INF;
		for(int i = num[n-1]; i <= len; ++i){
			ans = Min(dp[n-1][i], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}