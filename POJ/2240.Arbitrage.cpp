#include <map>
#include <iostream>
using namespace std;
const int maxn = 32;
double g[maxn][maxn];
void floyd(){
    
}
int main(){
    int n, m;
    while(cin >> n && n){
        string str1, str2;
        map<string, int> mp; mp.clear();
        for(int i = 0; i < n; ++i){
            cin >> str1;
            mp[str1] = i;
            str1.clear();
        }
        cin >> m;
        double f;
        for(int i = 0; i < m; ++i){
            cin >> str1 >> f >> str2;
            g[mp[str1]][mp[str2]] = f;
            str1.clear(); str2.clear();
        }

    }
    return 0;
}