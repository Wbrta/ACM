#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string str;
int ans, status, num[26];
void dfs(int n, int flag, int cnt, int st) {
	if (n == 0) {
		if (cnt < ans) return;
		if (!flag) {ans = cnt; status = st;}
		return;
	}

	dfs(n-1, flag ^ num[n], cnt + 1, st | (1 << (n-1)));
	dfs(n-1, flag, cnt, st);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, len, pos;
	while (cin >> n) {
		vector<int> vec; vec.clear();
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; ++i) {
			cin >> str;
			len = str.length();
			for (int j = 0; j < len; ++j) {
				num[i] ^= (1 << (str[j] - 'A'));
			}
		}
		ans = 0, status = 0, pos = 1;
		dfs(n, 0, 0, 0);
		cout << ans << endl;
		while (status) {
			if (status & 1) vec.push_back(pos);
			++pos; status >>= 1;
		}
		pos = vec.size();
		for (int i = 0; i < pos; ++i) {
			if (i) cout << " ";
			cout << vec[i];
		}
		cout << endl;
	}
	return 0;
}