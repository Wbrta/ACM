#include <cstdio>
using namespace std;
int main()
{
    int n, val;
    while(~scanf("%d", &n) && n){
        int ans = 0, tmp = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &val);
            if(val > tmp){
                ans += (val - tmp) * 6;
            }else{
                ans += (tmp - val) * 4;
            }
            ans += 5;
            tmp = val;
        }
        printf("%d\n", ans);
    }
    return 0;
}