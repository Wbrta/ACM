#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Min(a, b) ((a) < (b) ? (a) : (b))

int dp[401][201];
int t, len, len1, len2;
char str[401], str1[201], str2[201];

int main(){
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas){
        scanf(" %s %s %s", str1 + 1, str2 + 1, str + 1);

        len = strlen(str + 1);
        len1 = strlen(str1 + 1);
        len2 = strlen(str2 + 1);

        if(len != len1 + len2){
            printf("Data set %d: no\n", cas);
        }else{
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            for(int i = 1; i <= len; ++i){
                for(int j = 0; j <= Min(i, len1); ++j){
                    if(j != 0 && str[i] == str1[j]){
                        dp[i][j] |= dp[i-1][j-1];
                    }
                    if((i - j != 0) && str[i] == str2[i - j]){
                        dp[i][j] |= dp[i-1][j];
                    }
                }
            }

            printf("Data set %d: %s\n", cas, dp[len][len1] ? "yes" : "no");
        }
    }
    return 0;
}
