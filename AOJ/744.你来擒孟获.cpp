#include <cstdio>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1000 + 5;

bool vis[maxn];
int cost[maxn][maxn];
int d1[maxn], d2[maxn];
int n, m, T, s, t, a, b, c;

inline int Max(int x, int y){
	return (x > y ? x : y);
}
void dijkstra(int s){
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; ++i) d2[i] = cost[s][i];
	vis[s] = 1;

	for(int i = 1; i < n; ++i){
		int k, min = INF;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && d2[j] < min){
				min = d2[j];
				k = j;
			}
		}
		vis[k] = 1;
		for(int j = 0; j < n; ++j){
			if(!vis[j] && (d2[k] + cost[k][j] < d2[j])){
				d2[j] = d2[k] + cost[k][j];
			}
		}
	}
}
int main()
{
	//freopen("test.in", "r+", stdin);
	//freopen("test.out", "w+", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(i == j) cost[i][j] = 0;
				else cost[i][j] = INF;
			}
		}

		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			cost[a][b] = cost[b][a] = c;
		}
		scanf("%d%d", &s, &t);

		dijkstra(s);
		for(int i = 0; i < n; ++i) d1[i] = d2[i];
		dijkstra(t);

		int ans = 0;
		for(int i = 0; i < n; ++i){
			ans = Max(ans, d1[i] + d2[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}