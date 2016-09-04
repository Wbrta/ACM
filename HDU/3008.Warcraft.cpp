#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn], a[maxn], b[maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, t, q;
	while(~scanf("%d%d%d", &n, &t, &q)){
		if(n == 0 && t == 0 && q == 0) break;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &a[i], &b[i]);
		}
		a[n] = 0;
		b[n++] = 1;
		memset(dp, -1, sizeof(dp));
		dp[0][100] = 0;
		for(int i = 1; i <= 100; ++i){
			for(int j = 0; j <= 100; ++j){
				int res = -1;
				for(int k = 0; k < n; ++k){
					if(j + a[k] <= 100 && dp[i-1][j+a[k]] != -1)
						res = Max(res, dp[i-1][j+a[k]] + b[k]);
				}

				if(res == -1) continue;
				if(j + t < 100)
					dp[i][j+t] = Max(res, dp[i][j+t]);
				else
					dp[i][100] = Max(res, dp[i][100]);
			}
		}
		int flag = 1, ans = 0;
		for(int i = 1; flag && !ans && i <= 100; ++i){
			for(int j = 0; flag && !ans && j <= 100; ++j){
				if(dp[i][j] == -1) continue;
				// printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
				if(dp[i][j] >= 100){
					ans = i;
					break;
				}
			}
			if(!ans && q * i >= 100){
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("%d\n", ans);
		}else{
			printf("My god\n");
		}
	}
	return 0;
}