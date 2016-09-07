#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;
namespace NetworkFlow {
    const int maxn = 505;
    const int maxm = 100005;
    const int INF = 0x3f3f3f3f;

    typedef struct node {
        int v, cap, nxt;
        node(int a = 0, int b = 0, int c = 0) {
            v = a; cap = b; nxt = c;
        }
    }Edge;

    int tot;
    int dp[maxn];
    Edge edge[maxm];
    int head[maxn], lev[maxn];
    int g[maxn][maxn], dis[maxn], vis[maxn];

    void init() {
        tot = 0;
        memset(dp, 0, sizeof(dp));
        memset(head, -1, sizeof(head));
        for(int i = 0; i < maxn; ++i)
            for(int j = 0; j < maxn; ++j)
                g[i][j] = INF;
    }
    void add(int u, int v, int cap) {
        edge[tot] = Edge(v, cap, head[u]);
        head[u] = tot++;
        edge[tot] = Edge(u, 0, head[v]);
        head[v] = tot++;
    }
    void dfsPath(int p) {
        if(dp[p]) return;
        if (p == 1) {
            dp[1] = 1;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (g[i][p] + dis[i] == dis[p]) {
                add(i, p, 1);
                dfsPath(i);
                dp[p] += dp[i];
            }
        }
    }
    void dijkstra() {
        for (int i = 2; i <= n; ++i) {
            dis[i] = g[1][i];
            vis[i] = 0;
        }
        dis[1] = 0; vis[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int k, mi = INF;
            for (int j = 2; j <= n; ++j) {
                if (!vis[j] && dis[j] < mi) {
                    mi = dis[j];
                    k = j;
                }
            }
            vis[k] = 1;
            for (int j = 2; j <= n; ++j) {
                if (!vis[j] && dis[k] + g[k][j] < dis[j]) {
                    dis[j] = dis[k] + g[k][j];
                }
            }
        }
    }
    int bfs() {
        queue<int> q;
        while (!q.empty()) q.pop();
        memset(lev, 0, sizeof(lev));
        q.push(1); lev[1] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = head[x]; ~i; i = edge[i].nxt) {
                Edge &e = edge[i];
                if (e.cap && lev[e.v] == 0) {
                    q.push(e.v);
                    lev[e.v] = lev[x] + 1;
                }
            }
        }
        return lev[n];
    }
    int dfs(int x, int f) {
        if (x == n) return f;
        int sum = 0;
        for (int i = head[x]; ~i; i = edge[i].nxt) {
            Edge &e = edge[i];
            if (e.cap && lev[e.v] == lev[x] + 1) {
                int ret = dfs(e.v, min(e.cap, f));
                sum += ret; f -= ret;
                e.cap -= ret; edge[i ^ 1].cap += ret;
            }
        }
        return sum;
    }
    void solve(){
        dijkstra();
        dfsPath(n);
        printf("%d\n", dp[n]);
        int ret = 0;
        while (bfs()) ret += dfs(1, INF);
        printf("%d\n", ret);
    }
}
namespace SAT2 {
    typedef struct node {
        int v, nxt;
        node(int a = 0, int b = 0) {
            v = a; nxt = b;
        }
    }Edge;

    const int maxn = 1005;
    const int maxm = 200005;

    stack<int> s;
    int in[maxn];
    int head[maxn];                    //前向星头
    Edge edge[maxm];                //前向星存边
    int inx, cnt, tot;                //强连通索引号，强连通分量数量，前向星索引号
    vector<int> vec[maxn];            //邻接表存储强连通分量缩点后的图
    int color[maxn], f[maxn];        //强连通分量缩点后染色方案，各个点相互关系
    int low[maxn], dfn[maxn];        //最小可以回溯的点，dfs层次号
    int ins[maxn], ans[maxn];        //是否在栈中，在哪个强连通分量中

    void init() {
        inx = cnt = tot = 0;
        while (!s.empty()) s.pop();
        memset(in, 0, sizeof(in));
        memset(ans, 0, sizeof(ans));
        memset(dfn, 0, sizeof(dfn));
        memset(ins, 0, sizeof(ins));
        memset(low, 0, sizeof(low));
        memset(head, -1, sizeof(head));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < maxn; ++i) vec[i].clear();
    }
    void add(int u, int v) {
        edge[tot] = Edge(v, head[u]);
        head[u] = tot++;
    }
    void tarjan(int x) {                //求强连通分量
        s.push(x);
        ins[x] = 1;
        low[x] = dfn[x] = ++inx;

        int v;
        for (int i = head[x]; ~i; i = edge[i].nxt) {
            v = edge[i].v;
            if (!dfn[v]) {
                tarjan(v);
                low[x] = min(low[x], low[v]);
            }
            else if (ins[v]) low[x] = min(low[x], dfn[v]);
        }

        if (low[x] == dfn[x]) {
            ++cnt;
            while (!s.empty()) {
                v = s.top(); s.pop();
                ins[v] = 0;
                ans[v] = cnt;
                if (v == x) break;
            }
        }
    }
    void buildGraph(int n) {         //建立新的图
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = head[i]; ~j; j = edge[j].nxt) {
                int v = edge[j].v;
                if (ans[v] != ans[i]) {
                    vec[ans[v]].push_back(ans[i]);
                    ++in[ans[i]];
                }
            }
        }
    }
    void toposort(int n) {           //拓扑排序
        int v, u, len;
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            v = q.front(); q.pop();
            if (!color[v]) {
                color[v] = 1;
                color[f[v]] = 2;
            }

            len = vec[v].size();
            for (int i = 0; i < len; ++i) {
                u = vec[v][i];
                --in[u];
                if (!in[u]) q.push(u);
            }
        }
    }
    void solve(int n) {
        for (int i = 0; i < 2 * n; ++i) {
            if (!dfn[i]) tarjan(i);
        }
        for (int i = 0; i < 2 * n; i += 2) {
            if (ans[i] == ans[i ^ 1]) {
                puts("impossible.");
                return;
            }
            else {
                f[ans[i]] = ans[i ^ 1];
                f[ans[i ^ 1]] = ans[i];
            }
        }
        buildGraph(n);
        toposort(cnt);
        for (int i = 0; i < 2 * n; i += 2) {
            if(i) printf(" ");
            if (color[ans[i]] == 1) printf("1");
            else printf("0");
        }
        puts("");
    }
}
int main() {
    int a, b, w, t;
    scanf("%d", &t);
    while(t--){
        SAT2::init();
        NetworkFlow::init();
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &a, &b, &w);
            NetworkFlow::g[a][b] = w;
            NetworkFlow::g[b][a] = w;
        }
        for(int i = 0; i < k; ++i){
            scanf("%d%d%d", &w, &a, &b);
            --a; --b;
            a *= 2; b *= 2;
            if(w == 1){
                SAT2::add(a, b);
                SAT2::add(b ^ 1, a ^ 1);
            }else if(w == 2){
                SAT2::add(a ^ 1, b);
                SAT2::add(b ^ 1, a);
            }else if(w == 3){
                SAT2::add(a, b ^ 1);
                SAT2::add(b, a ^ 1);
            }else if(w == 4){
                SAT2::add(a ^ 1, b);
                SAT2::add(b ^ 1, a);
            }else{
                SAT2::add(a, b);
                SAT2::add(a ^ 1, b ^ 1);
                SAT2::add(b, a);
                SAT2::add(b ^ 1, a ^ 1);
            }
        }
        SAT2::solve(n);
        NetworkFlow::solve();
    }
    return 0;
}