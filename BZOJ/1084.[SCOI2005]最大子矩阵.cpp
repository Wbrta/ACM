#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int s1[105], s2[105], sum[105];
int dp[15][105], f[15][105][105];
int main(){
    int a, b, n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k)){
        if(m == 1){
            memset(dp, 0, sizeof(dp));
            memset(sum, 0, sizeof(sum));
            for(int i = 1; i <= n; ++i){
                scanf("%d", &a);
                sum[i] = sum[i - 1] + a;
            }
 
            for(int i = 1; i <= k; ++i){
                for(int j = 1; j <= n; ++j){
                    dp[i][j] = dp[i][j-1];
                    for(int ii = 0; ii < j; ++ii)
                        dp[i][j] = max(dp[i][j], dp[i-1][ii] + sum[j] - sum[ii]);
                }
            }
            printf("%d\n", dp[k][n]);
        }else{
            memset(f, 0, sizeof(f));
            memset(s1, 0, sizeof(s1));
            memset(s2, 0, sizeof(s2));
            for(int i = 1; i <= n; ++i){
                scanf("%d%d", &a, &b);
                s1[i] = s1[i - 1] + a;
                s2[i] = s2[i - 1] + b;
            }
            for(int i = 1; i <= k; ++i){
                for(int x = 1; x <= n; ++x){
                    for(int y = 1; y <= n; ++ y){
                        f[i][x][y] = max(f[i][x-1][y], f[i][x][y-1]);
                        for(int j = 0; j < x; ++j) f[i][x][y] = max(f[i][x][y], f[i-1][j][y] + s1[x] - s1[j]);
                        for(int j = 0; j < y; ++j) f[i][x][y] = max(f[i][x][y], f[i-1][x][j] + s2[y] - s2[j]);
                        if(x == y)
                            for(int j = 0; j < x; ++j)
                                f[i][x][y] = max(f[i][x][y], f[i-1][j][j] + s1[x] - s1[j] + s2[y] - s2[j]);
                    }
                }
            }
            printf("%d\n", f[k][n][n]);
        }
    }
    return 0;
}