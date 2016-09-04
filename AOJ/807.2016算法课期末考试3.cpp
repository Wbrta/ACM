#include <cstdio>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d", &n)){
        int ans = -1e9, sum = 0, num;
        for(int i = 0; i < n; ++i){
            scanf("%d", &num);
             
            sum += num;
            if(sum > ans) ans = sum;
            else if(sum < 0) sum = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
