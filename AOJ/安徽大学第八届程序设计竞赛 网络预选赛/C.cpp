#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
bool num[maxn];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		memset(num, false, sizeof(num));
		for(int cas = 2; cas <= n; ++cas)
			for(int i = 1; i <= n; ++i){
				if(i % cas == 0){
					num[i] = !num[i];
				}
			}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(num[i]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
