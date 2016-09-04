#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1e18
#define Min(a, b) ((a) <= (b) ? (a) : (b))

typedef long long LL;
typedef struct node{
	LL x, y;
	LL index;
}Coord;

const int maxn = 1e5 + 5;

LL p1, p2, ans;
Coord p[maxn], ppp[maxn], tmp[maxn];

inline LL f(LL x){
	return (x >= 0 ? x : -x);
}
inline bool cmp(Coord a, Coord b){
	return a.x < b.x;
}
inline bool cmp2(Coord a, Coord b){
	return a.y < b.y;
}
inline LL Dist(Coord a, Coord b){
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
LL Cal_Closest(LL left, LL right, int step){
    LL d = INF;
    if(left == right){
    	return d;
	}
    if(left + 1 == right){
    	LL tmp2 = Dist(p[left], p[right]);
    	if(step == 0){
    		if(step == 0 && tmp2 < ans){
    			p1 = left;
    			p2 = right;
    			ans = tmp2;
			}
		}
        return tmp2;
    }
    
    LL mid = (left + right) >> 1;
    LL d1 = Cal_Closest(left, mid, step);
    LL d2 = Cal_Closest(mid + 1, right, step);
    d = Min(d1, d2);
    
    LL k = 0;
    for(LL i = left; i <= right; ++i){
        if(f(p[mid].x - p[i].x) <= d){
            tmp[k++] = p[i];
        }
    }
    sort(tmp, tmp + k, cmp2);
    
    for(LL i = 0; i < k; ++i){
        for(LL j = i + 1; j < k && tmp[j].y - tmp[i].y < d; ++j){
            if(d > Dist(tmp[i], tmp[j])){
            	d = Dist(tmp[i], tmp[j]);
            	if(step == 0 && d < ans){
            		p1 = tmp[i].index;
            		p2 = tmp[j].index;
            		ans = d;
				}
            }
        }
    }
    return d;
}

int main()
{
	LL t, n;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		memset(p, 0, sizeof(p));
		memset(ppp, 0, sizeof(ppp));
		for(LL i = 0; i < n; ++i){
			scanf("%lld%lld", &p[i].x, &p[i].y);
		}
		
		sort(p, p + n, cmp);
		for(LL i = 0; i < n; ++i) p[i].index = i;
		for(LL i = 0; i < n; ++i) ppp[i] = p[i];
		p1 = 0; p2 = 0;
		ans = INF;
		
		ans = Cal_Closest(0, n - 1, 0);
		ans = ans * (n - 2);
		
		LL t = 0;
		for(LL i = 0; i < n; ++i){
			if(ppp[i].index == p1) continue;
			p[t++] = ppp[i];
		}
		sort(p, p + t, cmp);
		ans += Cal_Closest(0, t - 1, 1);
		
		t = 0;
		for(LL i = 0; i < n; ++i){
			if(ppp[i].index == p2) continue;
			p[t++] = ppp[i];
		}
		sort(p, p + t, cmp);
		ans += Cal_Closest(0, t - 1, 1);
		printf("%lld\n", ans);
	}
	return 0;
}
