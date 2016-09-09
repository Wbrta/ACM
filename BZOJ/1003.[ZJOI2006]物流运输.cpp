#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node {
	int v, nxt;
	long long cap;
	node(int a = 0, int b = 0, long long c = 0) {
		v = a; nxt = b; cap = c;
	}
}Edge;

const int maxn = 25;
const int maxm = 405;
const int inf = 0x3f3f3f3f;

set<int> s;
Edge edge[maxm];
int ban[maxn][105];
int a, b, c, d, n, m, K, e;
int tot, vis[maxn], head[maxn];
long long dis[maxn], f[105], cost[105][105];

void add(int u, int v, long long w) {
	edge[tot] = Edge(v, head[u], w);
	head[u] = tot++;
	edge[tot] = Edge(u, head[v], w);
	head[v] = tot++;
}
void spfa() {
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	q.push(1);
	dis[1] = 0; vis[1] = 1;

	while (!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = head[x]; ~i; i = edge[i].nxt) {
			Edge e = edge[i];
			if (s.find(e.v) == s.end() && dis[e.v] > dis[x] + e.cap) {
				dis[e.v] = dis[x] + e.cap;
				if (!vis[e.v]) {
					vis[e.v] = 1;
					q.push(e.v);
				}
			}
		}
	}
}
int main() {
	tot = 0;
	memset(head, -1, sizeof(head));

	scanf("%d%d%d%d", &n, &m, &K, &e);
	for (int i = 0; i < e; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	scanf("%d", &d);
	for (int i = 0; i < d; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		for (int j = b; j <= c; ++j)
			ban[a][j] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			s.clear();
			for (int k = 2; k < m; ++k)
				for (int kk = i; kk <= j; ++kk)
					if (ban[k][kk]) s.insert(k);
			spfa();
			cost[i][j] = dis[m] * (dis[m] >= inf ? 1 : (j - i + 1));
		}
	}
	f[0] = -K;
	for (int i = 1; i <= n; ++i) {
		f[i] = inf;
		for (int j = 0; j < i; ++j)
			f[i] = min(f[i], f[j] + cost[j + 1][i] + K);
	}
	printf("%lld\n", f[n]);
	//system("pause");
	return 0;
}