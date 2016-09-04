#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000 + 5;
int a[maxn];
double b[maxn], dp[maxn];
inline double Min(double a, double b){
	return (a < b ? a : b);
}
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;
		for(int i = 0; i < m; ++i){
			scanf("%d%lf", &a[i], &b[i]);
			b[i] = 1 - b[i];
		}
		for(int i = 0; i <= n; ++i) dp[i] = 1;
		for(int i = 0; i < m; ++i){
			for(int j = n; j >= a[i]; --j){
				dp[j] = Min(dp[j], dp[j - a[i]] * b[i]);
			}
		}
		printf("%.1f%%\n", (1 - dp[n]) * 100);
	}
	return 0;
}
