#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxm = 40005;
const int maxn = 200005;

set<int> ss;
map<int, map<int, int> > mp;
int dis[maxn];

void bfs(int s, int n) {
	queue<int> q; ss.clear();
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; ++i) {
		if (i == s) continue;
		if (mp[s][i]) {
			dis[i] = -1;
			ss.insert(i);
		} else {
			dis[i] = 1;
			q.push(i);
		}
	}
	int cnt = ss.size();
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (set<int>::iterator it = ss.begin(); it != ss.end(); ++it) {
			int y = *it;
			if (dis[y] != -1 || mp[x][y]) continue;
			dis[y] = dis[x] + 1;
			q.push(y);
			--cnt;
		}
		if (!cnt) return;
	}
}
int main() {
	int n, m, s, u, v, t;
	while (~scanf("%d", &t)) {
		while (t--) {
			mp.clear();
			scanf("%d%d", &n, &m);
			while (m--) {
				scanf("%d%d", &u, &v);
				mp[u][v] = mp[v][u] = 1;
			}
			scanf("%d", &s);
			bfs(s, n);
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (i == s) continue;
				++cnt;
				printf("%d%c", dis[i], (cnt == n - 1) ? '\n' : ' ');
			}
		}
	}
	return 0;
}