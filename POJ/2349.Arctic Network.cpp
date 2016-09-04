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

const int maxn = 500 + 5;

PATH r[maxn * maxn];
int s, p, tot, pre[maxn], x[maxn], y[maxn];

double dis(int i, int j){
    return sqrt( (double)((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + 0.001) );
}
int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int area = p;
    double ans = 0;
    for(int i = 0; i < maxn; ++i) pre[i] = i;
    for(int i = 0; i < tot; ++i){
        int fx = findfather(r[i].x);
        int fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        --area;
        ans = max(ans, r[i].w);
        if(area == s) break;
    }
    printf("%.2f\n", ans);
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &s, &p);
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for(int i = 1; i <= p; ++i){
            scanf("%d%d", &x[i], &y[i]);
        }
        
        tot = 0;
        for(int i = 1; i <= p; ++i)
            for(int j = i + 1; j <= p; ++j)
                r[tot++] = node(i, j, dis(i, j));
        sort(r, r + tot);
        kruskal();
    }
    return 0;
}