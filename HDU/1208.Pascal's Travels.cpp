#include <cstdio>
#include <cstring>
using namespace std;
typedef __int64 LL;
const int maxn = 40;
LL dp[maxn][maxn];
char bor[maxn][maxn];
int main()
{
	int n;
	while(~scanf("%d", &n) && n != -1){
		memset(dp, 0, sizeof(dp));
		memset(bor, 0, sizeof(bor));
		for(int i = 0; i < n; ++i){
			scanf(" %s", bor[i]);
		}
		dp[0][0] = 1;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(bor[i][j] - '0'){
					int nx = i + bor[i][j] - '0';
					int ny = j + bor[i][j] - '0';
					
					if(nx < n){
						dp[nx][j] += dp[i][j];
					}
					if(ny < n){
						dp[i][ny] += dp[i][j];
					}
				}
			}
		}
		printf("%I64d\n", dp[n-1][n-1]);
	}
	return 0;	
} 
