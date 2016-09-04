#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int a[maxn][maxn];
inline int Max(int a, int b){
    return a >= b ? a : b;
}
int main()
{
    int t, n, m, k, val;
    scanf("%d", &t);
    while(t--){
        memset(a, 0, sizeof(a));
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                scanf("%d", &val);
                a[i + 1][j] = a[i][j] + val;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int res = 0;
                int s = 0, t = 0, sum = 0;
                while(t < m){
                    sum += a[j][t] - a[i][t];
                    if(sum <= k){
                        res = Max(res, (t - s + 1) * (j - i));
                    }else{
                        sum -= a[j][s] - a[i][s];
                        ++s;
                    }
                    ++t;
                }
                ans = Max(ans, res);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}