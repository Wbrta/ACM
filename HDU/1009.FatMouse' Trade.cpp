#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
typedef struct{
    int f, j;
    double val;
}Room;
Room r[maxn];

bool cmp(Room a, Room b){
    return a.val > b.val;
}
int main()
{
    int n, m;
    while(~scanf("%d%d", &m, &n)){
        if(m == -1 && n == -1) break;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &r[i].j, &r[i].f);
            if(r[i].f == 0)
                r[i].val = 1;
            else
                r[i].val = (double)r[i].j / (r[i].f);
        }
        if(n > 1)
            sort(r, r + n, cmp);
        
        int i = 0;
        double ans = 0;
        while(m >= 0 && i < n){
            if(m - r[i].f >= 0){
                ans += r[i].j;
                m -= r[i].f;
            }else{
                ans += (double)r[i].j * ((double)m / (double)r[i].f);
                m = 0;
            }
            ++i;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}