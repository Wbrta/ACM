#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10005;
const int inf = 0x3f3f3f3f;

typedef struct node {
	int id;
	int num;
}Gao;

int n, mi;
int vis[maxn];
Gao gao[maxn];

bool cmp(const Gao a, const Gao b) {
	return a.num < b.num;
}
int solve() {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		int cnt = 1;
		int l = gao[i].id;
		int m = gao[i].num;
		int sum = gao[i].num;
		
		while (l != i) {
			vis[l] = 1;
			++cnt;
			sum += gao[l].num;
			if (m > gao[l].num) m = gao[l].num;
			l = gao[l].id;
		}
		ans = ans + min(sum - m + m * (cnt - 1), sum + m + (cnt + 1) * mi);
	}
	return ans;
}
int main() {
	while (~scanf("%d", &n)) {
		mi = inf;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &gao[i].num);
			gao[i].id = i;
			if (mi > gao[i].num) mi = gao[i].num;
		}
		sort(gao, gao + n, cmp);
		printf("%d\n", solve());
	}
	return 0;
}