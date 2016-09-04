#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e6 + 10;
int vis[maxn], p[maxn], ans[maxn], prime[maxn];

void init(){
    int cnt = 0;
    //memset(vis, 0, sizeof(vis));
    // memset(prime, 0, sizeof(prime));
    for(int i = 1; i < maxn; i += 4) vis[i] = 1;
    for(int i = 1; i < maxn; ++i) p[i] = i;
    for(int i = 2; i < maxn; ++i){
        if(p[i] && vis[i]){
            prime[cnt++] = i;
            for(int j = 2; i * j < maxn; ++j){
                p[i * j] = 0;
            }
        }
    }
    
    memset(p, 0, sizeof(p));
    for(int i = 0; i < cnt; ++i){
        for(int j = i; j < cnt; ++j){
            long long tmp = (long long)prime[i] * (long long)prime[j];
            if(tmp > 1000001) break;
            p[tmp] = 1;
        }
    }
    
    // memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= 1000001; ++i){
        if(p[i] == 1) ans[i] = ans[i-1] + 1;
        else ans[i] = ans[i-1];
    }
}
int main(){
    int n; init();
    while(~scanf("%d", &n) && n){
        printf("%d %d\n", n, ans[n]);
    }
    return 0;
}