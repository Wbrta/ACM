#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e6 + 5;
int m, n, mx;
int s[maxn], dp[maxn], tmp[maxn];
int main()
{
    while(~scanf("%d%d", &m, &n)){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &s[i]);
        }
        memset(dp, 0, sizeof(dp));
        memset(tmp, 0, sizeof(tmp));
        for(int i = 1; i <= m; ++i){
            mx = -INF;
            for(int j = i; j <= n; ++j){
                dp[j] = max(dp[j-1], tmp[j - 1]) + s[j];
                tmp[j - 1] = mx;
                mx = max(mx, dp[j]);
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
