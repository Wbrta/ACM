#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
char mm[maxn][maxn];
int a[maxn], b[maxn];
int main()
{
    char ch;
    int n, m, t = 0;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf(" %c", &mm[i][j]);
            if(mm[i][j] == '*'){
                ++t;
                ++a[i];
                ++b[j];
            }
        }
    }
    if(t > n + m - 1){
        printf("NO\n");
        return 0;
    }

    int flag = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int num = a[i] + b[j];
            if(mm[i][j] == '*') --num;
            if(num == t) {
                printf("YES\n");
                printf("%d %d\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
