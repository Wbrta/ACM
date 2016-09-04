#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;

int n, m;
char s[maxn][maxn];

void dfs(int row, int col){
    s[row][col] = '*';
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if(i == 0 && j == 0) continue;
            int nx = row + i;
            int ny = col + j;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '@'){
                dfs(nx, ny);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d", &n, &m)){
        if(m == 0) break;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                scanf(" %c", &s[i][j]);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(s[i][j] == '@'){
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}