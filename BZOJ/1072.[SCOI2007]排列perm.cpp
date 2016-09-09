#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int val, ans = 0;
		long long kk;
		char num[15] = {0};
		scanf(" %s%d", num, &val);
		int len = strlen(num);
		sort(num, num + len);
		do {
			kk = 0;
			for (int i = 0; i < len; ++i) {
				kk = kk * 10 + (num[i] - '0');
			}
			if (kk % val == 0) ++ans;
		} while (next_permutation(num, num + len));
		printf("%d\n", ans);
	}
	return 0;
}