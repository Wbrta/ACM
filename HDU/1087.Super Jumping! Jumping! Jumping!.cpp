#include <cstdio>
using namespace std;
const int maxn = 1000 + 10;
int dp[maxn], num[maxn];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	int n;
	while(~scanf("%d", &n) && n){
		for(int i = 0; i < n; ++i){
			scanf("%d", num + i);
		}
		
		int ans = 0;
		for(int i = 0; i < n; ++i){
			dp[i] = num[i];
			for(int j = 0; j < i; ++j){
				if(num[i] > num[j]){
					dp[i] = Max(dp[i], dp[j] + num[i]);
				}
			}
			ans = Max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
