#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
const int INF = 0x3f3f3f3f;

typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;

vector<Edge> vec[maxn];
int t[maxn], dis[maxn], vis[maxn], cnt[maxn];

int spfa(int n){
    Edge v;
    int p, len;
    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i < maxn; ++i){
        vis[i] = 0; cnt[i] = 0;
        dis[i] = INF;
    }
    q.push(0);
    dis[0] = 0; vis[0] = 1; cnt[0] = 1;

    while(!q.empty()){
        p = q.front(); q.pop(); vis[p] = 0;
        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            if(dis[v.to] > dis[p] + v.w){
                dis[v.to] = dis[p] + v.w;
                if(!vis[v.to]){
                    q.push(v.to);
                    vis[v.to] = 1; cnt[v.to] += 1;
                    if(cnt[v.to] >= n) return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    int a, b, n, cas = 1;
    while(~scanf("%d", &n) && n){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &t[i]);
        }
        for(int i = 0; i <= n; ++i) vec[i].clear();
        char op[5] = {0};
        while(~scanf(" %s", op)){
            if(strcmp(op, "#") == 0) break;
            scanf("%d%d", &a, &b);
            if(strcmp(op, "FAS") == 0) vec[b].push_back(Edge(a, t[a]));
            else if(strcmp(op, "FAF") == 0) vec[b].push_back(Edge(a, t[a] - t[b]));
            else if(strcmp(op, "SAF") == 0) vec[b].push_back(Edge(a, -t[b]));
            else vec[b].push_back(Edge(a, 0));
        }

        for(int i = 1; i <= n; ++i){
            vec[0].push_back(Edge(i, 0));
        }
        printf("Case %d:\n", cas++);
        if(spfa(n)){
            for(int i = 1; i <= n; ++i){
                printf("%d %d\n", i, -dis[i]);
            }
        }else puts("impossible");
        puts("");
    }
    return 0;
}