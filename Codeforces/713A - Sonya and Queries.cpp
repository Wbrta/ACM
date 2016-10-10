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

const int maxn = (1 << 18) + 10;

int cas;
int st[maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> cas;
	while (cas--) {
		char op; 
		LL num, tmp, los = 0;
		cin >> op >> num;
		int status = 0;
		while (num) {
			tmp = num % 10;
			num /= 10;
			if (tmp & 1) status |= (1 << los);
			++los;
		}
		if (op == '+') st[status] += 1;
		else if (op == '-') st[status] -= 1;
		else cout << st[status] << endl;
	}
	//system("pause");
	return 0;
}