#include <cstdio>
#include <cstring>
using namespace std;

int num[15];
int dp[15][15][3];
//(i, j, k) = (数位，mod，3种状态（0：末尾不是1，1：末尾是1，2：含有13）)
int dfs(int pos, int mod, int st, int lim) {
	int nn, ans, mod_x, st_x;
	if (pos <= 0) return mod == 0 && st == 2;
	if (!lim && dp[pos][mod][st] != -1) return dp[pos][mod][st];
	nn = lim ? num[pos] : 9;
	ans = 0;
	for (int i = 0; i <= nn; ++i) {
		mod_x = (mod * 10 + i) % 13;
		st_x = st;
		if (st == 0 && i == 1) st_x = 1;
		if (st == 1 && i != 1) st_x = 0;
		if (st == 1 && i == 3) st_x = 2;
		ans += dfs(pos - 1, mod_x, st_x, lim && i == nn);
	}
	if (!lim) dp[pos][mod][st] = ans;
	return ans;
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		memset(dp, -1, sizeof(dp));
		memset(num, 0, sizeof(num));
		int len = 0;
		while (n) {
			num[++len] = n % 10;
			n /= 10;
		}
		printf("%d\n", dfs(len, 0, 0, 1));
	}
	return 0;
}