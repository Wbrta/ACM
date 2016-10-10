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

const int maxn = 1e6 + 5;
const int mod = 1000000007;

int p[maxn];
void init() {
	memset(p, 0, sizeof(p));
	for (int i = 2; i < maxn; ++i) {
		if (!p[i]) p[++p[0]] = i;
		for (int j = 1; j <= p[0] && p[j] <= maxn / i; ++j) {
			p[p[j] * i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int main(){
	LL n, t; init();
	scanf("%lld", &t);
	while (t--) {
		LL ans = 1;
		scanf("%lld", &n);
		for (int i = 1; i <= p[0]; ++i) {
			if (n % p[i] == 0) {
				ans = (ans * (p[i] + 1)) % mod;
				while (n % p[i] == 0) n /= p[i];
			}
		}
		if (n != 1) ans = (ans * (n + 1)) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}