#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, before, after;
	bool flag = false;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string str;
		str.clear();
		cin >> str;
		cin >> before >> after;
		if(before >= 2400 && after > before){
			flag = true;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}
