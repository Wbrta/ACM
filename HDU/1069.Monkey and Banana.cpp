#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff

const int maxn = 200;
typedef struct node{
	int x, y, z;
	node(){}
	node(int a, int b, int c){
		x = a; y = b; z = c;
	}
}Rectange;

int dp[maxn];
Rectange r[maxn];

inline int Max(int a, int b){
	return a > b ? a : b;
}
bool cmp(Rectange a, Rectange b){
	return (a.x == b.x ? (a.y > b.y) : (a.x > b.x));
}
int main()
{
	int n, x, y, z, cas = 1;
	while(~scanf("%d", &n) && n){
		int len = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d", &x, &y, &z);
			
			r[len++] = node(x, y, z);
			r[len++] = node(y, x, z);
			r[len++] = node(x, z, y);
			r[len++] = node(z, x, y);
			r[len++] = node(z, y, x);
			r[len++] = node(y, z, x);
		}
		
		sort(r, r + len, cmp);
		memset(dp, 0, sizeof(dp));
		int ans = -INF;
		for(int i = 0; i < len; ++i){
			int res = r[i].z;
			for(int j = 0; j < i; ++j){
				if( ( r[i].x < r[j].x && r[i].y < r[j].y ) ){
					res = Max(res, dp[j] + r[i].z);
				}
			}
			dp[i] = res;
			ans = Max(ans, res);
		}
		printf("Case %d: maximum height = %d\n", cas ++, ans);
	}
	return 0;
}
