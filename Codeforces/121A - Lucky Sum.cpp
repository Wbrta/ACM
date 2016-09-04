#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 1000000000;
const int maxn = 1030;
LL num[maxn], cur;
void bfs(){
	queue<LL> q;
	while(!q.empty()) q.pop();
	q.push(4);
	q.push(7);
	
	while(!q.empty()){
		LL now = q.front();
		num[cur++] = now;
		q.pop();
		
		if(now * 10 + 4 <= INF) q.push(now * 10 + 4);
		if(now * 10 + 7 <= INF) q.push(now * 10 + 7);
	}
}
int main()
{
	cur = 0;
	bfs();
	num[cur] = 4444444444;
	int l, r;
	while(~scanf("%d%d", &l, &r)){
		LL ans = 0;
		bool flag = false;
		if(num[0] >= r){
			ans = (r - l + 1) * num[0];
		}else if(num[cur - 1] < l){
			ans = (r - l + 1) * num[cur];
		}else{
			LL min_l = -1, max_r = -1;
			for(int i = 0; i < cur; ++i){
				if(min_l == -1 && num[i] >= l){
					min_l = i;
				}
				if(num[i] <= r){
					max_r = i;
				}
			}
			
			if(max_r < min_l){
				ans += (r - l + 1) * num[min_l];	
			}else{
				ans += (num[min_l] - l + 1) * num[min_l];
				for(int i = min_l + 1; i <= max_r; ++i){
					ans += (num[i] - num[i-1]) * num[i];
				}
				ans += (r - num[max_r]) * num[max_r + 1];
			}
		}
		
		
		printf("%I64d\n", ans);
	}
	return 0;
}
