#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 5;
bool cmp(string a, string b){
	return a + b < b + a;
}
string str[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;	
	for(int i = 0; i < n; ++i){
		cin >> str[i];
	}
	sort(str, str + n, cmp);
	for(int i = 0; i < n; ++i){
		cout << str[i];
	}
	cout << endl;
	return 0;
}
