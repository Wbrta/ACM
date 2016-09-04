#include <set>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 150000 + 5;
int t[maxn];

struct cmp{
	bool operator()(const int &a,const int &b){
		return a > b;
	}
}; 

int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);

	int n, k, q, type, id;
	scanf("%d%d%d", &n, &k, &q);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &t[i]);
	}
	
	set<int, cmp> s;
	set<int, cmp>::iterator it;
	s.clear();
	for(int i = 0; i < q; ++i){
		scanf("%d%d", &type, &id);
		if(type == 1){
			s.insert(t[id]);
			it = s.end(); --it;
			if(s.size() > k) s.erase(it);
		}else{
			if(s.find(t[id]) != s.end()){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
