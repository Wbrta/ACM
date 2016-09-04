#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n, a, tmp = -1, cnt = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        if(a > tmp) {
            ++cnt;
            ans = max(ans, cnt);
        }else cnt = 1;
        tmp = a;
    }
    printf("%d\n", ans);
    return 0;
}
