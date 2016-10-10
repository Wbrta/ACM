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

const int maxn = 1e5 + 5;
LL n, a[maxn];

inline LL fun(LL x) {
	return x >= 0 ? x : -x;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	set<LL> s; s.clear();
	cin >> n; LL mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < n; ++i)
		if (fun(mx - a[i])) s.insert(fun(mx - a[i]));
	if(s.size() == 1 || s.size() == 0) cout << "YES" << endl;
	else if (s.size() == 2) {
		set<LL>::iterator it = s.begin();
		LL a = *it; ++it; LL b = *it;
		if(b == 2 * a || a == 2 * b) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else cout << "NO" << endl;
	//system("pause");
	return 0;
}