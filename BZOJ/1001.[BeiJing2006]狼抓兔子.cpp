#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
typedef struct node {
    int v, cap, nxt;
    node(int a = 0, int b = 0, int c = 0) {
        v = a; cap = b; nxt = c;
    }
}Edge;
 
const int maxn = 2100005;
const int maxm = 6100005;
const int inf = 0x3f3f3f3f;
 
Edge edge[maxm];
int tot, head[maxn];
int vis[maxn], dis[maxn];
 
void add(int u, int v, int cap) {
    edge[tot] = Edge(v, cap, head[u]);
    head[u] = tot++;
    edge[tot] = Edge(u, cap, head[v]);
    head[v] = tot++;
}
int spfa(int s, int t) {
    int x;
    Edge e;
    queue<int> q;
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
     
    dis[s] = 0; vis[s] = 1; q.push(s);
    while (!q.empty()) {
        x = q.front(); q.pop(); vis[x] = 0;
        for (int i = head[x]; ~i; i = edge[i].nxt) {
            e = edge[i];
            if (dis[x] + e.cap < dis[e.v]) {
                dis[e.v] = dis[x] + e.cap;
                if (!vis[e.v]) {
                    vis[e.v] = 1;
                    q.push(e.v);
                }
            }
        }
    }
    return dis[t];
}
int main() {
    int n, m, u, v, cap;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 1 || m == 1) {
            if (n > m) swap(n, m);
            int ans = inf;
            for (int i = 1, a; i < m; ++i) {
                scanf("%d", &a);
                ans = min(ans, a);
            }
            printf("%d\n", ans == inf ? 0 : ans);
            continue;
        }
        int s = 0, t = (m - 1) * 2 * (n - 1) + 1;
        tot = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m - 1; ++j) {
                scanf("%d", &cap);
                if (i == 1) { u = s; v = 2 * j; }
                else if (i == n) { u = (m - 1) * (n - 2) * 2 + 2 * j - 1; v = t; }
                else { v = (m - 1) * 2 * (i - 2) + 2 * j - 1; u = (m - 1) * 2 * (i - 1) + 2 * j; }
                add(u, v, cap);
                //printf("u = %d, v = %d, cap = %d\n", u, v, cap);
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &cap);
                if (j == 1) { v = t; u = (m - 1)*(i - 1) * 2 + 1; }
                else if (j == m) { u = s; v = (m - 1) * i * 2; }
                else { u = (m - 1) * (i - 1) * 2 + 2 * (j - 1); v = u + 1; }
                add(u, v, cap);
                //printf("u = %d, v = %d, cap = %d\n", u, v, cap);
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                scanf("%d", &cap);
                u = (m - 1) * 2 * (i - 1) + 2 * j - 1; 
                v = u + 1;
                add(u, v, cap);
                //printf("u = %d, v = %d, cap = %d\n", u, v, cap);
            }
        }
        printf("%d\n", spfa(s, t));
    }
    return 0;
}