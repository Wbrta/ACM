#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 30000 + 5;
const int maxm = 150000 + 5;

typedef struct node{
    int to, w;
    int next;
}Edge;

int tol;
Edge edge[maxm];
int s[maxm], head[maxm], dis[maxn], vis[maxn];

void add(int a, int b, int c){
    edge[tol].to = b;
    edge[tol].w = c;
    edge[tol].next = head[a];
    head[a] = tol++;
}
int spfa(int n){
    int p, v, top = 0;
    for(int i = 0; i <= n; ++i){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[1] = 0; vis[1] = 1; s[top++] = 1;

    while(top){
        p = s[--top]; vis[p] = 0;
        for(int i = head[p]; ~i; i = edge[i].next){
            v = edge[i].to;
            if(dis[v] > dis[p] + edge[i].w){
                dis[v] = dis[p] + edge[i].w;

                if(!vis[v]){
                    vis[v] = 1;
                    s[top++] = v;
                }
            }
        }
    }
    return dis[n];
}
int main(){
    tol = 0;
    int a, b, c, n, m;

    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));

    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", spfa(n));
    return 0;
}