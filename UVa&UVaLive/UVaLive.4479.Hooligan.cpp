#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
#define DEBUG 1

typedef struct node {
	int v, cap, nxt;
	node(int a = 0, int b = 0, int c = 0) {
		v = a; cap = b; nxt = c;
	}
}Edge;

const int maxn = 45;
const int maxm = 100005;
const int INF = 0x3f3f3f3f;

Edge edge[maxm];
int tot, s, t, n, m, g;
int head[maxn], dis[maxn], value[maxn][maxn], sc[maxn];

inline int Min(int a, int b) {
	return (a < b ? a : b);
}
inline void add(int u, int v, int cap) {
	edge[tot] = Edge(v, cap, head[u]);
	head[u] = tot++;
	edge[tot] = Edge(u, 0, head[v]);
	head[v] = tot++;
}
int bfs() {
	queue<int> q;
	while (!q.empty()) q.pop();
	memset(dis, 0, sizeof(dis));
	q.push(s); dis[s] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == t) break;
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
	if (x == t) return f;
	int sum = 0;
	for (int i = head[x]; ~i; i = edge[i].nxt) {
		Edge &e = edge[i];
		if (e.cap && dis[e.v] == dis[x] + 1) {
			int ret = dfs(e.v, Min(e.cap, f));
			sum += ret; f -= ret;
			e.cap -= ret; edge[i ^ 1].cap += ret;
		}
	}
	return sum;
}
void solve() {
	for (int i = 1; i < n; ++i)
		sc[0] += (m - value[0][i]) * 2;
	for (int i = 1; i < n; ++i)
		if (sc[i] >= sc[0]) { cout << "N" << endl; return;}
	for (int i = 1; i < n; ++i) 
		for (int j = 1; j < i; ++j) 
			value[i][j] = (m - value[i][j]) * 2;
	tot = 0; s = 0; t = n;
	memset(head, -1, sizeof(head));
	for (int i = 1; i < n; ++i) {
		add(i, t, sc[0] - sc[i] - 1);
		for (int j = 1; j < i; ++j) {
			if (value[i][j] > 0) {
				add(s, i, value[i][j]);
				add(i, j, value[i][j]);
			}
		}
	}

	while (bfs()) dfs(s, INF);
	for (int i = head[s]; ~i; i = edge[i].nxt) {
		Edge &e = edge[i];
		if (e.cap != 0) {cout << "N" << endl; return;}
	}
	cout << "Y" << endl;
}
int main() {
	char op;
	int a, b;
	while (cin >> n >> m >> g) {
		if (n == 0 && m == 0 && g == 0) break;
		memset(sc, 0, sizeof(sc));
		memset(value, 0, sizeof(value));
		for (int i = 0; i < g; ++i) {
			cin >> a >> op >> b;
			value[b][a] = value[a][b] = value[a][b] + 1;
			if (op == '=') {
				sc[a] += 1; sc[b] += 1;
			} else if (op == '<') {
				sc[b] += 2;
			}
		}
		solve();
	}
	return 0;
}