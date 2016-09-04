#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define INF 0x7fffffff
const int maxn = 1e6 + 5;

typedef long long LL;
typedef struct node{
    int to, w;
    node(int a = 0, int b = 0){
        to = a; w = b;
    }
}Edge;

LL dis[maxn];
int vis[maxn];
vector<Edge> vec[maxn];
int p, q, a[maxn], b[maxn], c[maxn];

LL spfa(int s){
    Edge v;
    queue<int> que;
    LL tmp, len, res = 0;
    while(!que.empty()) que.pop();
    for(int i = 0; i <= p; ++i){
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[s] = 0;
    vis[s] = 1;
    que.push(s);

    while(!que.empty()){
        tmp = que.front();
        que.pop();

        len = vec[tmp].size();
        for(int i = 0; i < len; ++i){
            v = vec[tmp][i];
            if(dis[tmp] + v.w < dis[v.to]){
                dis[v.to] = dis[tmp] + v.w;
                if(!vis[v.to]){
                    vis[v.to] = 1;
                    que.push(v.to);
                }
            }
        }
        vis[tmp] = 0;
    }

    for(int i = 2; i <= p; ++i) res += dis[i];
    return res;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &p, &q);
        for(int i = 0; i <= p; ++i)
            vec[i].clear();
        for(int i = 0; i < q; ++i){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            vec[a[i]].push_back(node(b[i], c[i]));
        }

        LL ans = spfa(1);
        for(int i = 0; i <= p; ++i) vec[i].clear();
        for(int i = 0; i < q; ++i){
            vec[b[i]].push_back(node(a[i], c[i]));
        }
        ans += spfa(1);
        printf("%I64d\n", ans);
    }
    return 0;
}