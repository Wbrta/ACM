#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    char from, to;
    int val;
    node(char a = 'A', char b = 'A', int w = 0){
        from = a; to = b;
        val = w;
    }
    bool operator < (node x){
        return val < x.val;
    }
}PATH;

const int maxn = 30;
const int maxm = 1000;

int n, tol, pre[maxn];
PATH r[maxm];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int k = 0, ans = 0;
    for(int i = 0; i <= n; ++i) pre[i] = i;
    for(int i = 0; i < tol; ++i){
        int x = r[i].from - 'A';
        int y = r[i].to - 'A';
        
        int fx = findfather(x);
        int fy = findfather(y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        ans += r[i].val;
        ++k;
        
        if(k == n - 1) break;
    }
    
    printf("%d\n", ans);
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d", &n) && n){
        tol = 0;
        memset(r, 0, sizeof(r));
        
        int w, k;
        char from, to;
        for(int i = 0; i < n - 1; ++i){
            scanf(" %c%d", &from, &k);
            for(int i = 0; i < k; ++i){
                scanf(" %c%d", &to, &w);
                r[tol++] = node(from, to, w);
            }
        }
        sort(r, r + tol);
        kruskal();
    }
    return 0;
}