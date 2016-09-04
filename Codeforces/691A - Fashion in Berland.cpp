#include <cstdio>
using namespace std;
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, val;
	while(~scanf("%d", &n)){
		if(n == 1){
			scanf("%d", &val);
			if(val == 1) printf("YES\n");
			else printf("NO\n");
		}else{
			int flag = 0;
			for(int i = 0; i < n; ++i){
				scanf("%d", &val);
				if(flag == 0 && val == 0){
					flag = 1;
				}else if(flag == 1 && val == 0){
					flag = -1;
				}
			}
			if(flag == 1) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}