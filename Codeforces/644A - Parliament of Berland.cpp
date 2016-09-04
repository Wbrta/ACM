#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int seat[maxn][maxn];
int main()
{
	int n, a, b;
	while(~scanf("%d%d%d", &n, &a, &b)){
		if(a * b < n){
			printf("-1\n");
			continue;
		}
		memset(seat, 0, sizeof(seat));
		int cur = 1;
		for(int i = 1; i <= a && cur <= n; ++i){
			if(i % 2){
				for(int j = 1; j <= b && cur <= n; ++j){
					seat[i][j] = cur++;
				}
			}else{
				for(int j = b; j > 0 && cur <= n; --j){
					seat[i][j] = cur++;
				}
			}
		}
		for(int i = 1; i <= a; ++i){
			for(int j = 1; j <= b; ++j){
				if(j != 1) printf(" ");
				printf("%d", seat[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
