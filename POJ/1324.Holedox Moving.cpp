#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

typedef pair<int, int> pi;
typedef struct node{
    int x, y;
    int st;
    node(){}
    node(int a, int b, int status){
        x = a; y = b;
        st = status;
    }
}Snake;

const int maxn = 21;
const int dir[4][2] = {0,1, 1,0, 0,-1, -1,0};

int n, m, l;
int g[maxn][maxn], vis[maxn][maxn][1<<14];

bool Judge(Snake p, int t){
    int a, b, nx, ny, flag;
    int row, col;
    row = p.x + dir[t][0];
    col = p.y + dir[t][1];
    
    a = p.x; b = p.y;
    
    if(row == a && col == b) return false;
    int k = l - 1;
    while(k--){
        int q = p.st & 3;
        p.st >>= 2;
        
        nx = a + dir[q][0];
        ny = b + dir[q][1];
        
        if(nx == row && ny == col) return false;
        a = nx; b = ny;
    }
    return true;
}
void bfs(Snake s){
    Snake p, tmp;
    queue<Snake> q;
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    
    q.push(s);
    vis[s.x][s.y][s.st] = 1;
    
    while(!q.empty()){
        p = q.front();
        q.pop();
        
        if(p.x == 1 && p.y == 1){
            printf("%d\n", vis[p.x][p.y][p.st] - 1);
            return;
        }
        
        for(int i = 0; i < 4; ++i){
            int nx = p.x + dir[i][0];
            int ny = p.y + dir[i][1];
            tmp = node(nx, ny, p.st);
            
            tmp.st = tmp.st & ((1 << (2 * (l - 2))) - 1);
            tmp.st <<= 2;
            tmp.st |= (i + 2) % 4;
            
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m && !vis[tmp.x][tmp.y][tmp.st] && !g[nx][ny] && Judge(p, i)){
                vis[nx][ny][tmp.st] = vis[p.x][p.y][p.st] + 1;
                q.push(tmp);
            }
        }
    }
    puts("-1");
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    int cas = 1;
    int a, b, k, tmp1, tmp2;
    while(~scanf("%d%d%d", &n, &m, &l)){
        if(n == 0 && m == 0 && l == 0) break;
        
        Snake ss;
        for(int i = 0; i < l; ++i){
            scanf("%d%d", &a, &b);
            
            if(i == 0) ss = node(a, b, 0);
            else{
                for(int j = 0; j < 4; ++j){
                    int nx = tmp1 + dir[j][0];
                    int ny = tmp2 + dir[j][1];
                    
                    if(nx == a && ny == b){
                        ss.st |= j << (2 * (i - 1));
                        break;
                    }
                }
            }
            tmp1 = a; tmp2 = b;
        }

        scanf("%d", &k);
        memset(g, 0, sizeof(g));
        for(int i = 0; i < k; ++i){
            scanf("%d%d", &a, &b);
            g[a][b] = 1;
        }
        
        printf("Case %d: ", cas);
        bfs(ss);
        ++cas;
    }
    return 0;
}