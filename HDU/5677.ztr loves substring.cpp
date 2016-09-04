#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 2;
char str[maxn];
int num[maxn * maxn];
int T, N, K, L;

bool isPalindrome(int l, int r){
    for(int i = l, j = r; i <= j; ++i, --j){
        if(str[i] != str[j]) return false;
    }
    return true;
}
bool solve(){
    int i = 0, len = v.size();
    
}
int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &N, &K, &L);
        memset(num, 0, sizeof(num));
        for(int i = 0; i < N; ++i){
            scanf(" %s", str);
            int len = strlen(str);
            for(int j = 0; j < len; ++j){
                for(int k = j; k < len; ++k){
                    if(isPalindrome(j, k)){
                        ++num[(k - j + 1)];
                    }
                }
            }
        }

        if(solve()){
            printf("True\n");
        }else{
            printf("False\n");
        }
    }
    return 0;
}