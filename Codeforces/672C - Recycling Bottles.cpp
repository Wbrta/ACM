#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;

typedef long long LL;
typedef struct node{
	int id;
	double da, db, dt;
}P;
bool vis[maxn];
LL x[maxn], y[maxn];
P p[maxn], q[maxn];

bool cmp1(P a, P b){
	return ((a.dt - a.da) > (b.dt - b.da));
}
bool cmp2(P a, P b){
	return ((a.dt - a.db) > (b.dt - b.db));
}
inline double Min(double a, double b){
	return (a < b ? a : b);
}
inline double dist(LL a, LL b, LL x, LL y){
	return sqrt((a - x) * (a - x) + (b - y) * ( b - y));
}
int main()
{
	LL n, ax, ay, bx, by, tx, ty;
	scanf("%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%lld", &n);

	double ans = 0;
	for(int i = 0; i < n; ++i){
		scanf("%lld %lld", &x[i], &y[i]);
		p[i].id = i;
		p[i].da = dist(x[i], y[i], ax, ay);
		p[i].db = dist(x[i], y[i], bx, by);
		p[i].dt = dist(x[i], y[i], tx, ty);
		q[i] = p[i];

		ans = 2 * p[i].dt;
	}

	if(n == 1){
		ans = Min(p[0].da + dist(bx, by, tx, ty), p[0].db + dist(ax, ay, tx, ty));
	}else{
		sort(p, p + n, cmp1);
		sort(q, q + n, cmp2);


	}
	printf("%d\n", ans);
	return 0;
}