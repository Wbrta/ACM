#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x10000000
const int maxm = 10000 + 5;
const int maxn = 500 + 5;
int w[maxn], val[maxn];
int dp[maxm];

inline int Min(int x, int y){
    return (x < y ? x : y);
}
int main()
{
    freopen("test.in", "r+", stdin);
    freopen("test.out", "w+", stdout);

    int n, T, E, F;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &E, &F, &n);
        int C = F - E;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &val[i], &w[i]);
        }

        for(int i = 1; i <= C; ++i){
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            int t = 1;
            int num = C / (w[i]);
            while(num){
                if(t > num) t = num;
                num -= t;

                for(int j = C; j >= t * w[i]; --j){
                    dp[j] = Min(dp[j], dp[j - t * w[i]] + t * val[i]);
                }
                t <<= 1;
            }
        }
        if(dp[C] != INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[C]);
        else
            printf("This is impossible.\n");
    }
    return 0;
}