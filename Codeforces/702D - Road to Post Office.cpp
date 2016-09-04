#include <cstdio>
using namespace std;
typedef long long LL;
int main(){
    LL d, k, a, b, t, ans = 0;
    scanf("%I64d%I64d%I64d%I64d%I64d", &d, &k, &a, &b, &t);
    if(d <= k){ printf("%I64d\n", d * a); return 0; }
    d -= k; ans += k * a;
    if(k * b <= k * a + t){
        ans += d * b;
    }else{
        LL t1 = d / k;
        LL dis = t1 * k;
        ans += dis * a + t1 * t;
        if(dis != d){
            dis = d - dis;
            if(dis * b <= dis * a + t){
                ans += dis * b;
            }else{
                ans += dis * a + t;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}