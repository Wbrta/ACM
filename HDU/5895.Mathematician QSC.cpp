#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> pi;

LL euler(LL n) {
	LL ans = n;
	for (LL i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1) ans -= ans / n;
	return ans;
}
LL fastMul(LL a, LL b, LL mod) {
	LL ans = 1;
	while (b) {
		if (b & 1) ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}
pi fastMatrix(LL n, LL mod) {
	LL t11, t12, t21, t22;
	LL bas[4] = {2, 1, 1, 0};
	LL ans[4] = {1, 0, 0, 1};
	
	while (n) {
		if (n & 1) {
			t11 = ((ans[0] * bas[0]) % mod + (ans[1] * bas[2]) % mod) % mod;
			t12 = ((ans[0] * bas[1]) % mod + (ans[1] * bas[3]) % mod) % mod;
			t21 = ((ans[2] * bas[0]) % mod + (ans[3] * bas[2]) % mod) % mod;
			t22 = ((ans[2] * bas[1]) % mod + (ans[3] * bas[3]) % mod) % mod;

			ans[0] = t11; ans[1] = t12; ans[2] = t21; ans[3] = t22;
		}

		n >>= 1;
		t11 = ((bas[0] * bas[0]) % mod + (bas[1] * bas[2]) % mod) % mod;
		t12 = ((bas[0] * bas[1]) % mod + (bas[1] * bas[3]) % mod) % mod;
		t21 = ((bas[2] * bas[0]) % mod + (bas[3] * bas[2]) % mod) % mod;
		t22 = ((bas[2] * bas[1]) % mod + (bas[3] * bas[3]) % mod) % mod;

		bas[0] = t11; bas[1] = t12; bas[2] = t21; bas[3] = t22;
	}
	return make_pair(ans[0], ans[2]);
}
LL solve(LL n, LL y, LL x, LL s) {
	LL eul = euler(s + 1);
	pi tmp = fastMatrix(n * y, eul * 2);
	LL N = ((tmp.first * tmp.second) % (eul * 2)) / 2 + eul;
	return fastMul(x, N, s + 1);
}
int main() {
	LL n, y, x, s, t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld%lld%lld", &n, &y, &x, &s);
		printf("%lld\n", solve(n, y, x, s));
	}
	return 0;
}