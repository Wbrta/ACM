#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
const int maxm = 100000 + 5;
int n, m;
int a[maxn], b[maxn], dp[maxm];
int solve(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= m; ++j){
			if(dp[j] >= 0){
				dp[j] = b[i];
			}else if(j < a[i] || dp[j - a[i]] <= 0){
				dp[j] = -1;
			}else{
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= m; ++i){
		if(dp[i] >= 0) ++ans;
	}
	return ans;
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &b[i]);
		}
		printf("%d\n", solve());
	}
	return 0;
}