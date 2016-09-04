#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 105;

char str[maxn];
int dp[maxn][maxn];
map<char, char> mp;

bool check(int l, int r) {
	if (mp[str[l]] == str[r]) return true;
	else return false;
}
int dfs(int l, int r) {
	if (l > r) return 0;
	if (l < 0 || r < 0) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) return dp[l][r] = 0;

	for (int i = l; i < r; ++i)
		dp[l][r] = max(dp[l][r], dfs(l, i) + dfs(i + 1, r));
	if (check(l, r)) dp[l][r] = max(dp[l][r], dfs(l + 1, r - 1) + 2);
	else dp[l][r] = max(dp[l][r], dfs(l + 1, r - 1));
	//printf("dp[%d][%d] = %d\n", l, r, dp[l][r]);
	return dp[l][r];
}
int main() {
	mp['('] = ')'; mp['['] = ']'; mp[')'] = '#'; mp[']'] = '$';
	while (~scanf(" %s", str) && strcmp(str, "end") != 0) {
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(0, strlen(str) - 1));
	}
	return 0;
}