#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 150;
const int INF = 0x3f3f3f3f;
const int maxs = (1 << 11) + 11;

int n, m;
int st[maxn];
char str[maxn];
int dp[maxs][maxs];

int dfs(int status, int res) {
	if (dp[status][res] != -1) return dp[status][res];
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if ((st[i] & status) == res) ++cnt;
	}
	if (cnt <= 1) return dp[status][res] = 0;

	int ans = INF;
	for (int i = 0; i < m; ++i) {
		if (status & (1 << i)) continue;
		dp[status | (1 << i)][res] = dfs(status | (1 << i), res);
		dp[status | (1 << i)][res | (1 << i)] = dfs(status | (1 << i), res | (1 << i));
		ans = min(ans, max(dp[status | (1 << i)][res], dp[status | (1 << i)][res | (1 << i)]) + 1);
	}
	return dp[status][res] = ans;
}
int main() {
	while (~scanf("%d%d", &m, &n)) {
		if (!n && !m) break;
		memset(st, 0, sizeof(st));
		for (int i = 0; i < n; ++i) {
			scanf(" %s", str);
			for (int j = 0; j < m; ++j) {
				if(str[j] == '1')
					st[i] |= (1 << j);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}