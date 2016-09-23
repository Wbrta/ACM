#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 12;
const int maxm = (1 << maxn);

int n, m, cur;
long long dp[2][maxm];

void update(int a, int b) {
	if (b & (1 << m)) dp[cur][b ^ (1 << m)] += dp[1 - cur][a];
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		if (n < m) swap(n, m);
		cur = 0;
		memset(dp, 0, sizeof(dp));
		dp[0][(1 << m) - 1] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cur ^= 1;
				memset(dp[cur], 0, sizeof(dp[cur]));
				for (int k = 0; k < (1 << m); ++k) {
					update(k, k << 1);
					if (i && !(k & (1 << m - 1))) update(k, (k << 1) ^ (1 << m) ^ 1);
					if (j && !(k & 1)) update(k, (k << 1) ^ 3);
				}
			}
		}
		printf("%lld\n", dp[cur][(1 << m) - 1]);
	}
	return 0;
}