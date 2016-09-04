#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100 + 5;

int dp[maxn][maxn];
int num[5][5] = {
				5, -1, -2, -1, -3,
				-1, 5, -3, -2, -4,
				-2, -3, 5, -2, -2,
				-1, -2, -2, 5, -1,
				-3, -4, -2, -1, 0
				};
int a[maxn], b[maxn];
char str1[maxn], str2[maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int t, n, m;
	scanf("%d", &t);
	while(t--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));

		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf(" %c", &str1[i]);
		scanf("%d", &m);
		for(int i = 0; i < m; ++i) scanf(" %c", &str2[i]);

		for(int i = 0; i < n; ++i){
			switch(str1[i]){
				case 'A': a[i] = 0; break;
				case 'C': a[i] = 1; break;
				case 'G': a[i] = 2; break;
				case 'T': a[i] = 3; break;
				case '-': a[i] = 4; break;
			}
		}

		for(int i = 0; i < m; ++i){
			switch(str2[i]){
				case 'A': b[i] = 0; break;
				case 'C': b[i] = 1; break;
				case 'G': b[i] = 2; break;
				case 'T': b[i] = 3; break;
				case '-': b[i] = 4; break;
			}
		}

		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				dp[i][j] = -INF;
			}
		}
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i-1][0] + num[a[i-1]][4];
        for (int j = 1; j <= m; j++)  
            dp[0][j] = dp[0][j-1] + num[4][b[j-1]];

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				dp[i][j] = Max(dp[i][j], dp[i-1][j-1] + num[a[i-1]][b[j-1]]);
				dp[i][j] = Max(dp[i][j], dp[i-1][j] + num[4][a[i-1]]); 
				dp[i][j] = Max(dp[i][j], dp[i][j-1] + num[4][b[j-1]]);
			}
		}

		printf("%d\n", dp[n][m]);
	}
	return 0;
}