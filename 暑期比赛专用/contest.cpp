#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define mod 7
#define PB push_back
#define INF 0x3f3f3f3f
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Clear(a) memset(a, 0, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define Max(a, b) ( (a) > (b) ? (a) : (b) )
#define Min(a, b) ( (a) < (b) ? (a) : (b) )

typedef long long LL;
typedef pair<int, int > pi;

const int maxn = 1e5 + 5;
const int MAXN = 4e4 + 5;
const int dir1[4][2] = {1,0, -1,0, 0,1, 0,-1};
const int dir2[8][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};

int prime[MAXN + 1];
void getPrime()
{
    for(int i = 2; i <= MAXN; ++i) prime[i] = i;
    for(int i = 2; i <= MAXN; ++i) {
        if(prime[i])
            for(int j = 2; i * j <= MAXN; ++j) prime[i * j] = 0;
    }
}
int main()
{
    int t, n, d, k;
    scanf("%d", &t);
    getPrime();
    while(t--){
        scanf("%d%d", &n, &d);
        --n;

        int tmp = INF;
        for(int i = 2; i * i <= d; ++i){
            if(d % i == 0) {
                tmp = i;
                break;
            }
        }

        if(tmp == INF) tmp = d;
        k = min(n / d, tmp);

        int ans = 0;
        for(int i = 2; i <= k; ++i){
            if(prime[i]) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
