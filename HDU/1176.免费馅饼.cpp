#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int maxp = 15;
int tx[maxn][maxp], dp[maxn][maxp];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	int n, p, t;
	while(~scanf("%d", &n) && n){
		memset(tx, 0, sizeof(tx));
		memset(dp, 0, sizeof(dp));
		
		int T = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &p, &t);
			++tx[t][p];
			T = Max(T, t);
		}
		for(int i = T; i >= 0; --i){
			for(int j = 0; j <= 10; ++j){
				int res = 0;
				for(int k = -1; k <= 1; ++k){
					if(j + k >= 0 && j + k <= 10){
						res = Max(dp[i + 1][j + k], res);
					}
				}
				dp[i][j] = res + tx[i][j];
			}
		}
		
		printf("%d\n", dp[0][5]);
	}
	return 0;
}
