#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10 + 3;

typedef struct node{
    int x, id;
    bool operator < (node a){
        return x > a.x;
    }
}Frog;

int flag;
Frog p[maxn];
int nei[maxn][maxn];

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &p[i].x);
            p[i].id = i;
        }
        
        sort(p, p + n);
        int flag = 1;
        memset(nei, 0, sizeof(nei));
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= p[0].x; ++j){
                --p[j].x;
                nei[p[0].id][p[j].id] = 1;
                nei[p[j].id][p[0].id] = 1;
                if(p[j].x < 0) flag = 0;
            }
            p[0].x = 0;
            sort(p, p + n);
        }
        if(flag){
            puts("YES");
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(j) printf(" ");
                    printf("%d", nei[i][j]);
                }
                puts("");
            }
        }else puts("NO");
        if(t) puts("");
    }
    return 0;
}