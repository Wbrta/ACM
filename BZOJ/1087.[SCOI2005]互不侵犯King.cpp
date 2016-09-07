#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int N, K;
bool vis[515][515], ha[515];
long long cnt[515], dp[13][100][515];
 
void init(){
    int status = 512;
    for(int i = 0; i < status; ++i){
        if((i & (i >> 1)) == 0){
            int s = 0;
            for(int tmp = i; tmp; tmp >>= 1) if(tmp & 1) ++s;
            cnt[i] = s; ha[i] = 1;
        }
    }
    for(int i = 0; i < status; ++i){
        if(!ha[i]) continue;
        for(int j = 0; j < status; ++j){
            if(!ha[j]) continue;
            if(((i & j) == 0) && ((i & (j >> 1)) == 0) && ((j & (i >> 1)) == 0))
                vis[i][j] = 1;
        }
    }
}
int main(){
    init();
    while(~scanf("%d%d", &N, &K)){
        int status = (1 << N) - 1;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= status; ++i){
            if(ha[i]) dp[1][cnt[i]][i] = 1;
        }
        for(int i = 1; i < N; ++i){
            for(int st = 0; st <= status; ++st){
                if(!ha[st]) continue;
                for(int sta = 0; sta <= status; ++sta){
                    if(!ha[sta]) continue;
                    if(vis[st][sta]){
                        for(int j = cnt[st]; j + cnt[sta] <= K; ++j)
                            dp[i+1][j + cnt[sta]][sta] += dp[i][j][st];
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i <= status; ++i){
            ans += dp[N][K][i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}