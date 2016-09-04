#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int num[maxn][maxn], dp[maxn][maxn];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	int c, n;
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= i; ++j){
				scanf("%d", &num[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		for(int i = n - 1; i >= 0; --i){
			for(int j = 0; j <= i; ++j){
				dp[i][j] = Max(dp[i+1][j], dp[i+1][j+1]) + num[i][j];
			}
		}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
