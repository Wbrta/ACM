#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define mp make_pair

typedef pair<int, int> pi;

const int maxn = 30;
const int dir[4][2] = {0,1, 0,-1, -1,0, 1,0};

int n, m;
int vis[maxn][maxn];
char s[maxn][maxn];

int bfs(int x, int y){
    queue<pi> q;
    memset(vis, 0, sizeof(vis));
    while(!q.empty()) q.pop();
    q.push(mp(x, y));
    vis[x][y] = 1;
    
    int cnt = 0;
    while(!q.empty()){
        pi now = q.front();
        q.pop(); ++cnt;
        
        for(int i = 0; i < 4; ++i){
            int nx = now.first + dir[i][0];
            int ny = now.second + dir[i][1];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny] && s[nx][ny] != '#'){
                vis[nx][ny] = 1;
                q.push(mp(nx, ny));
            }
        }
    }
    return cnt;
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        
        int a, b;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                scanf(" %c", &s[i][j]);
                if(s[i][j] == '@') a = i, b = j;
            }
        }
        printf("%d\n", bfs(a, b));
        memset(s, 0, sizeof(s));
    }
    return 0;
}