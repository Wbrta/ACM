#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
long long ans[maxn];
int main(){
    int n, m, x, y, X, Y;
    scanf("%d%d", &n, &m);
    X = n; Y = n;
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        if(!a[x]) a[x] = 1, --X;
        if(!b[y]) b[y] = 1, --Y;
        ans[i] = 1LL * X * Y;
    }
    for(int i = 0; i < m; ++i){
        if(i) printf(" ");
        printf("%I64d", ans[i]);
    }
    puts("");
    return 0;
}
