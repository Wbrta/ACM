#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int num[maxn];
inline int Min(int a, int b){
    return a < b ? a : b;
}
int main()
{
    int cas, n, S;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d%d", &n, &S);
        for(int i = 0; i < n; ++i){
            scanf("%d", &num[i]);
        }
        
        int res = n + 1;
        int s = 0, t = 0, sum = 0;
        while(true){
            while(t < n && sum < S){
                sum += num[t++];
            }
            if(sum < S) break;
            res = Min(res, t - s);
            sum -= num[s++];
        }
        
        if(res > n){
            printf("0\n");
        }else{
            printf("%d\n", res);
        }
    }
    return 0;
}