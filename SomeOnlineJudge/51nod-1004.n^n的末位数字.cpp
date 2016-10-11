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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	LL n, m;
	while (cin >> n) {
		LL ans = 1; m = n;
		while (m) {
			if (m & 1) ans = (ans * n) % 10;
			m >>= 1;
			n = (n * n) % 10;
		}
		cout << ans << endl;
	}
	return 0;
}