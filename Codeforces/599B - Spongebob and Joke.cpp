#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int f, b, a[maxn];
int main()
{
    int n, m;
    map<int, int> mm;
    mm.clear();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &f);
        if(mm.count(f) == 1){
            mm[f] = -1;
        }else{
            mm[f] = i;
        }
    }
    bool flag1 = 0, flag2 = 0;
    for(int i = 0; i < m; ++i){
        scanf("%d", &b);
        if(mm.count(b) == 0){
            flag1 = true;
        }else if(mm[b] == -1){
            flag2 = true;
        }else{
            a[i] = mm[b];
        }
    }
    if(flag1){
        printf("Impossible\n");
    }else if(flag2){
        printf("Ambiguity\n");
    }else{
        printf("Possible\n");
        for(int i = 0; i < m; ++i){
            if(i) printf(" ");
            printf("%d", a[i] + 1);
        }
        puts("");
    }
    return 0;
}