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
#define fun(x) ((x) >= 0 ? (x) : -(x))

typedef long long LL;
typedef pair<int, int> pi;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		if (n <= 153) cout << "153" << endl;
		else if (n <= 370) cout << "370" << endl;
		else if (n <= 371) cout << "371" << endl;
		else if (n <= 407) cout << "407" << endl;
		else cout << "1634" << endl;
	}
	return 0;
}