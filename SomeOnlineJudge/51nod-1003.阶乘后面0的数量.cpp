#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int main(){
    LL n, ans;
    while(cin >> n){
        ans = 0;
	while(n){
            ans += n / 5;
            n /= 5;
	}
        cout << ans << endl;
    }
    return 0;
}
