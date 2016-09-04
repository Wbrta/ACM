#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
char num[maxn][maxn];
int d[maxn], l[maxn], r[maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int n, m;
	while(~scanf("%d%d", &n, &m)){
		for(int i = 0; i < n; ++i){
			scanf(" %s", num[i]);
		}

		int ans = 0;
		for(int i = 0; i < n; ++i){
			memset(d, 0, sizeof(d));
			for(int k = 0; k < m; ++k){
				for(int j = i; j < n; ++j){
					if(num[j][k] == '0') break;
					d[k] += 1;
				}
			}
			sort(d, d + m);

			l[0] = 0;
			r[m-1] = m-1;

			for(int j = 1; j < m; ++j){
				int pos = j;
				while(pos > 0 && d[pos - 1] >= d[j]) pos = l[pos - 1];
				l[j] = pos;
			}
			for(int j = m - 2; j >= 0; --j){
				int pos = j;
				while(pos < m - 1 && d[pos + 1] >= d[j]) pos = r[pos + 1];
				r[j] = pos;
			}
			int res = 0;
			for(int j = 0; j < m; ++j){
				res = Max(res, d[j] * (r[j] - l[j] + 1));
			}
			ans = Max(res, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
