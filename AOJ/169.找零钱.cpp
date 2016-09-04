#include <cstdio>
using namespace std;
int ans[300];
int main()
{
    for(int i = 0; i < 300; ++i) ans[i] = 0;
    
    for(int i = 0; i <= 100; ++i){
        
        for(int j = 0; j <= 100; ++j){
            if(i + 2 * j > 250) break;
            if(i + j > 100) break;
            
            for(int k = 0; k <= 50; ++k){
                if(i + j + k > 100) break;
                if(i + j * 2 + 5 * k > 250) break;
                
                for(int a = 0; a <= 25; ++a){
                    if(i + j + k + a > 100) break;
                    if(i + j * 2 + 5 * k + 10 * a > 250) break;
                    
                    for(int b = 0; b <= 12; ++b){
                        if(i + j + k + a + b > 100) break;
                        if(i + j * 2 + 5 * k + 10 * a + 20 * b > 250) break;
                        
                        for(int c = 0; c <= 5; ++c){
                            if(i + j + k + a + b + c > 100) break;
                            if(i + j * 2 + 5 * k + 10 * a + 20 * b + 50 * c > 250) break;
                            
                            for(int d = 0; d <= 2; ++d){
                                if(i + j + k + a + b + c + d > 100) break;;
                                int sum = i + 2 * j + 5 * k + 10 * a + 20 * b + 50 * c + 100 *d;
                                if(sum > 250) break;
                                ++ans[sum];
                            }
                        }
                    }
                }
            }
        }
    }

// for(int i = 1; i <= 250; ++i){
//     if(i != 1) printf(" ");
//     printf();
// }
    int n;
    while(~scanf("%d", &n) && n) printf("%d\n", ans[n]);
    return 0;
}