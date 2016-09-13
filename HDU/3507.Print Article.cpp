#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500005;

int head, tail, a, n, m;
int q[maxn], sum[maxn], dp[maxn];

inline int getDp(int i, int j) {
    return dp[j] + m + (sum[i] - sum[j]) * (sum[i] - sum[j]);
}
inline int getUp(int i, int j) {
    return (dp[i] + sum[i] * sum[i] - dp[j] - sum[j] * sum[j]);
}
inline int getDown(int i, int j) {
    return 2 * (sum[i] - sum[j]);
}
int main() {
    while (~scanf("%d%d", &n, &m)) {
        dp[0] = sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            sum[i] = sum[i - 1] + a;
        }
        head = tail = 0;
        q[tail++] = 0;
        for (int i = 1; i <= n; ++i) {
            while (head + 1 < tail && getUp(q[head + 1], q[head]) <= sum[i] * getDown(q[head + 1], q[head])) ++head;
            dp[i] = getDp(i, q[head]);
            while (head + 1 < tail && getUp(i, q[tail - 1]) * getDown(q[tail - 1], q[tail - 2]) <= getUp(q[tail - 1], q[tail - 2]) * getDown(i, q[tail - 1])) --tail;
            q[tail++] = i;
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}