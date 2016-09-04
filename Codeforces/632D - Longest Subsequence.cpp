#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 5;
int num[maxn], a[maxn], sum[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	memset(num, 0, sizeof(num));
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		if(a[i] <= m){
			++num[a[i]];
		}
	}
	for(int i = 1; i <= m; ++i){
		if(num[i]){
			for(int j = i; j <= m; j += i){
				sum[j] += num[i];
			}
		}
	}
	int max_sum = 0, max_val = 0;
	for(int i = 1; i <= m; ++i){
		if(sum[i] && max_sum < sum[i]){
			max_val = i;
			max_sum = sum[i];
		}
	}
	if(max_sum == 0){
		printf("1 0\n\n");
	}else{
		int cas = 0;
		printf("%d %d\n", max_val, max_sum);
		for(int i = 0; i < n; ++i){
			if(max_val % a[i] == 0){
				if(cas){
					printf(" ");
				}
				printf("%d", i + 1);
				++cas;
			}
		}
		puts("");
	}
	return 0;
}
