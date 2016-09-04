#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 100000 + 5;
int num[maxn];

inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n, a, b;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &a, &b);
			num[i] = a - b;
		}

		int tmp = 0, ans = 0, res = 0;
		for(int i = 0; i < 2 * n - 1; ++i){
			tmp += num[i % n];
			if(tmp >= 0){
				++res;
				ans = Max(ans, res);
				if(ans == n) break;
			}
			if(tmp < 0){
				tmp = 0;
				res = 0;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
