#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
map<LL, LL> m;
LL solve(LL u, LL v, LL w){
	vector<LL> vec;
	vec.clear();

	LL t = u, flag = 1;
	while(t){
		vec.push_back(t);
		t /= 2;
	}
	int len = vec.size();
	t = v;
	while(t){
		for(int i = 0; i < len; ++i){
			if(t == vec[i]) {flag = 0; break;}
		}
		if(!flag) break;
		t /= 2; 
	}

	if(w == -1){
		LL ans = 0;
		while(u != t){
			ans += m[u];
			u /= 2;
		}
		while(v != t){
			ans += m[v];
			v /= 2;
		}
		return ans;
	}else{
		while(u != t){
			m[u] += w;
			u /= 2;
		}
		while(v != t){
			m[v] += w;
			v /= 2;
		}
	}
	return 1LL;
}
int main()
{
	// freopen("test.in", "r+", stdin);
	// freopen("test.out", "w+", stdout);
	m.clear();
	LL q, op, u, v, w;
	scanf("%I64d", &q);
	while(q--){
		scanf("%I64d", &op);
		if(op == 1){
			scanf("%I64d%I64d%I64d", &u, &v, &w);

			solve(u, v, w);
		}else{
			scanf("%I64d%I64d", &u, &v);
			LL ans = solve(u, v, -1);
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
