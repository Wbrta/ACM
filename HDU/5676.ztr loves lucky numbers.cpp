#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 67000;
int cur = 0;
LL num[maxn * 10], sl[maxn];

void bfs(){
    queue<LL> q;
    while(!q.empty()) q.pop();
    q.push(4); q.push(7);
    
    while(!q.empty()){
        LL now = q.front();
        q.pop();
        if(now >= 1e18) continue;
        num[cur++] = now;
        
        q.push(now * 10 + 4);
        q.push(now * 10 + 7);
    }
}
int main()
{
    memset(num, 0, sizeof(num));
    bfs();
    int len = 0;
    for(int i = 0; i < cur; ++i){
        if(num[i]){
            int s = 0, f = 0;
            LL tmp = num[i];
            while(tmp){
                if(tmp % 10 == 4) ++f;
                else ++s;
                tmp /= 10;
            }
            if(s == f) sl[len++] = num[i];
        }
    }
    LL i, t, n; scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for(i = 0; sl[i] < n && i < len; ++i);
        if(i == len && sl[i-1] < n){
            printf("44444444447777777777\n");
        }else{
            printf("%lld\n", sl[i]);
        }
    }
    return 0;
}