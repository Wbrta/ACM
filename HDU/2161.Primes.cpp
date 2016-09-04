#include <cstdio>
using namespace std;
int main(){
    int n, cas = 1;
    while(~scanf("%d", &n) && n > 0){
        if(n == 1 || n == 2){
            printf("%d: no\n", cas);
            ++cas;
            continue;
        }
        int flag = 0;
        for(int i = 2; i * i <= n; ++i){
            if(n % i == 0) {
                flag = 1;
                break;
            }
        }
        if(flag) printf("%d: no\n", cas);
        else printf("%d: yes\n", cas);
        ++cas;
    }
    return 0;
}