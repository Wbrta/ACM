#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100 + 5;
int p[maxn], vis[maxn];
int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &p[i]);
        sum += p[i];
    }
    sum /= n >> 1;
    for(int i = 0, k; i < n; ++i){
        if(vis[i]) continue;
        vis[i] = 1;
        for(int j = 0; j < n; ++j){
            if(!vis[j] && p[i] + p[j] == sum){
                k = j;
                break;
            }
        }
        vis[k] = 1;
        printf("%d %d\n", i + 1, k + 1);
    }
    return 0;
}
