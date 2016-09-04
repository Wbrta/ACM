#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 500 + 5;
int c[maxn], res[maxn], dp[maxn][maxn];
int main()
{
	int n, K;
	scanf("%d%d", &n, &K);
	for(int i = 0; i < n; ++i){
		scanf("%d", &c[i]);
	}
	sort(c, c + n);
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = K; j >= c[i]; --j){
			for(int k = 0; k + c[i] <= K; ++k){
				if(dp[j - c[i]][k]) dp[j][k] = dp[j][k + c[i]] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= K; ++i)
		if(dp[K][i]) res[ans++] = i;
	printf("%d\n", ans);
	for(int i = 0; i < ans; ++i){
		printf("%d%c", res[i], (i == (ans - 1) ? '\n' : ' '));
	}
	return 0;
}
