#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 6000;
typedef long long LL;
LL num[maxn];

int p1 = 1, p2 = 1, p3 = 1, p4 = 1;
inline int Min(int a, int b, int c, int d){
	int t1 = (a < b ? a : b);
	int t2 = (c < d ? c : d);
	int t3 = (t1 < t2 ? t1 : t2);

	if(t3 == a) ++p1;
	if(t3 == b) ++p2;
	if(t3 == c) ++p3;
	if(t3 == d) ++p4;

	return t3;
}
void init(){
	/*
	优先队列
	priority_queue<LL, vector<LL>, greater<LL> > q;
	while(!q.empty()) q.pop();

	int cur = 1;
	q.push(1);
	while(!q.empty() && cur <= 5842){
		LL now = q.top();
		if(now <= num[cur-1]) {q.pop(); continue;}
		num[cur++] = now;
		//printf("num[%d] = %d\n", cur - 1, num[cur - 1]);
		//system("pause");
		q.pop();

		q.push(now * 2LL);
		q.push(now * 3LL);
		q.push(now * 5LL);
		q.push(now * 7LL);
	}
	*/
	num[1] = 1;
	for(int i = 2; i <= 5842; ++i){
		num[i] = Min(num[p1] * 2, num[p2] * 3, num[p3] * 5, num[p4] * 7);
	}
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n;
	init();
	while(~scanf("%d", &n) && n){
		if((n % 10 == 1) && n % 100 != 11){
			printf("The %dst humble number is %lld.\n", n, num[n]);
		}else if((n % 10 == 2) && n % 100 != 12){
			printf("The %dnd humble number is %lld.\n", n, num[n]);
		}else if((n % 10 == 3) && n % 100 != 13){
			printf("The %drd humble number is %lld.\n", n, num[n]);
		}else{
			printf("The %dth humble number is %lld.\n", n, num[n]);
		}
	}
	return 0;
}
