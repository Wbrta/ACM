#include <cstdio>
#include <cstring>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
const int maxn = 100000 + 10;
int num[maxn << 2], pre[maxn];

void insert(int rt, int val, int i){
    if(num[rt] == 0) {
        num[rt] = val;
        pre[i] = num[rt >> 1];
        return;
    }
    
    if(num[rt] < val){
        insert(rson, val, i);
    }else{
        insert(lson, val, i);
    }
}
int main()
{
    int n, tmp;
    scanf("%d", &n);
    memset(num, 0, sizeof(num));
    for(int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        insert(1, tmp, i);
    }
    for(int i = 1; i < n; ++i){
        if(i != 1) printf(" "); 
        printf("%d", pre[i]);
    }
    printf("\n");
    return 0;
}