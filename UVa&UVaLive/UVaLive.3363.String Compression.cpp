#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 205;
const int INF = 0x3f3f3f3f;

char str[maxn];
int dp[maxn][maxn];

int check(int be, int en, int k) {
	if ((en - be + 1) % k) return 0;
	for (int i = be + k; i <= en; i += k)
		for (int j = 0; j < k; ++j)
			if (str[i + j] != str[be + j]) return 0;
	return (en - be + 1) / k;
}
int getNum(int x) {
	if (x >= 0 && x <= 9) return 1;
	else if (x >= 10 && x <= 99) return 2;
	else return 3;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", str);
		int tmp, len = strlen(str);

		for (int i = 0; i < len; ++i) dp[i][i] = 1;
		for (int i = 0; i < len; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				dp[j][i] = INF;
				for (int k = j; k < i; ++k)
					dp[j][i] = min(dp[j][i], dp[j][k] + dp[k+1][i]);
				for (int k = 1; k <= (i - j + 1) / 2; ++k) {
					int tmp = check(j, i, k);
					if (tmp)
						dp[j][i] = min(dp[j][i], dp[j][j + k - 1] + 2 + getNum(tmp));
				}
			}
		}
		printf("%d\n", dp[0][len-1]);
	}
	return 0;
}