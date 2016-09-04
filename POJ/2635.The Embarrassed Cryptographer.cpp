#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 5;

char k[105];
int prime[maxn], num[105];

void init(){
    memset(prime, 0, sizeof(prime));
    for(int i = 2 ;i <= maxn; ++i){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] <= maxn / i; ++j){
            prime[prime[j] * i]=1;
            if(i % prime[j] == 0) break;
        }
    }
}
int mod(int n, int m){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = (ans * 1000) % m;
        ans = (ans + num[i]) % m;
    }
    return ans;
}
int main(){
    init(); int l;
    while(~scanf(" %s%d", k, &l)){
        if(strcmp(k, "0") == 0 && l == 0) break;
        int len = strlen(k), cnt = 0, flag = 0;
        memset(num, 0, sizeof(num));
        for(int i = len - 1; i >= 0; i -= 3){
            if(i >= 2){
                num[cnt++] = (k[i] - '0') + (k[i-1] - '0') * 10 + (k[i-2] - '0') * 100;
            }else{
                if(i == 1) num[cnt++] = (k[i] - '0') + (k[i-1] - '0') * 10;
                else num[cnt++] = (k[i] - '0');
            }
        }
        reverse(num, num + cnt);
        for(int i = 1; prime[i] < l; ++i){
            if(mod(cnt, prime[i]) == 0){
                flag = prime[i]; break;
            }
        }
        if(!flag) printf("GOOD\n");
        else printf("BAD %d\n", flag);
        memset(k, 0, sizeof(k));
    }
    return 0;
}