#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;
LL dp[21][10];
void init() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 20; ++i) {
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k) {
				if (j == 4 && k == 9) continue;
				dp[i][j] += dp[i - 1][k];
			}
	}
}
LL solve(LL n) {
	LL ans = 0;
	int len = 0;
	int num[30] = { 0 };

	while (n) {
		num[++len] = n % 10;
		n /= 10;
	}
	num[len + 1] = 0;

	for (int i = len; i > 0; --i) {
		for (int j = 0; j < num[i]; ++j) {
			if (num[i + 1] == 4 && j == 9) continue;
			ans += dp[i][j];
		}
		if (num[i + 1] == 4 && num[i] == 9) break;
	}
	return ans;
}
int main() {
	LL n, t; init();
	while (~scanf("%lld", &t)) {
		while (t--) {
			scanf("%lld", &n);
			printf("%lld\n", n - solve(n + 1) + 1);
		}
	}
	return 0;
}