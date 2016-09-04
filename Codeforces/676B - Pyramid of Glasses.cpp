#include <cstdio>
using namespace std;
int full[11][11] = {0};
double num[11][11] = {0};
void init(){
    int t = 2;
    num[0][0] = 1;
    full[0][0] = 1;
    while(t <= 1024){
        num[0][0] += 1;
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j <= i; ++j){
                if(num[i][j] >= 1){
                    if(full[i][j] == 0) full[i][j] = t;
                    num[i+1][j] += (num[i][j] - 1)/ 2.0;
                    num[i+1][j+1] += (num[i][j] - 1)/ 2.0;
                    num[i][j] = 1;
                }
            }
        }
        ++t;
    }
}
int main()
{
    init();
    
    int n, t, ans = 0;
    scanf("%d%d", &n, &t);
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            if(t >= full[i][j]){
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}