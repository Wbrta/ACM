#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node{
    int v, cap, nxt;
    node(int a = 0, int b = 0, int c = 0){
        v = a; cap = b; nxt = c;
    }
}Edge;
typedef struct aaa{
    int from, to, val;
    aaa(int a = 0, int b = 0, int c = 0){
        from = a; to = b; val = c;
    }
}ANS;

const int maxn = 150;
const int maxm = 2e4 + 10;
const int INF = 0x3f3f3f3f;

int tot, s, t;
ANS ans[maxm];
Edge edge[maxm];
int head[maxn], dis[maxn], value[maxn][maxn];
int a[maxn], st1[maxn][12], st2[maxn][12];

inline int Min(int a, int b){
    return (a < b ? a : b);
}
void add(int u, int v, int cap){
    edge[tot] = Edge(v, cap, head[u]);
    head[u] = tot++;
    edge[tot] = Edge(u, 0, head[v]);
    head[v] = tot++;
    value[u][v] = cap;
    value[v][u] = 0;
}
int bfs(){
    queue<int> q;
    while(!q.empty()) q.pop();
    memset(dis, 0, sizeof(dis));
    q.push(s); dis[s] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == t) break;
        for(int i = head[x]; ~i; i = edge[i].nxt){
            Edge &e = edge[i];
            if(e.cap && dis[e.v] == 0){
                dis[e.v] = dis[x] + 1;
                q.push(e.v);
            }
        }
    }
    return dis[t];
}
int dfs(int x, int f){
    if(x == t) return f;
    int sum = 0;
    for(int i = head[x]; ~i; i = edge[i].nxt){
        Edge &e = edge[i];
        if(e.cap && dis[e.v] == dis[x] + 1){
            int ret = dfs(e.v, Min(e.cap, f));
            sum += ret; f -= ret;
            e.cap -= ret; edge[i^1].cap += ret;
        }
    }
    return sum;
}
int dinic(){
    int ret = 0;
    while(bfs()) ret += dfs(s, INF);
    return ret;
}
int main(){
    int p, n, st;
    while(~scanf("%d%d", &p, &n)){
        tot = 0; s = 0; t = 2 * n + 1;
        memset(head, -1, sizeof(head));
        memset(value, 0, sizeof(value));
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            st = 0;
            for(int j = 0; j < p; ++j){
                scanf("%d", &st1[i][j]);
                if(st1[i][j] == 1) st = 1;
            }
            if(!st) add(s, i, a[i]);
            st = 1;
            for(int j = 0; j < p; ++j){
                scanf("%d", &st2[i][j]);
                if(st2[i][j] == 0) st = 0;
            }
            if(st) add(i + n, t, a[i]);
        }
        for(int i = 1; i <= n; ++i){
            add(i, i + n, a[i]);
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                st = 1;
                for(int k = 0; k < p; ++k){
                    if(st2[i][k] == st1[j][k]) continue;
                    if(st1[j][k] == 2) continue;
                    st = 0;
                }
                if(st) add(i + n, j, a[i]);
            }
        }

        printf("%d ", dinic());
        int res = 0;
        for(int i = n + 1; i < t; ++i){
            for(int j = head[i]; ~j; j = edge[j].nxt){
                Edge &e = edge[j];
                if(e.v == t || (i - n) == e.v) continue;
                if(e.cap < value[i][e.v]){
                    ans[res++] = ANS(i - n, e.v, value[i][e.v] - e.cap);
                }
            }
        }
        printf("%d\n", res);
        for(int i = 0; i < res; ++i){
            printf("%d %d %d\n", ans[i].from, ans[i].to, ans[i].val);
        }
    }
    return 0;
}