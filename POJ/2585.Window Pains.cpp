#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int in[10], m[4][4];
vector<int> vec[10];
vector<int> pre[4][4];

void init(){
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) pre[i][j].clear();
    pre[0][0].push_back(1); pre[0][1].push_back(1); pre[1][0].push_back(1); pre[1][1].push_back(1);
    pre[0][1].push_back(2); pre[0][2].push_back(2); pre[1][1].push_back(2); pre[1][2].push_back(2);
    pre[0][2].push_back(3); pre[0][3].push_back(3); pre[1][2].push_back(3); pre[1][3].push_back(3);
    pre[1][0].push_back(4); pre[1][1].push_back(4); pre[2][0].push_back(4); pre[2][1].push_back(4);
    pre[1][1].push_back(5); pre[1][2].push_back(5); pre[2][1].push_back(5); pre[2][2].push_back(5);
    pre[1][2].push_back(6); pre[1][3].push_back(6); pre[2][2].push_back(6); pre[2][3].push_back(6);
    pre[2][0].push_back(7); pre[2][1].push_back(7); pre[3][0].push_back(7); pre[3][1].push_back(7);
    pre[2][1].push_back(8); pre[2][2].push_back(8); pre[3][1].push_back(8); pre[3][2].push_back(8);
    pre[2][2].push_back(9); pre[2][3].push_back(9); pre[3][2].push_back(9); pre[3][3].push_back(9);
}
bool toposort(){
    priority_queue<int> q;
    while(!q.empty()) q.pop();
    
    for(int i = 1; i < 10; ++i) if(!in[i]) q.push(i);
    
    int cnt = 0;
    while(!q.empty()){
        int p = q.top();
        q.pop(); ++cnt;
        
        int v, len = vec[p].size();
        for(int i = 0; i < len; ++i){
            v = vec[p][i];
            --in[v];
            if(!in[v]) q.push(v);
        }
    }
    
    if(cnt == 9) return true;
    else return false;
}
int main()
{
    // freopen("test.in", "r+", stdin);
    // freopen("test.out", "w+", stdout);
    
    char str[15] = {0}; init();
    while(~scanf(" %s", str)){
        if(strcmp(str, "ENDOFINPUT") == 0) break;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                scanf("%d", &m[i][j]);
            }
        }
        scanf(" %s", str);
        for(int i = 0; i < 10; ++i) vec[i].clear();
        
        int len, v;
        memset(in, 0, sizeof(in));
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                len = pre[i][j].size();
                
                for(int k = 0; k < len; ++k){
                    v = pre[i][j][k];
                    if(v == m[i][j]) continue;
                    
                    int flag = 1;
                    for(int tot = 0; tot < vec[v].size() && flag; ++tot){
                        if(vec[v][tot] == m[i][j]) flag = 0;
                    }
                    if(flag) {
                        vec[v].push_back(m[i][j]);
                        ++in[ m[i][j] ];
                    }
                }
            }
        }
        
        if(toposort()){
            printf("THESE WINDOWS ARE CLEAN\n");
        }else{
            printf("THESE WINDOWS ARE BROKEN\n");
        }
    }
    return 0;
}