#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int INF = 0x3f3f3f3f;
const int maxm = (1 << 16) + 10;

int s, m, n;
int tot, vis[10], tt[257];
int a[10], c[maxn], dp[maxm], ss[maxn][10];

bool judge(int a, int b) {
	while (b) {
		if ((b & 1) && !(a & 1)) return false;
		b >>= 1; a >>= 1;
	}
	return true;
}
void dfs(int p, int st, int j) {
	if (p == ss[j][0]) {
		tt[tot++] = st | (1 << (ss[j][p] - 1));
		tt[tot++] = st | (1 << (ss[j][p] - 1 + s));
		return;
	}

	dfs(p + 1, st | (1 << (ss[j][p] - 1)), j);
	dfs(p + 1, st | (1 << (ss[j][p] - 1 + s)), j);
}
int main() {
	while (~scanf("%d%d%d", &s, &m, &n) && s) {
		memset(a, 0, sizeof(a));
		int tmp, ans = 0; char op;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &tmp); ans += tmp;
			while (scanf("%d%c", &tmp, &op) == 2) {
				++a[tmp - 1];
				if (op == '\n') break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &c[i]); int tmp, cnt = 0;
			memset(vis, 0, sizeof(vis));
			while (scanf("%d%c", &tmp, &op) == 2) {
				if (!vis[tmp]) { ss[i][++cnt] = tmp; vis[tmp] = 1; }
				if (op == '\n') break;
			}
			ss[i][0] = cnt;
		}

		int be = 0, st = (1 << (2 * s)) - 1;
		for (int i = 0; i < s; ++i) {
			if (!a[i]) continue;
			else if (a[i] == 1) be += (1 << (i + s));
			else if (a[i] >= 2) be += (1 << i) + (1 << (s + i));
		}

		memset(dp, 0x3f, sizeof(dp));
		dp[be] = 0;
		for (int j = 1; j <= n; ++j) {
			tot = 0;
			dfs(1, 0, j);
			
			for (int i = st; i >= be; --i) {
				if (!judge(i, be)) continue;
				for (int k = 0; k < tot; ++k) {
					if (i == (i | tt[k])) continue;
					dp[i | tt[k]] = min(dp[i | tt[k]], dp[i] + c[j]);
				}
			}
		}
		printf("%d\n", ans + dp[st]);
	}
	return 0;
}