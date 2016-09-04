#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
const int maxk = 1e5 + 5;
int n, K, a[maxn], m[maxn], dp[maxk];

void solve(){
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= K; ++j){
			if(dp[j] >= 0){
				dp[j] = m[i];
			}else if(j < a[i] || dp[j - a[i]] <= 0){
				dp[j] = -1;
			}else{
				dp[j] = dp[j - a[i]] - 1;
			}
		}
	}
	if(dp[K] >= 0) printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &m[i]);
		}
		scanf("%d", &K);
		solve();
	}
	return 0;
} 
