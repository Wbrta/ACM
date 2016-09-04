#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int maze[25][1005], dp[25][1005];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	int c, n, m;
	scanf("%d", &c);
	while(c--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				scanf("%d", &maze[i][j]);
			}
		}
		
		for(int i = 0; i <= n; ++i) dp[i][0] = -INF;
		for(int i = 0; i <= m; ++i) dp[0][i] = -INF;
		dp[0][0] = dp[0][1] = dp[1][0] = 0;
				
		int ans;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				ans = Max(dp[i-1][j], dp[i][j-1]);
				for(int k = 2; k <= j; ++k){
					if(j % k == 0)
						ans = Max(ans, dp[i][ ( j / k ) ]);
				}
				dp[i][j] = ans + maze[i][j];
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
