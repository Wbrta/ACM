#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int n, val;
int num[maxn];
double ans[maxn];
vector<int> vec[maxn];

void dfs(int p){
	int len = vec[p].size();
	num[p] = len;
	for(int i = 0; i < len; ++i){
		int v = vec[p][i];
		dfs(v);
		num[p] += num[v];
	}
}
void cal(int p){
	int len = vec[p].size();
	for(int i = 0; i < len; ++i){
		int v = vec[p][i];
		ans[v] = ans[p] + 1 + (num[p] - num[v] - 1) / 2.0;
		cal(v);
	}
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i) {
		vec[i].clear();
		num[i] = 0;
	}
	for(int i = 2; i <= n; ++i){
		scanf("%d", &val);
		vec[val].push_back(i);
	}
	dfs(1);
	ans[1] = 1;
	cal(1);
	for(int i = 1; i <= n; ++i){
		if(i != 1) printf(" ");
		printf("%.8f", ans[i]);
	}
	return 0;
}