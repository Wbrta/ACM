#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

const int maxn = 17;
typedef struct node{
	char name[105];
	int d, c;
}HW;

HW hw[maxn];
int dp[1 << 17], sum[1 << 17], pre[1 << 17];

bool cmp(HW a, HW b){
	return strcmp(a.name, b.name) >= 0;
}
inline int Min(int x, int y){
	return ( x < y ? x : y );
}
inline int Max(int x, int y){
	return ( x > y ? x : y );
}
void Print(int st){
	if(st == 0) return;
	Print(pre[st]);

	int j = 0, tmp = st ^ pre[st];
	while(tmp){
		tmp >>= 1;
		++j;
	}
	printf("%s\n", hw[j - 1].name);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(hw, 0, sizeof(hw));
		memset(pre, 0, sizeof(pre));
		memset(sum, 0, sizeof(sum));
		for(int i = 0; i < n; ++i){
			scanf(" %s%d%d", hw[i].name, &hw[i].d, &hw[i].c);
		}
		sort(hw, hw + n, cmp);

		int st = (1 << n) - 1;
		for(int i = 1; i <= st; ++i) dp[i] = INF;
		dp[0] = 0;
		for(int i = 1; i <= st; ++i){
			int k;
			for(int j = 0; j < n; ++j){
				int tmp = 1 << j;
				if(i & tmp){
					int tt = sum[i - tmp] + hw[j].c;
					if(dp[i] > dp[i - tmp] + Max(tt - hw[j].d, 0)){
						dp[i] = dp[i - tmp] + Max(tt - hw[j].d, 0);
						sum[i] = tt;
						k = i - tmp;
					}
				}
			}
			pre[i] = k;
		}
		printf("%d\n", dp[st]);
		Print(st);
	}
	return 0;
}
