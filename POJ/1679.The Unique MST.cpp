#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct node{
    int x, y;
    int w, mark;
    bool operator == (node a){
        if(x == a.x && y == a.y && w == a.w && mark == a.mark) return true;
        else return false;
    }
    bool operator < (node a){
        return w < a.w;
    }
}PATH;

const int maxn = 100 + 5;
const int maxm = 10000 + 5;

int n, m;
PATH r[maxm];
int pre[maxn], inx[maxn];

int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int k, ans, res = 0, cnt = 0, flag = 1;
    memset(inx, 0, sizeof(inx));
    for(int i = 0; i <= n; ++i) pre[i] = i;
    for(int i = 0; i < m; ++i){
        int fx = findfather(r[i].x);
        int fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        res += r[i].w;
        inx[cnt++] = i;
        
        if(cnt == n - 1) break;
    }
    for(int i = 0; i < cnt && flag; ++i){
        if(r[inx[i]].mark) flag = 0;
    }
    
    if(flag) printf("%d\n", res);
    else{
        for(int i = 0; i < cnt; ++i){
            ans = 0; k = 0;
            for(int j = 0; j <= n; ++j) pre[j] = j;
            for(int j = 0; j < m; ++j){
                int fx = findfather(r[j].x);
                int fy = findfather(r[j].y);
                
                if(fx == fy) continue;
                if(j == inx[i]) continue;
                pre[fx] = fy;
                ans += r[i].w;
                ++k;
                if(k == n - 1) break; 
            }
            if(ans == res) {
                puts("Not Unique!");
                return;
            }
        }
        printf("%d\n", res);
    }
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; ++i){
            scanf("%d%d%d", &r[i].x, &r[i].y, &r[i].w);
            r[i].mark = 0;
        }
        sort(r, r + m);
        for(int i = 1; i < m; ++i){
            if(r[i].w == r[i-1].w){
                r[i].mark = r[i-1].mark = 1;
            }
        }
        kruskal();
    }
    return 0;
}