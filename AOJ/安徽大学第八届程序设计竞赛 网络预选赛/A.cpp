#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int pre[maxn], num[maxn];
int find(int x){
	int fx = x;
	while(fx != pre[fx]){
		fx = pre[fx];
	}
	pre[x] = fx;
	return fx;
}
void join(int x, int y){
	int fx = find(x);
	int fy = find(y);
	pre[fx] = fy;
}
int main()
{
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		memset(pre, 0, sizeof(pre));
		memset(num, 0, sizeof(num));
		int a, b;
		pre[0] = 0;
		for(int i = 1; i <= n; ++i){
			pre[i] = i;
		}
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			join(a, b);
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			num[i] = find(i);
		}
		sort(num + 1, num + n + 1);
		for(int i = 1; i <= n; ++i){
			if(num[i] != num[i-1])	++ans;
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
