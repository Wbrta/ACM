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

int main() {
	LL l1, l2, r1, r2, k, ans = 0;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	if (l2 > r1 || l1 > r2) ans = 0;
	else if (l1 <= l2 && r1 >= r2) {
		ans = r2 - l2 + 1;
		if (l2 <= k && k <= r2) ans -= 1;
	} else if (l2 <= l1 && r2 >= r1) {
		ans = r1 - l1 + 1;
		if (l1 <= k && k <= r1) ans -= 1;
	} else if (r1 >= l2 && l2 >= l1) {
		ans = r1 - l2 + 1;
		if (k >= l2 && k <= r1) ans -= 1;
	} else if (r2 >= l1 && l1 >= l2) {
		ans = r2 - l1 + 1;
		if (k >= l1 && k <= r2) ans -= 1;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}