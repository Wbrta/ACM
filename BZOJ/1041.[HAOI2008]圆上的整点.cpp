#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
LL gcd(LL a, LL b) {
	while (b) {
		LL tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main() {
	LL n, k, v, ans = 0;
	scanf("%lld", &n);
	for (LL i = 1; i * i <= 2 * n; ++i) {
		if (2 * n % i) continue;
		k = 2 * n / i;
		for (LL u = 1; u * u <= k; ++u) {
			v = sqrt((double)k - u * u);
			if (u >= v) continue;
			if (v * v == k - u * u && gcd(u, v) == 1) ++ans;
		}

		if (i * i == 2 * n) continue;
		k = i;
		for (LL u = 1; u * u <= k; ++u) {
			v = sqrt((double)k - u * u);
			if (u >= v) continue;
			if (v * v == k - u * u && gcd(u, v) == 1) ++ans;
		}
	}
	printf("%lld\n", ans * 4 + 4);
	//system("pause");
	return 0;
}