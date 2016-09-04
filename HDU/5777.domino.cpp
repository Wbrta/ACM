#include <queue>
#include <cstdio>
using namespace std;
typedef long long LL;
int main(){
    int t, n, k, x;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);

        LL ans = n;
        priority_queue<int> q;
        while(!q.empty()) q.pop();
        for(int i = 1; i < n; ++i){
            scanf("%d", &x);
            q.push(x);
        }

        while(!q.empty()){
            x = q.top();
            q.pop();
            if(k > 1) {--k; continue;}
            ans += x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}