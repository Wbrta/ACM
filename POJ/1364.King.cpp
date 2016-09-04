#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 150;
const int INF = 0x3f3f3f3f;

typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;

vector<Edge> vec[maxn];
int dis[maxn], vis[maxn], cnt[maxn];

int spfa(int n){
    Edge v;
    int p, len;
    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i = 0; i <= n; ++i){
        dis[i] = 0;
        vis[i] = 1;
        cnt[i] = 0;
        q.push(i);
    }

    while(!q.empty()){
        p = q.front(); q.pop();
        vis[p] = 0;
        if((++cnt[p]) > n + 1) return 0;

        len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            if(dis[v.to] > dis[p] + v.w){
                dis[v.to] = dis[p] + v.w;
                if(!vis[v.to]){
                    vis[v.to] = 1;
                    q.push(v.to);
                }
            }
        }
    }
    return 1;
}
int main(){
    int k, l, n, m, s;
    while(~scanf("%d", &n) && n){
        scanf("%d", &m);
        for(int i = 0; i <= n; ++i) vec[i].clear();
        for(int i = 0; i < m; ++i){
            char op[5] = {0};
            scanf("%d%d %s%d", &s, &l, op, &k);
            if(strcmp(op, "gt") == 0){
                vec[s-1].push_back(Edge(s+l, -(k+1)));
            }else{
                vec[s+l].push_back(Edge(s-1, (k-1)));
            }
        }
        if(!spfa(n)) puts("successful conspiracy");
        else puts("lamentable kingdom");
    }
    return 0;
}