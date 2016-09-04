#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int w[maxn];
int main()
{
	int n, m, t, l, r, k;
	while(~scanf("%d%d%d", &n, &m, &t)){
		memset(w, 0, sizeof(w));
		for(int i = 1; i <= n; ++i){
			scanf("%d", &w[i]);
		}
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d", &l, &r, &k);
			for(int j = l; j <= r; ++j)
				w[j] += k;
		}
		for(int i = 0; i < t; ++i){
			int sum = 0;
			scanf("%d%d", &l, &r);
			for(int j = l; j <= r; ++j)
				sum += w[j];
			printf("%d\n", sum);
		}
	}
	return 0;
}
