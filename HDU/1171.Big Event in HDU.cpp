#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 55;
int v[maxn], m[maxn], dp[1005 * 55 * 105];

inline int Max(int a, int b){
	return (a > b ? a : b);
}
int main()
{
	int n;
	while(~scanf("%d", &n) && n >= 0){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &v[i], &m[i]);
			sum += v[i] * m[i];
		}
		int tmp = sum;
		sum /= 2;
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; ++i){
			int t = 1;
			while(m[i]){
				if(m[i] < t){
					t = m[i];
				}
				m[i] -= t;
				
				for(int j = sum; j >= v[i] * t; --j){
					dp[j] = Max(dp[j], dp[ j - v[i] * t ] + t * v[i]);
					ans = Max(ans, dp[j]);
				}
				t << 1;
			}
		}
		
		printf("%d %d\n", tmp - ans, ans);
	}
	return 0;
}
