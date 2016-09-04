#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1e5 + 5;
char str[maxn];
int a[60], num[maxn];
int main(){
    int n, tmp, ans = INF, sum = 0;

    scanf("%d", &n);
    scanf(" %s", str + 1);
    for(int i = 1; i <= n; ++i){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            tmp = str[i] - 'A';
            num[i] = tmp;
            if(!a[tmp]) sum += 1;
            ++a[tmp];
        }else{
            tmp = str[i] - 'a' + 26;
            num[i] = tmp;
            if(!a[tmp]) sum += 1;
            ++a[tmp];
        }
    }

    memset(a, 0, sizeof(a));
    int L = 1, R = 1, res = 0;
    while(true){
        while(res < sum && R <= n){
            if(!a[num[R]]) ++res;
            ++a[num[R]]; ++R;
        }
        if(res < sum) break;

        ans = min(ans, R - L);
        --a[num[L]];
        if(!a[num[L]]) --res;
        ++L;
    }
    printf("%d\n", ans);
    return 0;
}
