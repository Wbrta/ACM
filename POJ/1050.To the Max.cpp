#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int n, d[maxn];
int num[maxn][maxn];

inline int Max(int a, int b){
	return (a >= b ? a : b);
}
int fun(){
	int sum = 0, tmp = 0;
	for(int i = 0; i < n; ++i){
		tmp += d[i];
		
		if(tmp > sum) sum = tmp;
		if(tmp < 0) tmp = 0;
	}
	return sum;
}
int main()
{
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
				
				ans = Max(ans, fun());
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
