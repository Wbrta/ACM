#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    int x, y;
    double w;
    node(int a = 0, int b = 0, double c = 0){
        x = a; y = b; w = c;
    }
    bool operator < (node a){
        return w < a.w;
    }
}PATH;

const int maxn = 750 + 5;

PATH r[maxn * maxn], res[maxn];
int n, m, tot, pre[maxn], x[maxn], y[maxn];

double dis(int i, int j){
    return sqrt( (double)((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + 0.001) );
}
int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int cnt = 0;
    memset(res, 0, sizeof(res));
    for(int i = 0; i < tot; ++i){
        int fx = findfather(r[i].x);
        int fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        res[cnt++] = r[i];
    }
    
    if(cnt == 0) puts("");
    else{
        for(int i = 0; i < cnt; ++i){
            printf("%d %d\n", res[i].x, res[i].y);
        }
    }
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    int a, b, cas = 0;
    scanf("%d", &n);
    memset(r, 0, sizeof(r));
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for(int i = 0; i <= n; ++i) pre[i] = i;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }
    tot = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            r[tot++] = node(i, j, dis(i, j));
        }
    }
    sort(r, r + tot);
    scanf("%d", &m);
    while(m--){
        scanf("%d%d", &a, &b);
        pre[findfather(a)] = findfather(b);
    }
    kruskal();
    return 0;
}