#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

typedef long long LL;

const int maxn = 100 + 5;
const int S = 20;

int tot;
LL factor[maxn];

LL mod_mul(LL a, LL b, LL n){
    LL res = 0;
    while(b){
        if(b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}
LL mod_exp(LL a, LL b, LL n){
    LL res = 1;
    while(b){
        if(b & 1) res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}
LL gcd(LL a, LL b){
    if(a == 0) return 1;
    if(a < 0) return gcd(-a, b);
    while(b){
        LL tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

LL pollard_rho(LL x, LL c){
    LL i = 1, k = 2;
    LL x0 = rand() % x;
    LL y = x0;
    while(true){
        ++i;
        x0 = (mod_mul(x0, x0, x) + c) % x;
        LL d = gcd(y - x0, x);
        if(d != 1 && d != x) return d;
        if(y == x0) return x;
        if(i == k){
            y = x0;
            k += k;
        }
    }
}

bool miller_rabin(LL n) {
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11) return true;
    if(n == 1 || !(n % 2) || !(n % 3) || !(n % 5) || !(n % 7) || !(n % 11)) return false;

    LL x, pre, u = n - 1, k = 0;

    while(!(u & 1)){
        ++k;
        u >>= 1;
    }

    //srand((LL)time(NULL));
    for(int i = 0; i < S; ++i){                     //进行S次测试，S越大，结果越准确
        x = rand() % (n - 2) + 2;                   //在[2, n)中取随机数
        if(x % n == 0) continue;

        x = mod_exp(x, u, n);                       //计算x^u % n
        pre = x;
        for(int j = 0; j < k; ++j){
            x = mod_mul(x, x, n);
            if(x == 1 && pre != 1 && pre != n - 1)
                return false;
            pre = x;
        }
        if(x != 1) return false;
    }
    return true;
}


void findfactor(LL n){
    if(miller_rabin(n)){
        factor[tot++] = n;
        return;
    }

    LL p = n;
    while(p >= n){
        p = pollard_rho(p, rand() % (n - 1) + 1);
    }
    findfactor(p);
    findfactor(n / p);
}

LL f[maxn];
LL n, p, ans, gcdd, lcmm;
void dfs(int pp, LL x){
    if(pp > p) return;
    if( gcd(gcdd * x, lcmm / x) == gcdd ){
        if(gcdd * x + lcmm / x < gcdd * ans + lcmm / ans){
            ans = x;
        }else if(gcdd * x + lcmm / x == gcdd * ans + lcmm / ans){
            ans = min(ans, x);
        }
    }
    dfs(pp + 1, x);
    x *= f[pp];
    if( gcd(gcdd * x, lcmm / x) == gcdd ){
        if(gcdd * x + lcmm / x < gcdd * ans + lcmm / ans){
            ans = x;
        }else if(gcdd * x + lcmm / x == gcdd * ans + lcmm / ans){
            ans = min(ans, x);
        }
    }
    dfs(pp + 1, x);
}
int main()
{
    while(~scanf("%lld%lld", &gcdd, &lcmm)){
        if(gcdd == lcmm){
            printf("%lld %lld\n", gcdd, lcmm);
        }else{
            tot = 0;
            n = lcmm / gcdd;
            fill(factor, factor + maxn, 0);
            findfactor(n);
            sort(factor, factor + tot);
            p = 0;
            fill(f, f + maxn, 0);
            f[0] = factor[0];
            for(int i = 0; i < tot - 1; ++i){
                if(factor[i] == factor[i+1]) f[p] *= factor[i+1];
                else f[++p] = factor[i+1];
            }
            ans = n;
            dfs(0, 1);
            printf("%lld %lld\n", gcdd * ans, lcmm / ans);
        }
    }
    return 0;
}
