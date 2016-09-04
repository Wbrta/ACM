#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 30000 + 10;
double mon[32], val[maxn * 100];

inline int INT(double a){
	return (int)(a * 100);
}
inline double Max(double a, double b){
	return (a > b ? a : b);
}
int main()
{
	int m, n;
	char type;
	double q, tm;
	while(~scanf("%lf%d", &q, &n) && n){
		memset(mon, 0, sizeof(mon));
		memset(val, 0, sizeof(val));
		for(int i = 0; i < n; ++i){
			scanf("%d", &m);
			bool flag = true;
			double cl[3] = {0};
			for(int j = 0; j < m; ++j){
				scanf(" %c:%lf", &type, &tm);
				if(!(type == 'A' || type == 'B' || type == 'C')) flag = false;
				switch (type){
					case 'A':
						cl[0] += tm; break;
					case 'B':
						cl[1] += tm; break;
					case 'C':
						cl[2] += tm; break;
				}
			}
			if(cl[0] > 600 || cl[1] > 600 || cl[2] > 600) flag = false;
			mon[i] += cl[0] + cl[1] + cl[2];
			mon[i] = (flag ? mon[i] : 0);
			mon[i] = (mon[i] <= 1000 ? mon[i] : 0);
		}
		
		int C = INT(q);
		for(int i = 0; i < n; ++i){
			for(int j = C; j >= INT(mon[i]); --j){
				val[j] = Max(val[j], val[j - INT(mon[i])] + mon[i]);
			}
		}
		printf("%.2f\n", val[C]);
	}
	return 0;
}
