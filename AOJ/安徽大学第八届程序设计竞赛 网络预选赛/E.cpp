#include <cstdio>
using namespace std;
const int maxn = 200 + 5;
int x[maxn], y[maxn];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &x[i], &y[i]);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				for(int k = j + 1; k < n; ++k){
					double k1 = (double)(y[i] - y[j]) / (double)(x[i] - x[j]);
					double k2 = (double)(y[i] - y[k]) / (double)(x[i] - x[k]);
					double k3 = (double)(y[k] - y[j]) / (double)(x[k] - x[j]);
					
					if(k1 != k2 && k2 != k3 && k1 != k3) ++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
