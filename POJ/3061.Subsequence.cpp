#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
int num[maxn], sum[maxn];
inline int Min(int a, int b){
    return a < b ? a : b;
}
int main()
{
    int cas, n, s;
    scanf("%d", &cas);
    while(cas--){
        memset(num, 0, sizeof(num));
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &s);
        for(int i = 0; i < n; ++i){
            scanf("%d", &num[i]);
            sum[i + 1] = sum[i] + num[i];
        }
        
        if(sum[n] < s){
            printf("0\n");
            continue;
        }
        
        int ans = n;
        for(int i = 0; sum[i] + s <= sum[n]; ++i){
            int t = lower_bound(sum + i, sum + n, sum[i] + s) - sum;
            ans = Min(ans, t - i);
        }
        printf("%d\n", ans);
    }
    return 0;
}