#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};
const int maxn = 10;

bool flag;
int n, m, t;
int a, b, c, d, cont;
char maze[maxn][maxn];

inline int f(int x){
    return (x > 0 ? x : -x);
}
void dfs(int row, int col, int step){
    //printf("step %d: (%d, %d)\n", step, row, col);
    if(flag) return;
    
    if(step == t){
        if(row == c && col == d){
            flag = true;
            //printf("Flag has been true\n");
        }
        return;
    }
    
    int tmp = (t - step) - (f(row - c) + f(col - d));
    if(tmp < 0 || tmp & 1) return;
    
    for(int i = 0; i < 4; ++i){
        int nx = row + dir[i][0];
        int ny = col + dir[i][1];
        
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != 'X'){
            maze[nx][ny] = 'X';
            dfs(nx, ny, step + 1);
            maze[nx][ny] = '.';
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &t)){
        if(n == 0 && m == 0 && t == 0) break;
           
        cont = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                scanf(" %c", &maze[i][j]);
                if(maze[i][j] == 'S'){
                    a = i;
                    b = j;
                }else if(maze[i][j] == 'D'){
                    c = i;
                    d = j;
                }else if(maze[i][j] == 'X'){
                    ++cont;
                }
            }
        }
        
        if(n * m <= t + cont) {
            printf("NO\n");
            continue;
        }
        
        maze[a][b] = 'X';
        flag = false;
        dfs(a, b, 0);
        
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}