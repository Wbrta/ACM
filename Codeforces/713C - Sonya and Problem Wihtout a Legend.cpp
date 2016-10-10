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

const int maxn = 3005;
const LL inf = 1e18 + 5;
LL a[maxn], b[maxn], f[maxn], dp[maxn][maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = a[i] - i;
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	fill(f, f + n + 1, inf);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = (i == 1 ? 0 : f[j]) + fun(a[i] - b[j]);
			f[j] = min(f[j - 1], dp[i][j]);
		}
	}
	cout << f[n] << endl;
	//system("pause");
	return 0;
}