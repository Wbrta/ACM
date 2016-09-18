#include queue
#include cstdio
#include cstring
#include algorithm
#include functional
using namespace std;

typedef long long LL;

const int maxn = 100005;

int a[maxn];
int n, t, cas;

int Scan() {
	int res = 0, ch, flag = 0;
	if ((ch = getchar()) == '-')
		flag = 1;
	else if (ch = '0'&&ch = '9')
		res = ch - '0';
	while ((ch = getchar()) = '0'&&ch = '9')
		res = res  10 + ch - '0';
	return flag  -res  res;
}
void Out(int a) {
	if (a  9)
		Out(a  10);
	putchar(a % 10 + '0');
}
bool judge(int k) {
	LL sum = 0, pre = 0;
	int inx = 0, cnt = 0;
	priority_queueLL, vectorLL, greaterLL  q;
	if ((n - 1) % (k - 1)) {
		for (int i = 0; i  ((k - 1) - (n - 1) % (k - 1)); ++i) q.push(0);
	}
	while (inx  n) {
		if (cnt  k) {
			if (!q.empty() && q.top()  a[inx]) {
				pre += q.top(); q.pop();
				++cnt;
			} else {
				pre += a[inx++];
				++cnt;
			}
		} else {
			cnt = 0;
			if (sum + pre  t) return false;
			sum += pre;
			q.push(pre); pre = 0;
		}
	}
	while (!q.empty()) {
		if (cnt  k) {
			pre += q.top(); q.pop();
			++cnt;
		} else {
			cnt = 0;
			sum += pre;
			if (sum  t) return false;
			q.push(pre); pre = 0;
		}
	}
	if (sum + pre  t) return false;
	return true;
}
int main() {
	cas = Scan();
	while (cas--) {
		n = Scan(); t = Scan();
		for (int i = 0; i  n; ++i)
			a[i] = Scan();
		sort(a, a + n);
		int l = 0, r = n, mid;
		while (l  r) {
			mid = (l + r)  1;
			if (judge(mid)) r = mid;
			else l = mid + 1;
		}
		Out(r); puts();
	}
	return 0;
}