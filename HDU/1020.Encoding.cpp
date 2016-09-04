#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10000 + 10;
char str[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        memset(str, 0, sizeof(str));
        scanf(" %s", str);
        char tmp = str[0];
        int len = strlen(str), cont = 1;   
        for(int i = 1; i < len; ++i){
            if(str[i] == tmp){
                ++cont;
            }else{
                if(cont == 1) printf("%c", tmp);
                else printf("%d%c", cont, tmp);
                cont = 1;
            }
            tmp = str[i];
        }
        if(cont == 1) printf("%c", tmp);
        else printf("%d%c", cont, tmp);
        printf("\n");
    }
    return 0;
}