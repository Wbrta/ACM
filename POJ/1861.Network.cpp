#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int maxs = 15000 + 5;

typedef struct node{
    int from, to;
    int val;
    node(int x = 0, int y = 0, int w = 0){
        from = x; to = y; val = w;        
    }
    bool operator < (const node p){
        return val < p.val;
    }
}PATH;

int n, m, pre[maxn];
PATH ans[maxn], r[maxs];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    memset(ans, 0, sizeof(ans));
    int tol = 0, res = 0;
    for(int i = 0; i < m; ++i){
        int fx = findfather(r[i].from);
        int fy = findfather(r[i].to);
        if(fx == fy) continue;
        pre[fx] = fy;
        ans[tol++] = r[i];
        res = max(res, r[i].val);
        
        if(tol == n) break;
    }
    
    printf("%d\n%d\n", res, tol);
    for(int i = 0; i < tol; ++i){
        printf("%d %d\n", ans[i].from, ans[i].to);
    }
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d%d", &n, &m)){
        memset(r, 0, sizeof(r));
        for(int i = 0; i <= n; ++i) pre[i] = i;
        for(int i = 0; i < m; ++i) scanf("%d%d%d", &r[i].from, &r[i].to, &r[i].val);
        sort(r, r + m);
        kruskal();
    }
    return 0;
}