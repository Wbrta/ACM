#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int dir[8][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};

int x1, y1, x2, y2;
int vis[10][10];
struct node{
    int x, y;
    node(){}
    node(int a, int b) {
        x = a; y = b;
    }
};

int bfs(){
    queue<node> q;
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    q.push(node(x1, y1));
    vis[x1][y1] = 1;
    
    while(!q.empty()){
        node p = q.front();
        q.pop();
        
        if(p.x == x2 && p.y == y2) return vis[p.x][p.y] - 1;
        for(int i = 0; i < 8; ++i){
            int nx = p.x + dir[i][0];
            int ny = p.y + dir[i][1];
            
            if(nx > 0 && nx <= 8 && ny > 0 && ny <= 8 && !vis[nx][ny]){
                vis[nx][ny] = vis[p.x][p.y] + 1;
                q.push(node(nx, ny));
            }
        } 
    }
}
int main()
{
    char a, b;
    while(~scanf(" %c%d %c%d", &a, &y1, &b, &y2)){
        x1 = a - 'a' + 1;
        x2 = b - 'a' + 1;
        printf("To get from %c%d to %c%d takes %d knight moves.\n", a, y1, b, y2, bfs());
    }
    return 0;
}