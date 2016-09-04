#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        double a, b, r, x0, y0, w, t;
        scanf("%lf%lf%lf%lf%lf%lf%lf", &a, &b, &r, &x0, &y0, &w, &t);
        
        double x1 = a + r * cos(w * t);
        double y1 = b + r * sin(w * t);
        
        double A = y1 - y0;
        double B = x0 - x1;
        double C = y0 * (x1 - x0) - x0 * (y1 - y0);
        if(A == 0 && B == 0){
            printf("0.00\n");
        }else{
            double ans = abs(A * a + B * b + C) / sqrt(A * A + B * B);
        
            ans = 2 * sqrt(r * r - ans * ans);
            printf("%.2f\n", ans);
        }
    }
    return 0;
}