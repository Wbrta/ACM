#include <cstdio>
using namespace std;
inline int gcd(int a, int b){
    while(b){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
    int step, mod;
    while(~scanf("%d%d", &step, &mod)){
        printf("%10d%10d", step, mod);
        if(gcd(step, mod) == 1){
            printf("    Good Choice\n\n");
        }else{
            printf("    Bad Choice\n\n");
        }
    }
    return 0;
}