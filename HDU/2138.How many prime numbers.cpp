#include <cstdio>
using namespace std;
int main()
{
    unsigned int flag, n, val;
    while(~scanf("%u", &n)){
        int ans = 0;
        for(int i = 0; i < n; ++i){
            scanf("%u", &val);
            
            flag = 1;
            for(int j = 2; j * j <= val; ++j){
                if(val % j == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}