#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
double a[maxn];
inline double fun(double x){
	return x * x;
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; ++i){
			scanf("%lf", &a[i]);
		}

		double avg = 0, avgg = 0, ans = 0;
		for(int i = 0; i < m; ++i){
			avg += a[i];
		}
		avg /= m;
		for(int i = 0; i < m; ++i){
			ans += (a[i] - avg) * (a[i] - avg);
		}
		ans /= m - 1;
		printf("%.8f\n", sqrt(ans));
		for(int i = 1; i < n - m + 1; ++i){
			double t = (a[i+m-1] - a[i-1]) / m;
			double tt = (-t) * ( 2 * avg - (m-1)*t - 2*a[i-1] ) + fun(a[i+m-1]-avg-t) - fun(a[i-1]-avg);
			tt /= (m - 1);
			ans += tt;
			printf("%.8f\n", sqrt(ans));
			avg += t;
		}
	}
	return 0;
}