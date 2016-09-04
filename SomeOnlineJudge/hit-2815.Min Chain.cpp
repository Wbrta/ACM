#include <cstdio>
#include <algorithm>
using namespace std;
int gcd ( int a, int b ) {
    return ( b == 0 ? a : gcd ( b, a % b ) ); 
}
void ext_euclid ( int a, int b, int &x, int &y ) {
    if ( b == 0 ) {
        x = 1; y = 0;
        return;
    }
    ext_euclid ( b, a % b, x, y );
    int tmp = x;
    x = y;
    y = tmp - ( a / b ) * y;
}
int main(){
    int t, a, b, x, y;
    scanf ( "%d", &t );
    while ( t-- ) {
        scanf ( "%d%d", &a, &b );
        if ( gcd ( a, b ) == 1 ) {
            if ( a < b ) swap ( a, b );
            if ( b == 1 && a == 2 ) {
                puts ( "1" );
            } else if ( b == 1 ) {
                puts ( "2" );
            } else if ( b == 0 && a == 1 ) {
                puts ( "1" );
            } else {
                ext_euclid ( a, b, x, y );
                int tmp, ans = ( x >= 0 ? x : -x );
                ans += ( y >= 0 ? y : -y );
                
                if ( x < 0 ) {
                    tmp = ( ( x + b ) >= 0 ? ( x + b ) : -( x + b ) );
                    tmp += ( ( y - a ) >= 0 ? ( y - a ) : -( y - a ) );
                    if ( tmp < ans ) ans = tmp;
                } else {
                    tmp = ( ( x - b ) >= 0 ? ( x - b ) : -( x - b ) );
                    tmp += ( ( y + a ) >= 0 ? ( y + a ) : -( y + a ) );
                    if ( tmp < ans ) ans = tmp;
                }
                
                printf ( "%d\n", ans - 1 );
            }
        } else {
            puts ( "-1" );
        }
    }
    return 0;
}