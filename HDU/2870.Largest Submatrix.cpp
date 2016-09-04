#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;

char c[maxn][maxn];
int d[maxn], l[maxn], r[maxn], match[26][26];

void init(){
	memset(match, 0, sizeof(match));
	match['a'-'a']['a'-'a'] = match['b'-'a']['b'-'a'] = match['c'-'a']['c'-'a'] = 1;

	match['a'-'a']['w'-'a'] = match['a'-'a']['y'-'a'] = match['a'-'a']['z'-'a'] = 1;
	match['b'-'a']['w'-'a'] = match['b'-'a']['x'-'a'] = match['b'-'a']['z'-'a'] = 1;
	match['c'-'a']['x'-'a'] = match['c'-'a']['y'-'a'] = match['c'-'a']['z'-'a'] = 1;
	
	match['w'-'a']['a'-'a'] = match['y'-'a']['a'-'a'] = match['z'-'a']['a'-'a'] = 1;
	match['w'-'a']['b'-'a'] = match['x'-'a']['b'-'a'] = match['z'-'a']['b'-'a'] = 1;
	match['x'-'a']['c'-'a'] = match['y'-'a']['c'-'a'] = match['z'-'a']['c'-'a'] = 1;
}
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int m, n; init();
	while(~scanf("%d%d", &m, &n)){
		//memset(c, 0, sizeof(c));
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				scanf(" %c", &c[i][j]);
			}
		}
		int ans = 0;
		for(int cas = 0; cas < 3; ++cas){
			for(int i = 0; i < m; ++i){

				memset(d, 0, sizeof(d));
				for(int k = 0; k < n; ++k){

					for(int j = i; j < m; ++j){
						if(match[c[j][k] - 'a'][cas]){
							d[k] += 1;
						}else break;
					}
				}

				l[0] = 0;
				r[n-1] = n-1;
				for ( int j = 1; j < n; ++j ) {
					int pos = j;
					while ( pos > 0 && d[pos - 1] >= d[j] ) pos = l[pos - 1];
					l[j] = pos;
				}
				for ( int j = n - 2; j >= 0; --j ) {
					int pos = j;
					while ( pos < n - 1 && d[pos + 1] >= d[j] ) pos = r[pos + 1];
					r[j] = pos;
				}
				int res = 0;
				for(int j = 0; j < n; ++j){
					res = Max(res, d[j] * (r[j] - l[j] + 1));
				}
				ans = Max(ans, res);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}