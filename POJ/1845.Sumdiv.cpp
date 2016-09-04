#include <cstdio>
#include <cstring>
using namespace std;
#define mod 9901
typedef long long LL;

const int maxn = 1e4 + 5;
LL prime[maxn], f[maxn], g[maxn];

void init(){
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i < maxn; ++i){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] < maxn / i; ++j){
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
LL mod_mul(LL a, LL b){
    LL res = 0;
    while(b){
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res % mod;
}
LL mod_exp(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = mod_mul(res, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return res % mod;
}
LL Cal(LL x, LL num){
    if(num == 0) return 1;
    if(num == 1) return (1 + x) % mod;
    
    LL res = 1;
    if(num % 2 == 0){
        res = (res + mod_exp(x, num / 2 + 1)) % mod;
        res = (res * Cal(x, num / 2 - 1)) % mod;
        res = (res + mod_exp(x, num / 2)) % mod;
    }else{
        res = (res + mod_exp(x, num / 2 + 1)) % mod;
        res = (res * Cal(x, num / 2)) % mod;
    }
    return res;
}
int main(){
    init();
    LL a, b, tmp, cnt;
    while(~scanf("%lld%lld", &a, &b)){
        if(a == 1) {puts("1"); continue;}
        tmp = a; cnt = 0;
        // memset(f, 0, sizeof(f));
        // memset(g, 0, sizeof(g));
        for(int i = 1; i <= prime[0]; ++i){
            if(tmp % prime[i] == 0){
                f[cnt] = prime[i];
                g[cnt] = 0;
                while(tmp % prime[i] == 0){
                    tmp /= prime[i];
                    ++g[cnt];
                }
                ++cnt;
            }
            
            if(tmp == 1) break;
        }
        if(tmp != 1){
            f[cnt] = tmp; g[cnt++] = 1;
        }
        LL ans = 1;
        for(int i = 0; i < cnt; ++i) {
            g[i] *= b;
            // printf("f = %lld, g = %lld\n", f[i], g[i]);
            ans = (ans * Cal(f[i], g[i])) % mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}