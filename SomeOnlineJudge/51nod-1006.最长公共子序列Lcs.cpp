#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 5;
int dp[maxn][maxn];
char a[maxn], b[maxn], ans[maxn];
int main(){
    fgets(a, maxn, stdin);
    fgets(b, maxn, stdin);
    int len1 = strlen(a) - 1;
    int len2 = strlen(b) - 1;
    for(int i = 0; i < len1; ++i){
        for(int j = 0; j < len2; ++j){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int k = 0;
    for(int i = len1, j = len2; i > 0 && j > 0; ){
        if(a[i-1] == b[j-1]){
            ans[k++] = a[i-1];
            --i; --j;
        }else if(dp[i][j] == dp[i][j-1]){
            --j;
        }else{
            --i;
        }
    }
    reverse(ans, ans+k);
    puts(ans);
    return 0;
}