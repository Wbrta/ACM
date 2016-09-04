#include <cstdio>
#include <cstring>
using namespace std;
#define mod 998244353
#define INF 0x3f3f3f3f
typedef long long LL;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
		a[0] = INF; b[0] = -1;

		LL ans = 1;
		for(int i = 1; i <= n; ++i){
			if(i == 1 && a[i] != b[i]){
				ans = 0;
				break;
			}
			if(a[i] > a[i-1]) {
				ans = 0;
				break;
			}
			if(b[i] < b[i-1]){
				ans = 0;
				break;
			}
			if(b[i] < a[i]){
				ans = 0;
				break;
			}
			if(i != 1 && a[i] < a[i-1] && b[i] > b[i-1]){
				ans = 0;
				break;
			}

			if(a[i] == a[i-1] && b[i] == b[i-1]){
				if(b[i] - a[i] + 2 - i <= 0) {
					ans = 0;
					break;
				}
				ans = (ans * (b[i] - a[i] + 2 - i)) % mod;
			}
		}

		printf("%lld\n", ans);
	}
	return 0;
}