#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 305;

bool judge[maxn][maxn];
pair<int, int> p[maxn];
LL sum[maxn], dp[maxn][maxn];

LL gcd(LL a, LL b) {
	while (b) {
		LL tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum[0] = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d", &p[i].first);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i].second);
			sum[i] = sum[i - 1] + p[i].second;
		}
		
		memset(judge, false, sizeof(judge));
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j)
				judge[i][j] = (gcd(p[i].first, p[j].first) == 1 ? false : true);
		}

		for (int i = n; i >= 1; --i) {
			for (int j = i; j <= n; ++j) {
				dp[i][j] = 0;
				for (int k = i; k < j; ++k)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
				if ((i + 1 == j || dp[i + 1][j - 1] == sum[j - 1] - sum[i]) && judge[i][j])
					dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + p[i].second + p[j].second);
			}
		}
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}