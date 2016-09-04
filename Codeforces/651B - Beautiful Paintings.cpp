#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int cont[maxn];
inline int Min(int a, int b){
	return a < b ? a : b;
}
inline int Max(int a, int b){
	return a > b ? a : b;
}
int main()
{
	int n;
	while(~scanf("%d", &n)){
		memset(cont, 0, sizeof(cont));
		int b = maxn, e = 0;
		for(int i = 0; i < n; ++i){
			int val;
			scanf("%d", &val);
			++cont[val];
			b = Min(b, val);
			e = Max(e, val);
		}
		
		int ans = 0;
		bool flag = true;
		while(flag){
			int cnt = 0;
			for(int i = b; i <= e; ++i){
				if(cont[i]){
					++cnt;
					--cont[i];
				}
			}
			
			if(!cnt) flag = false;
			ans += cnt - 1;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
