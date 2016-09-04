#include <set>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        set<int> s;
        s.clear();
        vector<char> v;
        v.clear();


        scanf("%d", &n);
        if(n < 0){
            n = -n;
            v.push_back('-');
        }
        v.push_back('0'); v.push_back('.');
        int div = 10; s.insert(div);
        bool flag = true;
        while(flag){
            if(div % n == 0){
                v.push_back('0' + div / n);
                flag = false;
            }else{
                if(div < n){
                    div *= 10;
                    v.push_back('0');
                    if(s.find(div) == s.end()){
                        s.insert(div);
                    }else{
                        flag = false;
                    }
                }else{
                    int tmp = div / n;
                    div = div % n * 10;
                    v.push_back('0' + tmp);
                    if(s.find(div) == s.end()){
                        s.insert(div);
                    }else{
                        flag = false;
                    }
                }
            }
        }
        int len = v.size();
        for(int i = 0; i < len; ++i){
            printf("%c", v[i]);
        }
        printf("\n");
    }
    return 0;
}