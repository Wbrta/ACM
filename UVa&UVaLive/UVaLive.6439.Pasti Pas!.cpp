#include <string>
#include <iostream>
using namespace std;
string str;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t, ans, len;
	cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		str.clear();
		cin >> str;
		ans = 0, len = str.length();
		for (int i = 0, j = len - 1; i <= j; ) {
			if (str[i] == str[j]) {
				ans += (i == j ? 1 : 2);
				++i; --j;
			} else {
				int a, b, k = 0;
				while (true) {
					while (str[i] != str[j - k]) ++k;
					for (a = i, b = j - k; str[a] == str[b] && b <= j; ++a, ++b);
					if (b > j) break;
					else ++k;
				}
				if (i + k >= j - k) ans += 1;
				else ans += 2;
				i = i + k + 1; j = j - k - 1;
			}
		}
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}