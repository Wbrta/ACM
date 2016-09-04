#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int dp[maxn];
int cost[maxn], w[maxn], t[maxn];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	freopen("test.in", "r+", stdin);
	freopen("test.out", "w+", stdout);

	int C, n, m;
	scanf("%d", &C);
	while(C--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &cost[i], &w[i], &t[i]);
		}

		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < m; ++i){
			int tmp = 1;
			while(t[i]){
				if(tmp > t[i]) tmp = t[i];
				t[i] -= tmp;

				for(int j = n; j >= tmp * cost[i]; --j){
					dp[j] = Max(dp[j], dp[j - tmp * cost[i]] + tmp * w[i]);
				}
				tmp <<= 1;
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}