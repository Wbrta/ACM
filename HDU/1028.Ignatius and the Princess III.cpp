#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 120 + 5;
int dp[maxn][maxn];

int main()
{
    int n;
    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                if(j - i >= 0){
                    dp[i][j] = (dp[i-1][j] + dp[i][j-i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}