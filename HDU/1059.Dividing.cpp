#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 40000 + 5;
int a[6], dp[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int cas = 1;
	while(~scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5])){
		if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0) break;
		int sum = 0;
		for(int i = 0; i < 6; ++i) sum += (i + 1) * a[i];
		if(sum % 2){
			printf("Collection #%d:\n", cas);
			printf("Can't be divided.\n");
		}else{
			sum /= 2;
			memset(dp, -1, sizeof(dp));
			dp[0] = 0;
			for(int i = 0; i < 6; ++i){
				for(int j = 0; j <= sum; ++j){
					if(dp[j] >= 0){
						dp[j] = a[i];
					}else if(j < (i + 1) || dp[j - (i + 1)] <= 0){
						dp[j] = -1;
					}else{
						dp[j] = dp[j - (i + 1)] - 1;
					}
				}
			}
			if(dp[sum] >= 0){
				printf("Collection #%d:\n", cas);
				printf("Can be divided.\n");
			}else{
				printf("Collection #%d:\n", cas);
				printf("Can't be divided.\n");
			}
		}
		puts("");
		++cas;
	}
	return 0;
}