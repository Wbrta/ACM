#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

typedef long long LL;
typedef struct node{
    int from, to;
    int w;
    bool operator < (node zz){
        return w < zz.w;
    }
}Edge;
typedef struct nn{
    int to;
    int w;
    nn(){}
    nn(LL a, LL b){
        to = a; w = b;
    }
}EEE;

LL ans;
double res;
int t, n, m;
Edge g[maxn * 10];
vector<EEE> e[maxn];
int vis[maxn], pre[maxn];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void join(int x, int y){
    pre[findfather(x)] = findfather(y);
}
void kruskal(){
    int x, y, flag = 0;
    for(int i = 0; i < m; ++i){
        x = findfather(g[i].from);
        y = findfather(g[i].to);

        if(x == y) continue;
        join(x, y);
        ++flag;
        ans += g[i].w;
        e[g[i].from].push_back(nn(g[i].to, g[i].w));
        e[g[i].to].push_back(nn(g[i].from, g[i].w));

        if(flag == n - 1) return;
    }
}
int dfs(int p){
    if(vis[p]) return 0;
    vis[p] = 1;

    int tt = 1, num;
    for(int i = 0; i < e[p].size(); ++i){
        int v = e[p][i].to;
        num = dfs(v);
        tt += num;
        res += (LL)(n - num) * (LL)num * (LL)e[p][i].w;
    }
    return tt;
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            pre[i] = i;
            vis[i] = 0;
            e[i].clear();
        }
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &g[i].from, &g[i].to, &g[i].w);
        }
        sort(g, g + m);
        ans = 0;
        kruskal();

        res = 0;
        dfs(1);
        printf("%lld %.2lf\n", ans, res / ((n - 1LL) * n / 2.0));
    }
    return 0;
}
