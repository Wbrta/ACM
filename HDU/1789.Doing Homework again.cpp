#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
typedef struct{
	int dl;
	int rd;
}HW;

HW hw[maxn];
int vis[maxn];

bool cmp(HW a, HW b){
	if(a.rd != b.rd) return a.rd > b.rd;
	else return a.dl < b.dl;
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; ++i){
			scanf("%d", &hw[i].dl);
		}
		for(int i = 0; i < n; ++i){
			scanf("%d", &hw[i].rd);
		}

		sort(hw, hw + n, cmp);
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int flag = 0;
			for(int j = hw[i].dl; j > 0; --j){
				if(!vis[j]){
					vis[j] = 1;
					flag = 1;
					break;
				}
			}
			if(!flag) ans += hw[i].rd;
		}
		printf("%d\n", ans);
	}
	return 0;
}