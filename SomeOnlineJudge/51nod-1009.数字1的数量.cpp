#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define mp make_pair
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define fun(x) ((x) >= 0 ? (x) : -(x))

typedef long long LL;
typedef pair<int, int> pi;

int num[12], dp[15];
int pow(int x) {
	int ans = 1;
	for (int i = 0; i < x; ++i)
		ans *= 10;
	return ans;
}
int dfs(int pos, bool lim) {
	if (pos <= 0) return 0;
	if (!lim && dp[pos] != -1) return dp[pos];
	int ans = 0, nn = lim ? num[pos] : 9;
	for (int i = 0; i <= nn; ++i) {
		if (i == 1) {
			if (lim && i == nn) {
				int res = 0;
				for (int i = pos - 1; i > 0; --i) {
					res *= 10;
					res += num[i];
				}
				ans += res + 1;
			} else ans += pow(pos - 1);
		}
		ans += dfs(pos - 1, lim && i == nn);
	}
	if (!lim) dp[pos] = ans;
	return ans;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, len;
	while (cin >> n) {
		len = 0;
		while (n) {
			num[++len] = n % 10;
			n /= 10;
		}
		memset(dp, -1, sizeof(dp));
		cout << dfs(len, true) << endl;
	}
	return 0;
}