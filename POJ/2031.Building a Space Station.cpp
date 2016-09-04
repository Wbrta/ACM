#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct point{
    double x, y, z;
    double radius;
    point(double a = 0, double b = 0, double c = 0, double d = 0){
        x = a; y = b; z = c;
        radius = d;
    }
}P;
typedef struct node{
    int from, to;
    double w;
}PATH;

const int maxn = 100 + 5;

P p[maxn];
PATH r[maxn * maxn];
int n, tot, pre[maxn];

double dist(int i, int j){
    double dis = sqrt( (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z));
    if(dis > (p[i].radius + p[j].radius)) return dis - (p[i].radius + p[j].radius);
    else return 0; 
}
int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int k = 0;
    double ans = 0;
    for(int i = 0; i < maxn; ++i) pre[i] = i;
    for(int i = 0; i < tot; ++i){
        int fx = findfather(r[i].from);
        int fy = findfather(r[i].to);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        ans += r[i].w;
        ++k;
        
        if(k == n - 1) break;
    }
    printf("%.3f\n", ans);
}
bool cmp(PATH a, PATH b){
    return a.w < b.w;
}
int main(){
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d", &n) && n){
        memset(p, 0, sizeof(p));
        for(int i = 0; i < n; ++i){
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z, &p[i].radius);
        }
        
        tot = 0;
        memset(r, 0, sizeof(r));
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                r[tot].from = i;
                r[tot].to = j;
                r[tot++].w = dist(i, j);
            }
        }
        sort(r, r + tot, cmp);
        kruskal();
    }
    return 0;
}