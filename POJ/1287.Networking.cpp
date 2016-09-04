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

const int maxn = 50 + 5;

PATH r[maxn * maxn];
int p, tot, pre[maxn];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int k = 0, ans = 0;
    for(int i = 0; i < maxn; ++i) pre[i] = i;
    for(int i = 0; i < tot; ++i){
        int fx = findfather(r[i].x);
        int fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        ans += r[i].w;
        
        ++k;
        if(k == p - 1) break;
    }
    printf("%d\n", ans);
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d", &p)){
        if(p == 0) break;
        scanf("%d", &tot);
        for(int i = 0; i < tot; ++i){
            scanf("%d%d%d", &r[i].x, &r[i].y, &r[i].w);
        }
        sort(r, r + tot);
        kruskal();
    }
    return 0;
}