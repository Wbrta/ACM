#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int num[maxn][maxn], d[maxn];


inline int Max(int x, int y){
	return (x >= y ? x : y);
}
int fun(int n){
	int sum = 0, tmp = 0;
	for(int k = 0; k < n; ++k){
		tmp += d[k];

		if(tmp > sum) sum = tmp;
		if(tmp < 0) tmp = 0;
	}
	return sum;
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &num[i][j]);
			}
		}

		int ans = 0;
		for(int i = 0; i < n; ++i){
			memset(d, 0, sizeof(d));
			for(int j = i; j < n; ++j){
				for(int k = 0; k < n; ++k){
					d[k] += num[j][k];
				}
				ans = Max(ans, fun(n));
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}