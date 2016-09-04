#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};

int n, k;
int hole[maxn][maxn], dp[maxn][maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
int dfs(int x, int y){
	// printf("(%d, %d)\n", x, y);
	if(dp[x][y] != -1) return dp[x][y];
	int res = 0;
	for(int i = 0; i < 4; ++i){
		for(int j = 1; j <= k; ++j){
			int nx = x + j * dir[i][0];
			int ny = y + j * dir[i][1];

			if(nx >= 0 && ny >= 0 && nx < n && ny < n && hole[nx][ny] > hole[x][y])
				res = Max(res, dfs(nx, ny));
		}
	}
	return dp[x][y] = res + hole[x][y];
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	
	while(~scanf("%d%d", &n, &k)){
		if(n == -1 && k == -1) break;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &hole[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}