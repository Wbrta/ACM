#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string str;
vector<int> vec;
map<int, int> mp;
map<int, int>::iterator it;

int num[26];

inline int bitCount(int st) {
	int cnt = 0;
	while (st) {
		if (st & 1) ++cnt;
		st >>= 1;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, len, pos;
	while (cin >> n) {
		vec.clear(); mp.clear();
		int ans, res, status, half;
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; ++i) {
			cin >> str;
			len = str.length();
			for (int j = 0; j < len; ++j) {
				num[i] ^= (1 << (str[j] - 'A'));
			}
		}

		half = (1 << (n >> 1));
		for (int i = 0; i < half; ++i) {
			int flag = 0;
			for (int j = 0; j < (n >> 1); ++j) {
				if (i & (1 << j)) flag ^= num[j];
			}

			it = mp.find(flag);
			if (it == mp.end()) {
				mp[flag] = i;
			} else {
				if (bitCount(it -> second) < bitCount(i)) {
					it -> second = i;
				}
			}
		}

		ans = 0; res = 0;
		status = (1 << (n - (n >> 1)));
		for (int i = 0; i < status; ++i) {
			int flag = 0;
			for (int j = n >> 1; j < n; ++j) {
				if (i & (1 << (j - (n >> 1)))) {
					flag ^= num[j];
				}
			}

			it = mp.find(flag);
			if (it != mp.end()) {
				half = i << (n >> 1);
				int cnt = bitCount(half + it -> second);
				if (ans < cnt) {
					ans = cnt;
					res = half + it -> second;
				}
			}
		}
		cout << ans << endl;
		ans = 1;
		while (res) {
			if (res & 1) vec.push_back(ans);
			++ans;
			res >>= 1;
		}
		ans = vec.size();
		for (int i = 0; i < ans; ++i) {
			if (i) cout << " ";
			cout << vec[i];
		}
		cout << endl;
	}
	return 0;
}