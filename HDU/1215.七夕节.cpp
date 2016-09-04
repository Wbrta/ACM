#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        LL ans = 0;
        scanf("%d", &n);
        for(int i = 2; i * i <= n; ++i){
            if(n % i == 0){
                if(i == n/i) ans += i;
                else ans += i + n / i;
            }
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}