#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 50005;

LL a, n, l, head, tail;
LL q[maxn], dp[maxn], sum[maxn];

inline LL fun(LL x) {
	return x * x;
}
inline LL getDp(LL i, LL j) {
	return dp[j] + fun(i - j - 1 + sum[i] - sum[j] - l);
}
inline LL getUp(LL i, LL j) {
	return ((dp[i] + fun(sum[i] + i)) - (dp[j] + fun(sum[j] + j)));
}
inline LL getDown(LL i, LL j) {
	return 2 * ((sum[i] + i) - (sum[j] + j));
}
int main() {
	scanf("%lld%lld", &n, &l);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a);
		sum[i] = sum[i - 1] + a;
	}
	head = tail = 0;
	q[tail++] = 0;
	for (int i = 1; i <= n; ++i) {
		while (head + 1 < tail && getUp(q[head + 1], q[head]) <= (sum[i] + i - l - 1) * getDown(q[head + 1], q[head])) ++head;
		dp[i] = getDp(i, q[head]);
		while (head + 1 < tail && getUp(i, q[tail - 1]) * getDown(q[tail - 1], q[tail - 2]) <= getUp(q[tail - 1], q[tail - 2]) * getDown(i, q[tail - 1])) --tail;
		q[tail++] = i;
	}
	printf("%lld\n", dp[n]);
	//system("pause");
	return 0;
}