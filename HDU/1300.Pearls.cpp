#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100 + 5;
int a[maxn], p[maxn], dp[maxn];
int main(){
    int t, c, val;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &c);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= c; ++i){
            scanf("%d%d", &val, &p[i]);
            a[i] = a[i-1] + val;
        }

        for(int i = 1; i <= c; ++i){
            dp[i] = INF;
            for(int j = 0; j < i; ++j){
                dp[i] = min(dp[i], dp[j] + (a[i] - a[j] + 10) * p[i]);
            }
        }
        printf("%d\n", dp[c]);
    }
    return 0;
}
