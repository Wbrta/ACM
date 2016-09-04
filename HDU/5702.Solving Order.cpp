#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 15;
typedef struct node{
    string color;
    int num;
    node(){};
    node(string c, int a){
        color = c; num = a;
    }
    bool operator < (node x){
        return num > x.num;
    }
}Problem;
Problem p[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> p[i].color >> p[i].num;
        }
        sort(p, p + n);
        for(int i = 0; i < n; ++i){
            if(i) cout << " ";
            cout << p[i].color;
        }
        cout << endl;
    }
    return 0;
}
