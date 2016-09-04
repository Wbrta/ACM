#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
struct ROOM{
    int bug, brain;
}room[maxn];
int n, m, a, b;
int dp[maxn][maxn]; //根节点为i时用掉j个骑兵所能获得的最大brain
bool vis[maxn];
vector<int> tu[maxn];
inline int Max(int a, int b){
    return (a > b ? a : b);
}
void Gao(int rt){
    int cost = (room[rt].bug + 19) / 20;
    for(int i = cost; i <= m; ++i) dp[rt][i] = room[rt].brain;
    vis[rt] = true;
    for(int i = 0; i < tu[rt].size(); ++i){
        int pos = tu[rt][i];
        if(vis[pos]) continue;
        Gao(pos);
        for(int j = m; j >= cost; --j){
            for(int k = 1; k <= j - cost; ++k){
                dp[rt][j] = Max(dp[rt][j], dp[rt][j - k] + dp[pos][k]);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d", &n, &m)){
        if(n == -1 && m == -1) break;
        
        memset(dp, 0, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        memset(room, 0, sizeof(room));
        for(int i = 0; i <= n; ++i) tu[i].clear();
        
        for(int i = 1; i <= n; ++i){
            scanf("%d%d", &room[i].bug, &room[i].brain);
        }
        for(int i = 1; i < n; ++i){
            scanf("%d%d", &a, &b);
            tu[a].push_back(b);
            tu[b].push_back(a);
        }

        if(m == 0){
            printf("0\n");
        }else{
            Gao(1);
            printf("%d\n", dp[1][m]);
        }
    }
    return 0;
}