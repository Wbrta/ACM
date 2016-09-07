#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
 
const int maxn = 1505;
 
int sum[maxn][maxn];
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];
 
int main() {
    int m, n, k, val;
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &val);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val;
        }
    }
    for (int i = m; i >= k; --i) {
        for(int j = n; j >= k; --j)
            sum[i][j] -= sum[i - k][j] + sum[i][j - k] - sum[i - k][j - k];
    }
 
    for (int i = k; i <= m; ++i) {
        for (int j = k; j <= n; ++j)
            a[i][j] = max(sum[i][j], max(a[i - 1][j], a[i][j - 1]));
    }
    for (int i = k; i <= m; ++i) {
        for (int j = n; j >= k; --j)
            b[i][j] = max(sum[i][j], max(b[i - 1][j], b[i][j + 1]));
    }
    for (int i = m; i >= k; --i) {
        for (int j = k; j <= n; ++j)
            c[i][j] = max(sum[i][j], max(c[i + 1][j], c[i][j - 1]));
    }
    for (int i = m; i >= k; --i) {
        for (int j = n; j >= k; --j)
            d[i][j] = max(sum[i][j], max(d[i + 1][j], d[i][j + 1]));
    }
     
    int ans = 0;
    for (int i = k; i <= m - k; ++i) {
        for (int j = k; j <= n - k; ++j)
            ans = max(ans, a[i][j] + b[i][j + k] + c[i + k][n]);
    }
    for (int i = k; i <= m - k; ++i) {
        for (int j = (k << 1); j <= n; ++j)
            ans = max(ans, a[m][j - k] + b[i][j] + d[i + k][j]);
    }
    for (int i = k; i <= m - k; ++i) {
        for (int j = k; j <= n - k; ++j)
            ans = max(ans, a[i][j] + b[m][j + k] + c[i + k][j]);
    }
    for (int i = (k << 1); i <= m; ++i) {
        for (int j = k; j <= n - k; ++j)
            ans = max(ans, a[i - k][n] + c[i][j] + d[i][j + k]);
    }
    for (int i = k; i <= m; ++i) {
        for (int j = (k << 1); j <= n - k; ++j)
            ans = max(ans, sum[i][j] + a[m][j - k] + b[m][j + k]);
    }
    for (int i = (k << 1); i <= m - k; ++i) {
        for (int j = k; j <= n; ++j)
            ans = max(ans, sum[i][j] + a[i - k][n] + c[i + k][n]);
    }
    printf("%d\n", ans);
    //system("pause");
    return 0;
}