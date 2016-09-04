#include <cstdio>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    while(N--){
        int n, m, cas = 1;
        while(~scanf("%d%d", &n, &m)){
            if(n == 0 && m == 0) break;
            int cont = 0;
            for(int i = 1; i < n; ++i){
                for(int j = i + 1; j < n; ++j){
                    int fenzi = i * i + j * j + m;
                    int fenmu = i * j;
                    if(fenzi % fenmu == 0) ++cont;
                }
            }
            printf("Case %d: %d\n", cas++, cont);
        }
        if(N != 0) printf("\n");
    }
    return 0;
}