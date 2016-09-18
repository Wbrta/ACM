#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node {
	int v, cap, nxt;
	node(int a = 0, int b = 0, int c = 0) {
		v = a; cap = b; nxt = c;
	}
}Edge;

const int maxn = 1005;
const int maxm = 400005;
const int inf = 0x3f3f3f3f;

Edge vec[maxm];
int cnt, vis[maxn], first[maxn];

int s, t;
Edge edge[maxm];
int tot, cur[maxn], head[maxn], dis[maxn];

void add(int u, int v, int cap) {
	edge[tot] = Edge(v, cap, head[u]);
	head[u] = tot++;
	edge[tot] = Edge(u, 0, head[v]);
	head[v] = tot++;
}
void addEdge(int u, int v, int w) {
	vec[cnt] = Edge(v, w, first[u]);
	first[u] = cnt++;
	vec[cnt] = Edge(u, w, first[v]);
	first[v] = cnt++;
}
void BFS(int n) {
	int x;
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof(vis));

	q.push(1); vis[1] = 1;
	while (!q.empty()) {
		x = q.front(); q.pop();
		for (int i = first[x]; ~i; i = vec[i].nxt) {
			Edge &e = vec[i];
			if (!vis[e.v]) {
				vis[e.v] = vis[x] + 1;
				q.push(e.v);
			}
		}
	}
}
void BuildGraph(int n, int pre) {
	if (dis[n]) return;
	dis[n] = 1;
	for (int i = first[n]; ~i; i = vec[i].nxt) {
		Edge &e = vec[i];
		if (e.v != pre && vis[n] == vis[e.v] + 1) {
			add(e.v, n, e.cap);
			BuildGraph(e.v, n);
		}
	}
}
int bfs() {
	int x;
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(dis, 0, sizeof(dis));
	dis[s] = 1; q.push(s);

	while (!q.empty()) {
		x = q.front(); q.pop();
		for (int i = head[x]; ~i; i = edge[i].nxt) {
			Edge &e = edge[i];
			if (e.cap && dis[e.v] == 0) {
				dis[e.v] = dis[x] + 1;
				q.push(e.v);
			}
		}
	}
	return dis[t];
}
int dfs(int x, int f) {
	int sum = 0;
	if (x == t) return f;
	for (int &i = cur[x]; ~i; i = edge[i].nxt) {
		Edge &e = edge[i];
		if (e.cap && dis[e.v] == dis[x] + 1) {
			int ret = dfs(e.v, min(e.cap, f));
			sum += ret; f -= ret;
			e.cap -= ret; edge[i ^ 1].cap += ret;
		}
	}
	return sum;
}
int dinic() {
	int ret = 0;
	while (bfs()) {
		for (int i = s; i <= t; ++i) cur[i] = head[i];
		ret += dfs(s, inf);
	}
	return ret;
}
int main() {
	int a, b, c, n, m, cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d", &n, &m);

		cnt = 0; tot = 0; s = 1; t = n;
		memset(dis, 0, sizeof(dis));
		memset(head, -1, sizeof(head));
		memset(first, -1, sizeof(first));

		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
		}
		BFS(n);
		BuildGraph(n, n);
		int ans = dinic();
		printf("%d\n", ans);
	}
	return 0;
}