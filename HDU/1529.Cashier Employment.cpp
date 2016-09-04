#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 1000;
typedef struct node{
    int to, w;
    int next;
}Edge;

int tot;
Edge edge[maxn];
int r[25], t[25];
int head[maxn], dis[30], vis[30], cnt[30];

void add(int u, int v, int w){
    edge[tot].w = w;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int spfa(int ans){
    int p, v;
    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i <= 24; ++i){
        dis[i] = 0;
        vis[i] = 1;
        cnt[i] = 0;
        q.push(i);
    }

    while(!q.empty()){
        p = q.front(); q.pop(); vis[p] = 0;

        if(++cnt[p] > 25) return 0;
        for(int i = head[p]; ~i; i = edge[i].next){
            v = edge[i].to;
            if(dis[v] > dis[p] + edge[i].w){
                dis[v] = dis[p] + edge[i].w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    if(-dis[24] == ans) return 1;
    else return 0;
}
int solve(int ans){
    tot = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i < 24; ++i){
        add(i, i+1, 0);
        add(i+1, i, t[i+1]);
    }
    for(int j = 1; j <= 24; ++j){
        if(j + 8 <= 24) add(j, j + 8, -r[j+8]);
        else add(j, j-16, ans - r[j-16]);
    }
    add(0, 24, -ans);
    if(spfa(ans)) return 1;
    else return 0;
}
int main(){
    int tt, n, a;
    scanf("%d", &tt);
    while(tt--){
        for(int i = 1; i <= 24; ++i){
            scanf("%d", &r[i]); t[i] = 0;
        }
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a); ++t[a+1];
        }
        int flag = 0;
        for(int i = 0; !flag && i <= n; ++i){
            flag = solve(i);
            if(flag) {printf("%d\n", i); break;}
        }
        if(!flag) puts("No Solution");
    }
    return 0;
}