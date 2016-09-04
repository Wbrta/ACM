#include <cstdio>
#include <cstring>
using namespace std;
#define INF 50003
const int maxn = 1450 + 5;
int pos[maxn];
int dp[maxn][maxn];
int v;

inline int Min(int a, int b){
    return a < b ? a : b;
}

int main()
{
    int t, n, p, c, a, b, d;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &p, &c);
        for(int i = 1; i <= p; ++i){
            for(int j = 1; j <= p; ++j){
                if(i == j) dp[i][j] = 0;
                else dp[i][j] = INF;
            }
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &pos[i]);
        }
        for(int i = 0; i < c; ++i){
            scanf("%d%d%d", &a, &b, &d);
            dp[a][b] = dp[b][a] = d;
        }
        for(int k = 1; k <= p; ++k){
            for(int i = 1; i <= p; ++i){
                for(int j = 1; j <= p; ++j){
                    dp[i][j] = Min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        int minsum = INF, minpos = 0;
        for(int i = 1; i <= p; ++i){
            int tmp = 0;
            for(int j = 0; j < n; ++j){
                tmp += dp[pos[j]][i];
            }
            if(tmp < minsum){
                minpos = i;
                minsum = tmp;
            }
        }
        printf("%d\n", minsum);
    }
    return 0;
}