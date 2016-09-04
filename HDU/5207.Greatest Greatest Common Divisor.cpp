#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int num[maxn];
inline int Max(int a, int b){
	return a > b ? a : b;
}
int main()
{
	int t, n, val;
	scanf("%d", &t);
	for(int cas = 1; cas <= t; ++cas){
		scanf("%d", &n);
		int max_val = 0;
		memset(num, 0, sizeof(num));
		for(int i = 0; i < n; ++i){
			scanf("%d", &val);
			for(int j = 1; j * j <= val; ++j){
				if(val % j == 0){
					++num[j];
					++num[val / j];
				}
			}
			max_val = Max(max_val, val);
		}
		bool flag = false;
		for(int i = max_val; !flag && i > 0; --i){
			if(num[i] >= 2){
				flag = true;
				printf("Case #%d: %d\n",cas, i);
			}
		}
	}
	return 0;
}
