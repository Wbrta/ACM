#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 30000 + 5;
int dp[maxn], num[maxn];
inline int Max(int x, int y){
    return (x > y ? x : y);
}
int main()
{
//    freopen("test.in", "r+", stdin);
//    freopen("test.out", "w+", stdout);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int ans = 0;
		for(int i = 0; i < n; ++i){
            cin >> num[i];

            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(num[j] < num[i]){
                    dp[i] = Max(dp[i], dp[j] + 1);
                }
            }
            ans = Max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
