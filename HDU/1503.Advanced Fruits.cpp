#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;

int len1, len2;
int dp[maxn][maxn];
char tmp[maxn], str1[maxn], str2[maxn], ans[maxn << 1];

int main(){
    while(~scanf(" %s %s", str1, str2)){
        len1 = strlen(str1);
        len2 = strlen(str2);

        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        int k = 0;
        memset(tmp, 0, sizeof(tmp));
        for(int i = len1, j = len2; i > 0 && j > 0; ){
            if(str1[i-1] == str2[j-1]){
                tmp[k++] = str1[i-1];
                --i; --j;
            }else{
                if(dp[i][j] == dp[i-1][j]){
                    --i;
                }else if(dp[i][j] == dp[i][j-1]){
                    --j;
                }
            }
        }
        reverse(tmp, tmp + k);

        int l1 = 0, l2 = 0, t = 0;
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < k; ++i){
            int tt = 0;
            for(int j = l1; str1[j] != tmp[i]; ++j){
                ans[t++] = str1[j];
                tt = 1;
                l1 = j;
            }
            l1 = (tt? (l1 + 2) : (l1 + 1));
            tt = 0;
            for(int j = l2; str2[j] != tmp[i]; ++j){
                ans[t++] = str2[j];
                tt = 1;
                l2 = j;
            }
            l2 = (tt? (l2 + 2) : (l2 + 1));
            ans[t++] = tmp[i];
        }
        for(int i = l1; i < len1; ++i){
            ans[t++] = str1[i];
        }
        for(int i = l2; i < len2; ++i){
            ans[t++] = str2[i];
        }
        puts(ans);
    }
    return 0;
}
