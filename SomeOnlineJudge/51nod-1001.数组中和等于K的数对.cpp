#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 5;
int k, n, a[maxn], vis[maxn];
int main(){
    scanf("%d%d", &k, &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int v, tmp, flag = 1;
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        tmp = k - a[i];
        v = lower_bound(a, a + n, tmp) - a;
        if(vis[v]) continue;
        if(a[v] == a[i]) continue;
        if(a[v] + a[i] == k) flag = 0, printf("%d %d\n", a[i], a[v]);
        vis[i] = 1; vis[v] = 1;
    }
    if(flag) puts("No Solution");
    return 0;
}