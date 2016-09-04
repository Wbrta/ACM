#include <string>
#include <cstdio>
using namespace std;
typedef unsigned long long uLL;
int main()
{
    int n;
    while(~scanf("%d", &n)){
        uLL ans = 1, j = 1;
        for(int i = n + 1; i <= 2 * n; ++i){
            ans *= i;
            ans /= j;
            ++j;
        }
        while(j <= n){
            ans /= j;
            ++j;
        }
        ans /= (n + 1);
        printf("%llu\n", ans);
    }
    return 0;
}