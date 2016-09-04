#include <map>
#include <cstdio>
using namespace std;
map<int, int> m;
int main()
{
    int odd, val;
    while(~scanf("%d", &odd)){
        m.clear();
        for(int i = 0; i < odd; ++i){
            scanf("%d", &val);
            if(m.find(val) != m.end()) {
                m[val] = m[val] + 1;
            }else{
                m.insert(map<int, int>::value_type(val, 1));
            }
        }
        map<int, int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it){
            if((*it).second >= (odd + 1) >> 1){
                printf("%d\n", (*it).first);
                break;
            }
        }
    }
    return 0;
}