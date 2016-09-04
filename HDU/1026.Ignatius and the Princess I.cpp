#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
const int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};
typedef struct Point{
    int x, y;
    int step;
    
    friend bool operator < (const Point &a, const Point &b){
        return a.step > b.step;
    }
}Point;

int n, m;
bool vis[maxn][maxn];
char maze[maxn][maxn];
Point pre[maxn][maxn];

void print(Point p){
    if(p.x == 0 && p.y == 0) {
        if(maze[p.x][p.y] >= '0' && maze[p.x][p.y] <= '9'){
            int tt = pre[p.x][p.y].step + 1;
            while(tt <= p.step){
                printf("%ds:FIGHT AT (%d,%d)\n", tt, p.x, p.y);
                ++tt;
            }
        }
        return;
    }
    print(pre[p.x][p.y]);
    printf("%ds:(%d,%d)->(%d,%d)\n", pre[p.x][p.y].step + 1, pre[p.x][p.y].x, pre[p.x][p.y].y, p.x, p.y);
    if(maze[p.x][p.y] >= '0' && maze[p.x][p.y] <= '9'){
        int tt = pre[p.x][p.y].step + 2;
        while(tt <= p.step){
            printf("%ds:FIGHT AT (%d,%d)\n", tt, p.x, p.y);
            ++tt;
        }
    }
}
void bfs(){
    priority_queue<Point> pq;
    while(!pq.empty()) pq.pop();
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    
    Point p;
    Point tmp, vec;
    if(maze[0][0] == '.'){
        p.x = p.y = p.step = 0;
    }else if(maze[0][0] == 'X'){
        printf("God please help our poor hero.\n");
        return;
    }else{
        p.x = p.y = 0;
        p.step = maze[0][0] - '0';
    }
    pre[p.x][p.y].x = -1;
    pre[p.x][p.y].x = -1;
    pre[p.x][p.y].step = 0;
    vis[p.x][p.y] = true;
    pq.push(p);
    
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        
        if(tmp.x == n - 1 && tmp.y == m - 1){
            printf("It takes %d %s to reach the target position, let me show you the way.\n", tmp.step, (tmp.step == 1 ? "second" : "seconds"));
            print(tmp);
            return;
        }
        
        for(int i = 0; i < 4; ++i){
            vec.x = tmp.x + dir[i][0];
            vec.y = tmp.y + dir[i][1];
            
            if(vec.x >= 0 && vec.x < n && vec.y >= 0 && vec.y < m && !vis[vec.x][vec.y] && maze[vec.x][vec.y] != 'X'){
                if(maze[vec.x][vec.y] >= '0' && maze[vec.x][vec.y] <= '9'){
                    vec.step = tmp.step + maze[vec.x][vec.y] - '0' + 1;
                }else if(maze[vec.x][vec.y] == '.'){
                    vec.step = tmp.step + 1;
                }
                pre[vec.x][vec.y] = tmp;
                vis[vec.x][vec.y] = true;
                pq.push(vec);
            }
        }
    }
    printf("God please help our poor hero.\n");
}
int main()
{
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i < n; ++i){
            scanf(" %s", maze[i]);
        }
        bfs();
        printf("FINISH\n");
    }
    return 0;
}