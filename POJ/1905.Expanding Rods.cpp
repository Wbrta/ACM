#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    double l, n, c;
    while(~scanf("%lf%lf%lf", &l, &n, &c)){
        if(l == -1 && n == -1 && c == -1) break;
        double tt = (n * c + 1) * l;
        double low = 0, high = 1.0 / 2.0 * l;
        double ans, mid, tmp, radius;
        while( (high - low) >= 1e-6 ){
            mid = (high + low) / 2.0;
            radius = (l * l + 4 * mid * mid) / (8.0 * mid);

            tmp = 2 * radius * asin(l / (2.0 * radius));

            if( tt > tmp ) low = mid;
            else high = mid;
        }
        ans = mid;
        printf("%.3f\n", ans);
    }
    return 0;
}
