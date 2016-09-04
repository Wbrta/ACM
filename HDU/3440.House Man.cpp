#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 0x7fffffff;

typedef struct point{
    int h, index;
    point(int a = 0, int b = 0){
        h = a; index = b;
    }
    bool operator < (point a){
        return h < a.h;
    }
}P;
typedef struct node{
    int to, w;
    int next;
    node(int a = 0, int b = 0, int c = 0){
        to = a; w = b; next = c;
    }
}Edge;

P p[maxn];
Edge edge[maxn * maxn];
int tot, Stack[maxn], h[maxn];
int head[maxn * maxn], dis[maxn], vis[maxn], cnt[maxn];

inline int Max(int a, int b){
    return (a >= b ? a : b);
}
inline int Min(int a, int b){
    return (a <= b ? a : b);
}
inline void add(int u, int v, int w){
    edge[tot] = Edge(v, w, head[u]);
    head[u] = tot++;
}
int spfa(int s, int e, int n){
    int u, v, top = 0;
    for(int i = 0; i <= n; ++i){
        dis[i] = INF;
        vis[i] = 0; cnt[i] = 0;
    }
    Stack[top++] = s; dis[s] = 0; vis[s] = 1;

    while(top){
        u = Stack[--top]; vis[u] = 0;
        if((++cnt[u]) > n) return -1;
        for(int i = head[u]; ~i; i = edge[i].next){
            v = edge[i].to;
            if(dis[v] > dis[u] + edge[i].w){
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v]){
                    vis[v] = 1;
                    Stack[top++] = v;
                }
            }
        }
    }

    return dis[e];
}
int main(){
    int t, n, a, b, d;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas){
        tot = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &h[i]);
            p[i] = P(h[i], i);
        }
        sort(p + 1, p + 1 + n);
        for(int i = 1; i < n; ++i){
            a = Max(p[i].index, p[i+1].index);
            b = Min(p[i].index, p[i+1].index);

            add(i, i + 1, -1);
            add(a, b, d);
        }

        a = Max(p[n].index, p[1].index);
        b = Min(p[n].index, p[1].index);
        printf("Case %d: %d\n", cas, spfa(a, b, n));
    }
    return 0;
}