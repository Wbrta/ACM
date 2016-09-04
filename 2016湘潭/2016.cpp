#include <cstdio>
#include <cstring>
using namespace std;
#define mod 2016
const int maxn = 100000 + 10;
char str[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int a, b, c, d;
	while(~scanf(" %s", str)){
		int num = 0, len = strlen(str);
		for(int i = 0; i < len; ++i){
			num = (num * 10) % mod;
			num = (num + str[i] - '0') % mod;
		}
		scanf("%d%d%d%d", &a, &b, &c, &d);

		int ans1 = 1, ans2 = 0, ans3 = 0, ans4 = 1;
		for(int i = 0; i < num; ++i){
			int tmp1 = (ans1 * a + ans2 * c) % 7;
			int tmp2 = (ans1 * b + ans2 * d) % 7;
			int tmp3 = (ans3 * a + ans4 * c) % 7;
			int tmp4 = (ans3 * b + ans4 * d) % 7;

			ans1 = tmp1;
			ans2 = tmp2;
			ans3 = tmp3;
			ans4 = tmp4;
		}
		printf("%d %d\n%d %d\n", ans1, ans2, ans3, ans4);
	}
	return 0;
}
