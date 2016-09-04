#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int t, a, b;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        scanf("%d%d", &a, &b);
        double p = (double)(a - 1) / (double)a;
        double tmp = 1 - pow(p, (double)b);
        tmp *= a * (a + 1.0) / 2.0;
        printf("Case #%d: %.3lf\n", i, tmp);
    }
    return 0;
}