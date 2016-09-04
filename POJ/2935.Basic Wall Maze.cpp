#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 8;
const char pri[4] = {'N', 'E', 'S', 'W'};
const int dir[4][2] = {-1,0, 0,1, 1,0, 0,-1};
typedef struct point{
    int x, y;
    point(){}
    point(int a, int b){x = a; y = b;}
}Coord;
typedef struct node{
    int x, y;
    bool to[4];
    node(int a = 0, int b = 0){
        x = a; y = b;
        to[0] = to[1] = to[2] = to[3] = 0;
    }
}Maze;

Maze m[maxn][maxn];
int sx, sy, ex, ey;
int vis[maxn][maxn];
Coord pre[maxn][maxn];

void Print(int row, int col){
    if(row == -1 && col == -1) return;
    Print(pre[row][col].x, pre[row][col].y);
    int nx, ny;
    for(int i = 0; i < 4; ++i){
        nx = pre[row][col].x + dir[i][0];
        ny = pre[row][col].y + dir[i][1];
        if(nx == row && ny == col){
            printf("%c", pri[i]);
            break;
        }
    }
}
void bfs(){
    queue<Maze> q;
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    
    vis[sy][sx] = 1;
    q.push(m[sy][sx]);
    
    while(!q.empty()){
        Maze p = q.front();
        q.pop();
        
        if(p.x == ey && p.y == ex){
            Print(ey, ex); puts("");
            return;
        }
        
        for(int i = 0; i < 4; ++i){
            int nx = p.x + dir[i][0];
            int ny = p.y + dir[i][1];
            
            if(!p.to[i] && nx >= 1 && nx <= 6 && ny >= 1 && ny <= 6 && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push(m[nx][ny]);
                pre[nx][ny] = point(p.x, p.y);
            }
        }
    }
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    int ax, ay, bx, by;
    while(~scanf("%d%d", &sx, &sy)){
        if(sx == 0 && sy == 0) break;
        scanf("%d%d", &ex, &ey);
        for(int i = 1; i <= 6; ++i){
            for(int j = 1; j <= 6; ++j){
                m[i][j] = node(i, j);
            }
        }

        for(int i = 0; i < 3; ++i){
            scanf("%d%d%d%d", &ax, &ay, &bx, &by);
            if(ax == bx){
                for(int i = min(ay, by) + 1; i <= max(ay, by); ++i){
                    if(ax == 0){
                        m[i][1].to[3] = 1;
                    }else if(ax == 6){
                        m[i][6].to[1] = 1;
                    }else{
                        m[i][ax].to[1] = m[i][ax+1].to[3] = 1;
                    }
                }
            }else{
                for(int i = min(ax, bx) + 1; i <= max(ax, bx); ++i){
                    if(ay == 0){
                        m[1][i].to[0] = 1;
                    }else if(ay == 6){
                        m[6][i].to[2] = 1;
                    }else{
                        m[ay][i].to[2] = m[ay+1][i].to[0] = 1;
                    }
                }
            }
        }

        bfs();
    }
    return 0;
}