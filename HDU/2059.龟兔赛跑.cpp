#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 100 + 10;
int p[maxn];
double dp[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int l, n, c, t;
	int vr, vt1, vt2;
	while(~scanf("%d", &l)){
		scanf("%d%d%d", &n, &c, &t);
		scanf("%d%d%d", &vr, &vt1, &vt2);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &p[i]);
		}
		p[0] = 0; p[++n] = l;
		memset(dp, 0, sizeof(dp));

		double dis, tmp;
		for(int i = 1; i <= n; ++i){
			double mi = INF;
			for(int j = 0; j < i; ++j){
				int dis = p[i] - p[j];
				if(dis < c)
					tmp = dis * 1.0 / vt1;
				else
					tmp = c * 1.0 / vt1 + (dis - c) * 1.0 / vt2;
				if(j) tmp += t;
				mi = min(mi, dp[j] + tmp);
			}
			dp[i] = mi;
		}

		if(dp[n] * vr < l){
			printf("What a pity rabbit!\n");
		}else{
			printf("Good job,rabbit!\n");
		}
	}
	return 0;
}