#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int val[maxn], w[maxn], dp[maxn];
inline int Max(int a, int b){
	return (a > b ? a : b);
}
int main()
{
	int t, n, V;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &V);
		for(int i = 0; i < n; ++i) scanf("%d", &val[i]);
		for(int i = 0; i < n; ++i) scanf("%d", &w[i]);
		
		fill(dp, dp + 1 + V, 0);
		for(int i = 0; i < n; ++i){
			for(int j = V; j >= w[i]; --j){
				dp[j] = Max(dp[j], dp[ j - w[i]] + val[i]);
			}
		}
		printf("%d\n", dp[V]);
	}
	return 0;
}
