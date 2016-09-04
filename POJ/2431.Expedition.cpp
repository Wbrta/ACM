#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 10000 + 10;
typedef struct{
	int a, b;
}stop;
stop s[maxn];
bool cmp(const stop x, const stop y){
	return ((x.a == y.a) ? (x.b > y.b) : (x.a < y.a));
}
int main()
{
	int n, l, p;
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; ++i){
			scanf("%d%d", &s[i].a, &s[i].b);
		}
		scanf("%d%d", &l, &p);
		for(int i = 0; i < n; ++i){
			s[i].a = l - s[i].a;
		}
		s[n].a = l; s[n++].b = 0;
		sort(s, s + n, cmp);
		
		priority_queue<int> q;
		while(!q.empty()) q.pop();
		
		bool flag = true;
		int ans = 0, pos = 0, tank = p;
		for(int i = 0; i < n && flag; ++i){
			int d = s[i].a - pos;

			while(tank - d < 0){
				if(q.empty()){
					flag = false;
					break;
				}
				
				tank += q.top();
				q.pop();
				ans++;
			}
			
			tank -= d;
			pos = s[i].a;
			q.push(s[i].b);
		}
		
		if(flag)
			printf("%d\n", ans);
		else
			puts("-1");
	}
	return 0;
}
