#include <cstdio>
using namespace std;
typedef long long LL;
LL high, low;
void solve(int n){
    if(n == 0) return;
    LL tmpHigh = high, tmpLow = low;
    high = 3 * tmpHigh + 2 * tmpLow;
    low = tmpHigh + tmpLow;
    solve(n - 1);
}
int main()
{
    int n;
    while(scanf("%d", &n) && n != -1){
        high = 1; low = 0;
        solve(n);
        printf("%lld, %lld\n", high, low);
    }
    return 0;
}