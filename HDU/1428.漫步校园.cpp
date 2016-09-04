#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int dir[4][2] = {1,0, -1,0, 0,1, 0,-1};
const int maxn = 50 + 2;

typedef long long LL;
typedef struct{
	int x, y;
}Coord;

int n;
LL dp[maxn][maxn];
int sc[maxn][maxn], mt[maxn][maxn];

bool Judge(int a, int b, int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < n){
		if(mt[x][y] > mt[a][b]){
			return true;
		}
	}
	return false;
}
LL dfs(int x, int y){
	//printf("(%d, %d)      dp[%d][%d] = %d\n", x, y, x, y, dp[x][y]);
	if(dp[x][y] != -1){
		return dp[x][y];
	}
	
	if(x == 0 && y == 0) {
		return dp[x][y] = 1;
	}else{
		return dp[x][y] = (Judge(x, y, x + 1, y) ? dfs(x + 1, y) : 0) + (Judge(x, y, x - 1, y) ? dfs(x - 1, y) : 0) 
			+ (Judge(x, y, x, y + 1) ? dfs(x, y + 1) : 0) + (Judge(x, y, x, y - 1) ? dfs(x, y - 1) : 0);
	}
}
void bfs(int x, int y){
	queue<Coord> q;
	while(!q.empty()) q.pop();
	memset(mt, 0, sizeof(mt));
	
	Coord t = {x, y};
	q.push(t);
	mt[x][y] = sc[x][y];
	
	while(!q.empty()){
		Coord p = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = p.x + dir[i][0];
			int ny = p.y + dir[i][1];
			
			if(nx >= 0 && nx < n && ny >= 0 && ny < n){
				if(!mt[nx][ny] || (mt[nx][ny] > mt[p.x][p.y] + sc[nx][ny])){
					mt[nx][ny] = mt[p.x][p.y] + sc[nx][ny];
					
					Coord tt = {nx, ny};
					q.push(tt);
				}
			}
		}
	}
}

int main()
{
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &sc[i][j]);
			}
		}
		bfs(n-1, n-1);
		/*for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				printf("%d ", mt[i][j]);
			}
			puts("");
		}*/
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", dfs(n-1, n-1));
	}
	return 0;
}
