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

const int maxn = 505;
int a[maxn][maxn], dp[maxn][maxn];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> a[i][j];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i) dp[n - 1][i] = a[n - 1][i];
		for (int i = n - 2; i >= 0; --i)
			for (int j = i; j >= 0; --j)
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
		cout << dp[0][0] << endl;
	}
	return 0;
}