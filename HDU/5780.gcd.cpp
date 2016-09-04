#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int maxn = 1e6 + 10;
const int mod = 1000000007;

LL cont[maxn];
bool check[maxn];
int tot, prime[maxn], phi[maxn];

void getEuler(){
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for(int i = 2; i < maxn; i++){
        if(!check[i]){
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < tot; j++) {
            if(i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0){
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }else{
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }

    cont[0] = 0;
    for(int i = 1; i < maxn; ++i){
        cont[i] = (cont[i-1] + phi[i]) % mod;
    }
}
LL Mi(LL a, LL b){
    LL ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans % mod;
}
LL Cal(LL x, LL be, LL en){
    if(x == 1) return (en - be + 1);
    LL ans = Mi(x, be);
    if(ans < 0) ans += mod;
    LL n = en - be + 1;
    LL tmp = (Mi(x, n) - 1) % mod;
    if(tmp < 0) tmp += mod;
    tmp = (tmp * Mi(x - 1, mod - 2)) % mod;
    ans = (ans * tmp) % mod;
    return ans;
}
int main(){
    int t;
    LL x, n;
    getEuler();
    scanf("%d", &t);
    while(t--){
        scanf("%I64d%I64d", &x, &n);
        if(x == 1) { puts("0");continue; }
        LL nxt, tmp, ans = 0;
        for(int i = 1; i <= n; i = nxt + 1){
            nxt = n / (n / i);
            tmp = (2LL * cont[n / i] - 1) % mod;
            ans = (ans + tmp * Cal(x, i, nxt)) % mod;
            if(ans < 0) ans += mod;
        }
        ans = (ans - n * n) % mod;
        if(ans < 0) ans += mod;
        printf("%I64d\n", ans);
    }
    return 0;
}