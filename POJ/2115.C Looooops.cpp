#include <cstdio>
using namespace std;
typedef long long LL;
LL ext_euclid(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    LL gao = ext_euclid(b, a % b, x, y);
    LL tmp = x;
    x = y;
    y = tmp - (a / b) * y;
    return gao;
}
int main(){
    LL a, b, c, d;
    while(~scanf("%lld%lld%lld%lld", &a, &b, &c, &d)){
        if(a == 0 && b == 0 && c == 0 && d == 0) break;
        
        LL k = (1LL << d);
        LL A = c;
        LL B = (b - a + k) % k;
        
        LL x, y;
        LL dd = ext_euclid(A, k, x, y);
        if(B % dd == 0){
            LL tmp = k / dd;
            x = (x * (B / dd)) % k;
            x = ( x % tmp + tmp ) % tmp;
            printf("%lld\n", x);
        }else{
            puts("FOREVER");
        }
    }
    return 0;
}