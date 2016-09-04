#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int m[maxn];
double p[maxn], dp[maxn * maxn];
inline double Max(double a, double b){
	return (a >= b ? a : b);
}
int main()
{
	int t, N;
	double P;
	scanf("%d", &t);
	while(t--){
		int C = 0;
		scanf("%lf%d", &P, &N);
		P = 1 - P;
		for(int i = 0; i < N; ++i){
			scanf("%d%lf", &m[i], &p[i]);
			p[i] = 1 - p[i];
			C += m[i];
		}
		
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(int i = 0; i < N; ++i){
			for(int j = C; j >= m[i]; --j){
				dp[j] = Max(dp[j], dp[j - m[i]] * p[i]);
				//printf("dp[%d] = %.2f\n", j, dp[j]);
			}
		}
		
		for(int i = C; i >= 0; --i){
			if(dp[i] >= P){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
