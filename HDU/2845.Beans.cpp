#include <cstdio>
using namespace std;
const int maxn = 200000 + 5;
int dpx[maxn], dpy[maxn];
inline int Max(int x, int y){
	return (x > y ? x : y);
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	int m, n, val;
	while(~scanf("%d%d", &m, &n)){
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d", &val);
				if(j == 0) dpx[j] = val;
				else if(j == 1) dpx[j] = Max(dpx[j-1], val);
				else dpx[j] = Max(dpx[j-1], dpx[j-2] + val);
			}

			if(i == 0) dpy[i] = dpx[n-1];
			else if(i == 1) dpy[i] = Max(dpy[i-1], dpx[n-1]);
			else dpy[i] = Max(dpy[i-1], dpy[i-2] + dpx[n-1]);
		}
		printf("%d\n", dpy[m-1]);
	}
	return 0;
}