#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;

const int inf = 1e18 + 5;
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

LL n, ans;
void dfs(int dep, LL tmp, int num) {
	if (num > n) return;
	if (num == n && tmp < ans) ans = tmp;
	for (int i = 1; i <= 63; ++i) {
		if (ans / prime[dep] < tmp) break;
		dfs(dep + 1, tmp *= prime[dep], num * (i + 1));
	}
}
int main() {
	while (~scanf("%I64d", &n)) {
		ans = inf;
		dfs(0, 1, 1);
		printf("%I64d\n", ans);
	}
	return 0;
}