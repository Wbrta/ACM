#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5;
int n, p[maxn], pre[maxn];

int findfather(int x){
    return pre[x] = (pre[x] == x ? pre[x] : findfather(pre[x]));
}
int main()
{
    scanf("%d", &n);
    int ans = 0, root = 0;
    for(int i = 1; i <= n; ++i) pre[i] = i;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &p[i]);
        if(p[i] == i){
            root = i;
            ++ans;
        }else{
            int fx = findfather(i);
            int fy = findfather(p[i]);

            if(fx == fy){
                p[i] = i;
                ++ans;
            }else pre[fx] = fy;
        }
    }

    if(root == 0){
        for(int i = 1; i <= n; ++i) if(p[i] == i) root = i;
        ++ans;
    }

    printf("%d\n", ans - 1);
    for(int i = 1; i <= n; ++i){
        if(i != 1) printf(" ");
        if(p[i] == i) p[i] = root;
        printf("%d", p[i]);
    }
    puts("");
    return 0;
}
