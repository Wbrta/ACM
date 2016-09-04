#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
LL a[maxn];
int main(){
    int n;
    scanf("%d", &n);
    map<LL, LL> m; m.clear();
    for(int i = 0; i < n; ++i){
        scanf("%I64d", &a[i]);
        m[a[i]] += 1;
    }
    sort(a, a + n);
    LL ans = 0;
    for(int i = 0; i < n; ++i){
        m[a[i]] -= 1;
        for(int j = 1; j <= 33; ++j){
            LL tmp = 1LL << j;
            int pos = lower_bound(a + i + 1, a + n, tmp - a[i]) - a;
            if(pos <= i || pos >= n || a[pos] + a[i] != tmp) continue;
            ans += m[a[pos]];
        }
    }
    printf("%I64d\n", ans);
    return 0;
}