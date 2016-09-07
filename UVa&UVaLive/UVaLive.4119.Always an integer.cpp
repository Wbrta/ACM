#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100005;

int tot;
char str[maxn];
long long a[110], b[110];

long long mod_exp(long long a, long long b, long long mod) {
	long long res = 1, tmp = a;
	while (b) {
		if (b & 1) res = (res * tmp) % mod;
		tmp = (tmp * tmp) % mod;
		b >>= 1;
	}
	return res;
}
int cal_res(long long mod) {
	for (long long i = 0; i <= 101; ++i) {
		long long sum = 0;
		for (int j = 0; j < tot; ++j)
			sum = (sum + a[j] * mod_exp(i, b[j], mod)) % mod;
		if (sum % mod != 0) return 0;
	}
	return 1;
}
int main() {
	int cas = 1;
	while (~scanf("%s", str)) {
		if (str[0] == '.') break;
		int mod = 0, len = strlen(str);

		tot = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));

		for (int i = 1; str[i] != ')'; ++i) {
			if (i == 1 || str[i] == '+' || str[i] == '-') {
				int be, aa = 0, flag = 1, sign = (str[i] == '-' ? -1 : 1);
				if (i == 1 && str[1] != '-') be = i;
				else be = i + 1;
				for (int j = be; !(str[j] == '+' || str[j] == '-' || str[j] == ')'); ++j) {
					if (str[j] == 'n') flag = 0;
					if (str[j] == '^' || str[j] == 'n') continue;
					if (flag) { aa = 1; a[tot] = a[tot] * 10 + (str[j] - '0'); }
					else b[tot] = b[tot] * 10 + (str[j] - '0');
				}
				if (!aa && a[tot] == 0) a[tot] = 1;
				if (!flag && b[tot] == 0) b[tot] = 1;
				a[tot] *= sign;
				++tot;
			}
		}
		for (int i = 0; i < len; ++i) {
			if (str[i] == '/') {
				for (int j = i + 1; j < len; ++j)
					mod = mod * 10 + (str[j] - '0');
				break;
			}
		}
		
		int res = cal_res(mod);
		if (res) printf("Case %d: Always an integer\n", cas++);
		else printf("Case %d: Not always an integer\n", cas++);
		memset(str, 0, sizeof(str));
	}
	return 0;
}