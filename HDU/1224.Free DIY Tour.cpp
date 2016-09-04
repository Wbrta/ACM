#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;

int n, m, t, a, b;
vector<int> vec[maxn];
int in[maxn], dp[maxn], pre[maxn];

void PrinT(int x){
	if(x == 1) {
		printf("%d", x);
		return;
	}
	PrinT(pre[x]);
	printf("->%d", (x == (n + 1) ? 1 : x));
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas){
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for(int i = 0; i <= n + 1; ++i){
			vec[i].clear();
		}
		for(int i = 1; i <= n; ++i){
			scanf("%d", &in[i]);
		}
		in[n+1] = 0;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			vec[a].push_back(b);
		}

		for(int i = 1; i <= n; ++i){
			int len = vec[i].size();
			for(int j = 0; j < len; ++j){
				int v = vec[i][j];

				if(dp[v] < dp[i] + in[v]){
					dp[v] = dp[i] + in[v];
					pre[v] = i;
				}
			}
		}
		printf("CASE %d#\n", cas);
		printf("points : %d\n", dp[n+1]);
		printf("circuit : ");
		PrinT(n+1);
		puts("");
		if(cas != t) puts("");
	}
	return 0;
}