#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL, LL > pi;
const int maxn = 1e5;
pi b[maxn];
LL a[maxn];
bool cmp(pi x, pi y){
	return (x.first == y.first ? (x.second > y.second) : (x.first < y.first));
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	LL t, n, L, R;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld%lld%lld", &n, &L, &R);
		for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		sort(a, a + n);
		for(int i = 0; i < n - 1; ++i){
			b[i].first = a[i+1] - a[i];
			b[i].second = a[i+1] + a[i];
		}
		if(n - 1 >= 2)
			sort(b, b + n - 1, cmp);
		LL ans = 0, tmp1 = L, tmp2 = L;
		for(int i = 0; i < n - 1; ++i){
			if(b[i].second <= L) continue;
			if(b[i].first > R) break;

			if(b[i].first >= tmp2){
				tmp1 = b[i].first;
				ans += tmp1 - tmp2 + 1;
			}
			if(b[i].second > tmp2){
				tmp2 = b[i].second;
			}
			if(tmp2 > R){
				tmp2 = R + 1;
				break;
			}
		}
		ans += (R >= tmp2 ? (R - tmp2 + 1) : 0 );
		printf("%lld\n", ans);
	}
	return 0;
}
