#include <cstdio>
#include <cstring>
using namespace std;

int dp[10][10];

void init() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 7; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 4) continue;
			for (int k = 0; k < 10; ++k) {
				if (k == 4 || (j == 6 && k == 2)) continue;
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
int solve(int n) {
	int num[10] = { 0 };
	int ans = 0, len = 0;

	while (n) {
		num[++len] = n % 10;
		n /= 10;
	}
	num[len + 1] = 0;
	
	for (int i = len; i > 0; --i) {
		for (int j = 0; j < num[i]; ++j) {
			if (j != 4 && !(num[i + 1] == 6 && j == 2))
				ans += dp[i][j];
		}
		if (num[i] == 4 || (num[i] == 2 && num[i + 1] == 6))
			break;
	}
	return ans;
}
int main() {
	int n, m; init();
	while (~scanf("%d%d", &n, &m)) {
		if (!n && !m) break;
		printf("%d\n", solve(m + 1) - solve(n));
	}
	return 0;
}