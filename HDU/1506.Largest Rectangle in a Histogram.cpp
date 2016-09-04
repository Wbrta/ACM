#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
typedef long long LL;
LL l[maxn], r[maxn], a[maxn];
inline LL Max(LL a, LL b){
	return (a > b ? a : b);
}
int main()
{
	LL n;
	ios::sync_with_stdio(false);
	while(cin >> n && n){
		LL ans = 0;
		for(int i = 0; i < n; ++i) cin >> a[i];
		l[0] = 0;
		r[n-1] = n-1;
		for(int i = 1; i < n; ++i){
			int pos = i;
			while(pos > 0 && a[pos - 1] >= a[i]) pos = l[pos - 1];
			l[i] = pos;
		}
		for(int i = n - 2; i >= 0; --i){
			int pos = i;
			while(pos < n - 1 && a[pos + 1] >= a[i]) pos = r[pos + 1];
			r[i] = pos;
		}
		for(int i = 0; i < n; ++i){
			ans = Max(ans, (r[i] - l[i] + 1) * a[i]);
			//cout << r[i] << "	" << l[i] << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
