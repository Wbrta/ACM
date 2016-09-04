#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
typedef struct node
{
	int id;
	int w, s;	
}mice;

mice a[maxn];
int dp[maxn], pre[maxn];

bool cmp(mice x, mice y){
	if(x.s == y.s) return x.w > y.w;
	else return x.s > y.s;
}
void Print(int pos){
	if(pre[pos] == pos){
		printf("%d\n", a[pos].id);
		return;
	}
	Print(pre[pos]);
	printf("%d\n", a[pos].id);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n = 0;
	while(~scanf("%d%d", &a[n].w, &a[n].s)) {a[n].id = n + 1; ++n;}
	sort(a, a + n, cmp);

	// for (int i = 0; i < n; ++i){
	// 	printf("%d %d %d\n", a[i].w, a[i].s, a[i].id);
	// }

	int ans = 0, pos = 0;
	for(int i = 0; i < n; ++i){
		dp[i] = 1;
		pre[i] = i;
		for(int j = 0; j < i; ++j){
			if(a[j].w < a[i].w && a[j].s > a[i].s){
				if(dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
		}

		if(ans < dp[i]){
			ans = dp[i];
			pos = i;
		}
	}
	printf("%d\n", ans);
	Print(pos);
	return 0;
}