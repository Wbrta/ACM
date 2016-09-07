#include <cstdio>
#include <cstring>
using namespace std;
#define Clear(r) memset(r, 0, sizeof(r))
const int maxn = 100000 + 10;
int num[maxn], sum[maxn], l[maxn << 1], r[maxn << 1];
int main()
{
    int n, b, val, p;
    while(~scanf("%d%d", &n, &b)){
        Clear(l); Clear(r); Clear(num); Clear(sum);
        for(int i = 0; i < n; ++i){
            scanf("%d", &val);
            if(val > b){ 
                num[i] = 1;
            }else if(val == b){
                num[i] = 0;
                p = i;
            }else{
                num[i] = -1;
            }
        }
        l[n] = 1; r[n] = 1;
        for(int i = p - 1; i >= 0; --i){
            sum[i] = sum[i + 1] + num[i];
            ++l[n + sum[i]];
        }
        for(int i = p + 1; i < n; ++i){
            sum[i] = sum[i - 1] + num[i];
            ++r[n + sum[i]];
        }
        int ans = 0;
        for(int i = 0; i < n << 1; ++i){
            ans += l[i] * r[(n << 1) - i];
        }
        printf("%d\n", ans);
    }
    return 0;
}