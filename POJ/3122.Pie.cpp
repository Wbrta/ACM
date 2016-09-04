#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
const double pi=3.14159265359;

int n, f, r;
double p[maxn];
bool judge(double mid){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        if(mid > p[i]) continue;
        cnt += (int)(p[i] / mid);
    }
    if(cnt >= f + 1) return true;
    else return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &f);

        double maxx = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%lf", &p[i]);
            p[i] *= p[i];
            maxx = max(maxx, p[i]);
        }

        double mid, low = 0, high = maxx;
        while( (high - low) > 1e-6 ){
            mid = (high + low) / 2.0;

            if(judge(mid)) low = mid;
            else high = mid;
        }
        printf("%.4f\n", mid * pi);
    }
    return 0;
}