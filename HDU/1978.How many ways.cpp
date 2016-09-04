#include <cstdio>
#include <cstring>
using namespace std;
#define mod 10000
const int maxn = 100 + 5;
int mm[maxn][maxn], dp[maxn][maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n, m, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				scanf("%d", &mm[i][j]);
			}
		}

		dp[0][0] = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				for(int a = 0; a <= mm[i][j]; ++a){
					for(int b = 0; b <= mm[i][j]; ++b){
						if(a == 0 && b == 0) continue;
						if(a + b > mm[i][j]) continue;
						if(i + a >= n || j + b >= m) continue;

						dp[i + a][j + b] = (dp[i][j] + dp[i + a][j + b]) % mod;
					}
				}
			}
		}

		// for(int i = 0; i < n; ++i){
		// 	for(int j = 0; j < m; ++j){
		// 		printf("%d ", dp[i][j]);
		// 	}
		// 	puts("");
		// }
		printf("%d\n", dp[n-1][m-1]);
	}
	return 0;
}