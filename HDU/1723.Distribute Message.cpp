#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 30 + 5;
int dp[maxn];
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		memset(dp, 0, sizeof(dp));
		dp[1] = 1;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(i - j > 0){
					dp[i] += dp[i - j];
				}
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
