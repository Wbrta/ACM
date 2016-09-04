#include <set>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 100000 + 5;
int pre[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, d, h;
	while(~scanf("%d%d%d", &n, &d, &h)){
		if(d > 2 * h || n <= d || n <= h || (d == 1 && n > 2)){
			//printf("%d %d %d\n", (d > 2 * h), (n <= d), (d == 1 && n > 2));
			puts("-1");
			continue;
		}

		memset(pre, 0, sizeof(pre));
		pre[1] = 1;
		for(int i = 2; i <= h + 1; ++i){
			pre[i] = i - 1;
		}
		pre[h + 2] = 1;
		for(int i = h + 3; i <= d + 1; ++i){
			pre[i] = i - 1;
		}
		for(int i = d + 2; i <= n; ++i){
			pre[i] = (h > 1 ? 2 : 1);
		}
		for(int i = n; i > 1; --i){
			printf("%d %d\n", i, pre[i]);
		}
		// puts("");
	}
	return 0;
}