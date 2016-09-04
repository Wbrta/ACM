#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        double ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            ans += log((double)i) / log(10.0);
        }
        printf("%d\n", (int)ans + 1);
    }
    return 0;
}