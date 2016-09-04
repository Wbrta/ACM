#include <cstdio>
using namespace std;
#define INF 0x7fffffff
int main()
{
	int k, n, val;
	scanf("%d", &k);
	for(int cas = 1; cas <= k; ++cas){
		int sum = -INF, tmp = 0, begin = 0, end = 0, tmp_l = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &val);

			if(tmp_l == 0) tmp_l = i + 1;
			tmp += val;
			if(tmp > sum){
				sum = tmp;
				begin = tmp_l;
				end = i + 1;
			}
			
			if(tmp < 0){
				tmp = 0;
				tmp_l = i + 2;
			}
		}
		
		printf("Case %d:\n", cas);
		printf("%d %d %d\n", sum, begin, end);
		if(cas != k) puts("");
	}
	return 0;
}
