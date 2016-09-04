#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 1e5 + 5;

int n;
map<int, LL> mm;
int a[maxn], dp[maxn][20];

int Scan() {
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
void Out(int a) {
    if(a < 0) { putchar('-'); a = -a; }
    if(a >= 10) Out(a / 10);
    putchar(a % 10 + '0');
}
int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}
void ST(){
    for(int j = 1; j < 18; ++j){
        for(int i = 1; i <= n; ++i){
            if(i + (1 << j) - 1 <= n){
                dp[i][j] = gcd(dp[i][j-1], dp[i + (1 << (j-1))][j-1]);
            }else break;
		}
	}
}
int Find(int l, int r){
    int k = (int)log2((double)(r - l + 1));
    return gcd(dp[l][k], dp[r-(1<<k)+1][k]);
}
int main()
{
    int t, q;
    t = Scan();
    for(int cas = 1; cas <= t; ++cas){
        n = Scan();
        mm.clear();
        for(int i = 1; i <= n; ++i){
            a[i] = Scan();
            dp[i][0] = a[i];
        }

        ST();
        for(int i = 1; i <= n; ++i){
            int j = i, g = a[i];
            while(j <= n){
                int l = j, r = n;
                while(l < r){
                    int mid = (l + r) >> 1;
                    if(Find(l, r) == g) l = mid + 1;
                    else r = mid - 1;
                }
                mm[g] += l - j + 1;
                j = l + 1;
                g = gcd(g, a[j]);
            }
        }

        q = Scan();
        printf("Case #%d:\n", cas);
        while(q--){
            int l, r;
            l = Scan(); r = Scan();

            int ans = Find(l, r);
            printf("%d %I64d\n",ans, mm[ans]);
        }
    }
	return 0;
}
