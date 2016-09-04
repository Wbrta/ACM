#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000 + 5;
int l[maxn], r[maxn], d[maxn], num[maxn][maxn];
inline int Max ( int a, int b ) {
	return ( a > b ? a : b );
}
int main()
{
	int t, n, m;
	scanf( "%d", &t );
	while( t-- ) {
		char c;
		scanf( "%d%d", &n, &m );
		for ( int i = 0; i < n; ++i ) {
			for ( int j = 0; j < m; ++j ) {
				scanf( " %c", &c );
				if ( c == 'F' ) {
					num[i][j] = 1;
				} else if( c == 'R' ) {
					num[i][j] = 0;
				}
			}
		}
		
		int ans = 0;
		for ( int i = 0; i < n; ++i ) {
			memset ( d, 0, sizeof(d) );
			for ( int k = 0; k < m; ++k ) {
				for ( int j = i; j < n; ++j ) {
					if ( num[j][k] == 0 ) break;
					d[k] += num[j][k];
				}
			}
			l[0] = 0;
			r[m - 1] = m - 1;

			for ( int j = 1; j < m; ++j ) {
				int pos = j;
				while ( pos > 0 && d[pos - 1] >= d[j] ) pos = l[pos - 1];
				l[j] = pos;
			}
			for ( int j = m - 2; j >= 0; --j ) {
				int pos = j;
				while ( pos < m - 1 && d[pos + 1] >= d[j] ) pos = r[pos + 1];
				r[j] = pos;
			}
			
			int res = 0;
			for( int j = 0; j < m; ++j ) {
				res = Max ( res, d[j] * ( r[j] - l[j] + 1 ) );
			}
			ans = Max(ans, res);
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}
