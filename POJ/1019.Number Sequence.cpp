#include <cstdio>
using namespace std;
const int maxn = 5e5 + 5;
int num[maxn];
void init(){
    int tmp;
    num[0] = 0;
    for(int i = 1; i < maxn; ++i){
        if(i >= 1e4) tmp = 5;
        else if(i >= 1e3) tmp = 4;
        else if(i >= 100) tmp = 3;
        else if(i >= 10) tmp = 2;
        else tmp = 1;
        num[i] = num[i-1] + tmp;
    }
}
int main(){
    int t, n; init();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long k, sum = 0;
        for(int i = 1; sum < n; ++i){
            sum += num[i];
            k = i;
        }
        if(sum > n) {
            n -= (sum - num[k]);
            sum = 0;
            for(int i = 1; sum < n; ++i){
                if(i >= 1e4) sum += 5;
                else if(i >= 1e3) sum += 4;
                else if(i >= 100) sum += 3;
                else if(i >= 10) sum += 2;
                else sum += 1;
                k = i;
            }
            while(sum != n){
                k /= 10;
                --sum;
            }
        }
        printf("%d\n", (int)k % 10);
    }
    return 0;
}
