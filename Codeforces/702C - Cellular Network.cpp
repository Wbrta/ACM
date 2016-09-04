#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
inline int fun(int x){
    return (x >= 0 ? x : -x);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &b[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int mid, k = 0, l = 0, r = m - 1;
        while(l <= r){
            mid = (l + r) >> 1;
            if(b[mid] <= a[i]) k = mid, l = mid + 1;
            else r = mid - 1;
        }
        int t1 = k;
        int t2 = upper_bound(b, b + m, a[i]) - b;
        if(t2 >= m) t2 = m - 1;
        int dis = min( fun(a[i] - b[t1]), fun(b[t2] - a[i]) );
        ans = max(ans, dis);
    }
    printf("%d\n", ans);
    return 0;
}