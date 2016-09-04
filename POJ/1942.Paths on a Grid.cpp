#include <cstdio>
using namespace std;
typedef long long LL;
LL C(LL n, LL m){
    double a = n + m;
    double b = (n < m ? n : m);
    double ans = 1.0;
    while(b > 0){
        ans *= a / b;
        --a; --b;
    }
    return (LL)(ans + 0.5);
}
int main(){
    LL n, m;
    while(~scanf("%lld%lld", &n, &m)){
        if(n == 0 && m == 0) break;
        printf("%lld\n", C(n, m));
    }
    return 0;
}