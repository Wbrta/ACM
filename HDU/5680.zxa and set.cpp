#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#define lson (rt<<1)
#define rson (rt<<1|1)
#define INF 0x7fffffff
#define Clear(a) memset((a), 0, sizeof(a));
typedef long long LL;
const int maxn = 30 + 5;
LL num[maxn], C[maxn][maxn];
void init(){
    for(int i = 0; i < maxn; ++i){
        C[i][0] = 0;
        C[0][i] = 1;
    }
    for(int i = 1; i < maxn; ++i){
        for(int j = 1; j < maxn; ++j){
            C[i][j] = C[i-1][j-1] + C[i][j-1];
        }
    }
}
int main()
{
    int t, n; init();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &num[i]);
        }
        sort(num + 1, num + n + 1);
        LL odd = 0, even = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j <= n - i; ++j){
                if((i + j) % 2){
                    odd += C[j][n-i] * num[i];
                }else{
                    even += C[j][n-i] * num[i];
                }
            }
        }
        printf("%lld\n", (odd > even ? odd - even : even - odd));
    }
    return 0;
}
