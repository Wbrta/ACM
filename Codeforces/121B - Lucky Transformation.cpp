#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
char num[maxn];

int main()
{
	int n, k;
	while(~scanf("%d%d", &n, &k)){
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= n; ++i){
			scanf(" %c", &num[i]);
		}
		int x = 1, cont = 0;
		while(k){
			if(num[x] == '4' && num[x + 1] == '4' && num[x + 2] == '7' && x % 2 == 1){
				num[x + 1] = (k % 2 ? '7' : '4');
				break;
			}else if(num[x] == '4' && num[x + 1] == '7' && num[x + 2] == '7' && x % 2 == 1){
				num[x + 1] = (k % 2 ? '4' : '7');
				break;
			}else if(num[x] == '4' && num[x + 1] == '7'){
				num[x] = num[x + 1] = (x % 2 ? '4' : '7');
				--k;
				++x;
			}else{
				++x; ++cont;
			}
			
			if(cont == n) break;
			if(x > n) {
				x = 1;
				cont = 0;
			}
		}
		for(int i = 1; i <= n; ++i) putchar(num[i]);
		puts("");
	}
	return 0;
}
