#include <cstdio>
#include <cstring>
using namespace std;

inline int f(int x){
    return x > 0 ? x : -x;
}
int main()
{
    int n, val, minpos, maxpos;
    while(~scanf("%d", &n)){
        minpos = maxpos = 1;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &val);
            if(val == 1){
                minpos = i;
            }else if(val == n){
                maxpos = i;
            }
        }
        
        int ans = f(maxpos - minpos);
        if(maxpos > minpos){
            if(n - maxpos > minpos - 1){
                ans += n - maxpos;
            }else{
                ans += minpos - 1;
            }
        }else{
            if(n - minpos > maxpos - 1){
                ans += n - minpos;
            }else{
                ans += maxpos - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}