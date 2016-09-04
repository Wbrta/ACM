#include <cstdio>
using namespace std;
#define INF 0x7fffffff
const int maxn = 10000 + 5;
int los[maxn], num[maxn];
inline int Max(int a, int b){
	return a > b ? a : b;
}
int main()
{
	int n;
	while(~scanf("%d", &n)){
		int res = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &num[i]);
			los[num[i]] = i;
			res = Max(res, num[i]);
		}
		int sum = 0;
		for(int i = 1; i <= n; ++i){
			int cur = INF;
			for(int j = 2 * num[i]; j <= res; j += num[i]){
				if(los[j] < cur && los[j] > i){
					cur = los[j];
				}
			}
			if(cur != INF){
				sum += cur;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
