#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    int x, y, w;
    node(int a = 0, int b = 0, int c = 0){
        x = a; y = b; w = c;
    }
    bool operator < (node a){
        return w < a.w;
    }
}PATH;

const int maxn = 100 + 5;

PATH r[maxn * maxn];
int n, tot, pre[maxn];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int ans = 0;
    for(int i = 0; i < tot; ++i){
        int fx = findfather(r[i].x);
        int fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        ans += r[i].w;
    }
    printf("%d\n", ans);
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d", &n)){
        tot = 0;
        int w, q, a, b;
        memset(r, 0, sizeof(r));
        for(int i = 0; i < maxn; ++i) pre[i] = i;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                scanf("%d", &w);
                if(i == j) continue;
                r[tot++] = node(i, j, w);
            }
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &a, &b);
            pre[findfather(a)] = findfather(b);
        }
        sort(r, r + tot);
        kruskal();
    }
    return 0;
}