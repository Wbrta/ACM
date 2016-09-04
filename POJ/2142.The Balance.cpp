#include <cstdio>
using namespace std;
int gcd(int a, int b){
    int tmp;
    while(b){
        tmp = a % b; a = b; b = tmp;
    }
    return a;
}
void ext_euclid(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1; y = 0;
        return;
    }
    ext_euclid(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
int main(){
    int a, b, d;
    while(~scanf("%d%d%d", &a, &b, &d)){
        if(a == 0 && b == 0 && d == 0) break;
        int tmp = gcd(a, b);
        a /= tmp;
        b /= tmp;
        d /= tmp;
        
        int x, y;
        ext_euclid(a, b, x, y);
        
        int tx = x * d;
        tx = ( (tx % b) + b ) % b;
        int ty = ( d - a * tx ) / b;
        if(ty < 0) ty = -ty;
        
        y = y * d;
        y = ( (y % a) + a ) % a;
        x = ( d - b * y ) / a;
        if(x < 0) x = -x;
        
        if(x + y > tx + ty){
            x = tx; y = ty;
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}