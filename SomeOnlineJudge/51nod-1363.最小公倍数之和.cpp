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

typedef long long LL;
typedef pair<int, int> pi;

const int maxm = 105;
const int maxn = 32000;
const LL mod = 1000000007;

LL ans, cnt;
int p[maxn], g[maxm], gg[maxm];

int scan(){
	int res = 0; char ch;
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + (ch - '0');
	return res;
}
inline void init() {
	memset(p, 0, sizeof(p));
	for (int i = 2; i < maxn; ++i) {
		if (!p[i]) p[++p[0]] = i;
		for (int j = 1; j <= p[0] && p[j] <= maxn / i; ++j) {
			p[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
inline void dfs(LL num, int pos, LL euler) {
	if (pos == cnt) {
		ans = (ans + (num * euler / 2)) % mod;
		return;
	}
	LL tmp = g[pos], eul = g[pos] - 1;
	dfs(num, pos + 1, euler);
	for (int i = 1; i <= gg[pos]; ++i) {
		dfs(num * tmp, pos + 1, euler * eul);
		tmp *= g[pos];
		eul *= g[pos];
	}
}
int main() {
	int a, b, t;
	init();
	t = scan();
	while (t--) {
		ans = cnt = 0;
		memset(gg, 0, sizeof(gg));
		a = scan();
		b = a;
		for (int i = 1; i <= p[0]; ++i) {
			if (b % p[i] == 0) {
				g[cnt] = p[i];
				while (b % p[i] == 0) {
					b /= p[i];
					++gg[cnt];
				}
				++cnt;
			}
		}
		if (b > 1) {
			g[cnt] = b;
			gg[cnt++] = 1;
		}
		dfs(1, 0, 1);
		ans = (a * (ans + 1)) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}