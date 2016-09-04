#include <cstdio>
using namespace std;
const int maxn = 5000 + 5;
int vis[maxn];
int main(){
    int n, m, t, sum, flag;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        sum = 0; flag = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            sum = (sum + x) % m;
            vis[sum] += 1;
            if(vis[sum] >= 2) flag = 1;
        }
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}