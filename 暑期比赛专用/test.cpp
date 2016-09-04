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
#define INF 0x3f3f3f3f
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Clear(a) memset(a, 0, sizeof(a))
#define Max(a, b) ( (a) > (b) ? (a) : (b) )
#define Min(a, b) ( (a) < (b) ? (a) : (b) )

const int maxn = 1e7 + 5;
const int dir[8][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};

char str[maxn]; 
bool cmp(char a, char b){
    return a > b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        str[0] = '0';
        scanf(" %s", str + 1);
        int len = strlen(str + 1);
        if(len == 1){
            puts("Uncertain");
        }else{
            int cur = 0;
            sort(str + 1, str + len + 1, cmp);
            while(str[len-cur] == '0') ++cur;
            
            if(len - cur <= 1){
                puts("Uncertain");
            }else{
                for(int i = cur; i >= 1; --i){
                    swap(str[len-i], str[len-i+1]);
                }
                str[len-1] += str[len] - '0';
                str[len] = 0;
                for(int i = len - 1; i >= 0; --i){
                    if(str[i] - '0' >= 10){
                        str[i] -= 10;
                        str[i-1] += 1;
                    }
                }
                if(str[0] == '0') puts(str + 1);
                else puts(str);
            }
        }
    }
    return 0;
}
