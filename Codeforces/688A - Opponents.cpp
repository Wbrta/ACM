#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 5;
int main()
{
	int n, d, ans = 0, tmp = 0;
	scanf("%d%d", &n, &d);
	for(int i = 0; i < d; ++i){
		char str[maxn] = {0};
		scanf(" %s", str);
		bool flag = false;
		for(int j = 0; j < n; ++j){
			if(str[j] == '0') {
				flag = true;
				break;
			}
		}
		if(flag){
			tmp ++;
		}else{
			tmp = 0;
		}
		if(tmp > ans) ans = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
