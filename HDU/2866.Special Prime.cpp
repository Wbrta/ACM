#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define mp make_pair
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)

typedef long long LL;
typedef pair<int, int> pi;

inline int f(LL x) {
	return 3 * x * x + 3 * x + 1;
}
inline bool isPrime(int p) {
	for (int i = 2; i * i <= p; ++i)
		if (p % i == 0) return false;
	return true;
}
int main() {
	int l, ans;
	while (~scanf("%d", &l)) {
		ans = 0;
		for (int x = 1, p; (p = f(x)) <= l; ++x) {
			if (isPrime(p)) ++ans;
		}
		if(ans) printf("%d\n", ans);
		else puts("No Special Prime!");
	}
	return 0;
}