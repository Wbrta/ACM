#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110000 + 10;
int ans, p[maxn << 1];
char str[maxn], t[maxn << 1];

void pre(){
    int cnt = 0;
    int len = strlen(str);
    t[cnt++] = '$'; t[cnt++] = '#';
    for(int i = 0; i < len; ++i){
        t[cnt++] = str[i];
        t[cnt++] = '#';
    }
    t[cnt] = '\0';
}
void manacher(){
    memset(p, 0, sizeof(p));
    ans = 0;
    int MaxId = 0, id = 0;
    for(int i = 1; t[i] != 0; ++i){
        if(MaxId > i) p[i] = min(p[2 * id - i], MaxId - i);
        else p[i] = 1;

        while(t[i+p[i]] == t[i-p[i]]) ++p[i];
        if(p[i] + i > MaxId){
            MaxId = p[i] + i;
            id = i;
        }
        ans = max(p[i], ans);
    }
}
int main(){
    while(~scanf(" %s", str)){
        pre();
        manacher();
        printf("%d\n", ans - 1);
    }
    return 0;
}
