#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1005;

int n, s;
int a[maxn], b[maxn], c[maxn];

int solve() {
	int cnt = 0, flag = 1;
	while (flag) {
		++cnt;
		for (int i = 1; i <= n; ++i)
			b[i] = c[c[i]];
		for (int i = 1; i <= n; ++i)
			if (b[i] == a[i]) flag = 0;
		if (!flag) break;
		for (int i = 1; i <= n; ++i)
			c[i] = b[i];
	}
	return cnt;
}
int main() {
	while (~scanf("%d%d", &n, &s)) {
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			b[i] = a[i];
			c[i] = a[i];
		}
		int cnt = solve();
		s %= cnt;
		s = cnt - s;
		while (s--) {
			for (int i = 1; i <= n; ++i)
				b[i] = a[a[i]];
			for (int i = 1; i <= n; ++i)
				a[i] = b[i];
		}
		for (int i = 1; i <= n; ++i)
			printf("%d\n", b[i]);
	}
	return 0;
}