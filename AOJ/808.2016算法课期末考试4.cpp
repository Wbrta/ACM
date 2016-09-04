#include <cstdio>
#include <cstring>
using namespace std;
//#define Accept 1
const int maxn = 1000;
int p;
char ans[maxn];

void dfs(int num, int lim){
	if(num < 0) return;
	if(num == 0) {
		puts(ans);
		return;
	}
	for(int i = lim; i >= 1; --i){
		int tmp = p;
		if(i / 10) ans[p++] = i / 10 + '0';
		ans[p++] = i % 10 + '0';
		if(num - i > 0) ans[p++] = '+'; 
		dfs(num - i, i);
		for(int j = tmp; j < p; ++j) ans[j] = 0;
		p = tmp;
	}
}
int main()
{
	#ifndef Accept
	#define Accept 1
	int n;
	while(~scanf("%d", &n)){
		p = 0;
		memset(ans, 0, sizeof(ans));
		dfs(n, n);
	}
	#else
	freopen("test.out", "w+", stdout);
	int n;
	scanf("%d", &n);
	p = 0;
	memset(ans, 0, sizeof(ans));
	dfs(n, n);
	#endif
	return 0;
}
