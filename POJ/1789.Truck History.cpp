#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXS 2010
#define MAXN 3000000

typedef struct node{
    int x, y;
    int w;
}PATH;

PATH r[MAXN];
char str[MAXS][10];
int n, tol, pre[MAXS];

int cmp(const void *p1, const void *p2){
    PATH *a = (PATH *)p1;
    PATH *b = (PATH *)p2;
    return a -> w - b -> w;
}
int findfather(int x){
    return pre[x] = (pre[x] == x ? x : findfather(pre[x]));
}
void kruskal(){
    int i, fx, fy, k = 0, res = 0;
    for(i = 0; i < n; ++i) pre[i] = i;
    for(i = 0; i < tol; ++i){
        fx = findfather(r[i].x);
        fy = findfather(r[i].y);
        
        if(fx == fy) continue;
        pre[fx] = fy;
        res += r[i].w;
        ++k;
        
        if(k == tol - 1) break;
    }
    printf("The highest possible quality is 1/%d.\n", res);
}
int main(){
    int i, j, k, cnt;
    while(~scanf("%d", &n) && n){
        for(i = 0; i < n; ++i){
            scanf(" %s", str[i]);
        }
        tol = 0;
        for(i = 0; i < n; ++i){
            for(j = i+1; j < n; ++j){
                cnt = 0;
                for(k = 0; k < 7; ++k){
                    if(str[i][k] == str[j][k]) continue;
                    ++cnt;
                }
                r[tol].x = i; r[tol].y = j; r[tol++].w = cnt;
            }
        }
        qsort(r, tol, sizeof(PATH), cmp);
        kruskal();
    }
    return 0;
}