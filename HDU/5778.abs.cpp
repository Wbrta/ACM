#include <cmath>
#include <time.h>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
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

    srand((LL)time(NULL));
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

int main(){
    LL t, x, tmp;
    cin >> t;
    while(t--){
        cin >> x;
        if(x == 1 || x == 2 || x == 3 || x == 4){
            cout << (4 - x) << endl;
            continue;
        }

        tmp = (LL)sqrt(x + 0.500);
        LL ans = 1e18;
        for(LL i = tmp; i > 1; --i){
            tot = 0;
            memset(factor, 0, sizeof(factor));
            findfactor(i);
            sort(factor, factor + tot);

            int flag = 1;
            for(int j = 1; j < tot; ++j){
                if(factor[j] == factor[j-1]) {flag = 0; break;}
            }
            if(flag) {ans = min(ans, x - i * i); break;}
        }
        for(LL i = tmp + 1; ; ++i){
            tot = 0;
            memset(factor, 0, sizeof(factor));
            findfactor(i);
            sort(factor, factor + tot);

            int flag = 1;
            for(int j = 1; j < tot; ++j){
                if(factor[j] == factor[j-1]) {flag = 0; break;}
            }
            if(flag) {ans = min(ans, i * i - x); break;}
        }
        cout << ans << endl;
    }
    return 0;
}