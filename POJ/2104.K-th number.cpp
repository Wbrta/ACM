#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int B = 1000;
const int maxn = 100005;

int a[maxn], num[maxn];
vector<int> vec[maxn / B];
int main() {
	int n, m;
	int l, r, k;
	while (~scanf("%d%d", &n, &m)) {
		//for (int i = 0; i < (maxn / B); ++i) vec[i].clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			num[i] = a[i];
			vec[i / B].push_back(a[i]);
		}
		sort(num, num + n);
		for (int i = 0; i < (n / B); ++i) sort(vec[i].begin(), vec[i].end());
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &l, &r, &k);
			--l; --r;
			int lb = -1, ub = n - 1;
			while (ub - lb > 1) {
				int mid = (lb + ub) >> 1;
				int x = num[mid], c = 0;
				int tl = l, tr = r + 1;

				while (tl < tr && tl % B != 0) if (a[tl++] <= x) ++c;
				while (tl < tr && tr % B != 0) if (a[--tr] <= x) ++c;

				while (tl < tr) {
					int b = tl / B;
					c += upper_bound(vec[b].begin(), vec[b].end(), x) - vec[b].begin();
					tl += B;
				}

				if (c >= k) ub = mid;
				else lb = mid;
			}
			printf("%d\n", num[ub]);
		}
	}
	return 0;
}