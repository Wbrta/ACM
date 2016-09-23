#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10;
const int inf = 0x3f3f3f3f;

int n, m;
int a[maxn][maxn];
int dp[10][10][60010];

typedef struct node {
	int ha[9];
	int left;

	int encode() const {
		int key = left;
		for (int i = 0; i < m; ++i)
			key = key * 3 + ha[i];
		return key;
	}

	bool next(int row, int col, int U, int R, int D, int L, node &t) const {
		//for (int i = 0; i < n; ++i) printf("%d%c", ha[i], (i == n - 1 ? '\n' : ' '));

		if (row == n - 1 && D != 0) return false;
		if (col == m - 1 && R != 0) return false;

		bool must_left = (col > 0 && left != 0);
		bool must_up = (row > 0 && ha[col] != 0);

		if ((must_left && L != left) || (!must_left && L != 0)) return false;
		if ((must_up && U != ha[col]) || (!must_up && U != 0)) return false;
		if (must_left && must_up && left != ha[col]) return false;

		for (int i = 0; i < m; ++i) t.ha[i] = ha[i];
		t.ha[col] = D;
		t.left = R;
		return true;
	}
}State;

int dfs(int row, int col, State &s) {
	if (col == m) { col = 0; ++row; }
	if (row == n) return 0;

	int key = s.encode();
	int& ans = dp[row][col][key];
	if (ans >= 0) return ans;

	State t;
	ans = inf;
	if (a[row][col] <= 1) {
		if (s.next(row, col, 0, 0, 0, 0, t)) ans = min(ans, dfs(row, col + 1, t));
		if (a[row][col] == 0) {
			for (int i = 1; i <= 2; ++i) {
				if (s.next(row, col, i, 0, i, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
				if (s.next(row, col, 0, i, 0, i, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
				if (s.next(row, col, i, 0, 0, i, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
				if (s.next(row, col, i, i, 0, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
				if (s.next(row, col, 0, 0, i, i, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
				if (s.next(row, col, 0, i, i, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 2);
			}
		}
	} else {
		int cur = a[row][col] - 1;
		if (s.next(row, col, cur, 0, 0, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 1);
		if (s.next(row, col, 0, cur, 0, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 1);
		if (s.next(row, col, 0, 0, cur, 0, t)) ans = min(ans, dfs(row, col + 1, t) + 1);
		if (s.next(row, col, 0, 0, 0, cur, t)) ans = min(ans, dfs(row, col + 1, t) + 1);
	}
	return ans;
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		if (!n && !m) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				scanf("%d", &a[i][j]);
		}
		State s;
		memset(&s, 0, sizeof(s));
		memset(dp, -1, sizeof(dp));
		int ans = dfs(0, 0, s);
		if (ans == inf) ans = 0;
		printf("%d\n", ans / 2);
	}
	return 0;
}