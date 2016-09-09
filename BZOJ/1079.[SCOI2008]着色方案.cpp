#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 16;
const int mod = 1000000007;

int n, v, c[6];
long long dp[maxn][maxn][maxn][maxn][maxn][6]; //剩下的颜料能涂1个，2个，3个，4个，5个木块，并且上一个颜色是第i类的方案数

long long dfs(int a, int b, int c, int d, int e, int color) {
	long long ans = 0;
	if (dp[a][b][c][d][e][color] != -1) return dp[a][b][c][d][e][color];
	if (a + b + c + d + e == 0) return dp[a][b][c][d][e][color] = 1;
	if (a) ans += (a - (color == 2)) * dfs(a - 1, b, c, d, e, 1);
	if (b) ans += (b - (color == 3)) * dfs(a + 1, b - 1, c, d, e, 2);
	if (c) ans += (c - (color == 4)) * dfs(a, b + 1, c - 1, d, e, 3);
	if (d) ans += (d - (color == 5)) * dfs(a, b, c + 1, d - 1, e, 4);
	if (e) ans += e * dfs(a, b, c, d + 1, e - 1, 5);
	return dp[a][b][c][d][e][color] = ans % mod;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v);
		++c[v];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", dfs(c[1], c[2], c[3], c[4], c[5], 0));
	return 0;
}