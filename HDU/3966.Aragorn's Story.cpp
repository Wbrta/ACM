#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define PB push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)

typedef struct node{
    int l, r;
    int val;
    int cnt;
}TREE;

const int maxn = 5e4 + 5;

int tim, a[maxn];
TREE tree[maxn << 2];
vector<int> vec[maxn];
int tid[maxn], rak[maxn], top[maxn];
int num[maxn], dep[maxn], f[maxn], sson[maxn];

int Scan(){
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
void init(){
    tim = 0;
    memset(tree, 0, sizeof(tree));
    memset(sson, -1, sizeof(sson));
}
void dfs1(int p, int father, int d){
    dep[p] = d;
    num[p] = 1;
    f[p] = father;

    int v, len = vec[p].size();
    for(int i = 0; i < len; ++i){
        v = vec[p][i];
        if(v == father) continue;
        dfs1(v, p, d + 1);
        num[p] += num[v];

        if(sson[p] == -1 || num[sson[p]] < num[v]) sson[p] = v;
    }
}
void dfs2(int p, int tp){
    top[p] = tp;
    tid[p] = ++tim;
    rak[tid[p]] = p;

    if(sson[p] == -1) return;
    dfs2(sson[p], tp);

    int v, len = vec[p].size();
    for(int i = 0; i < len; ++i){
        v = vec[p][i];
        if(v != sson[p] && v != f[p]){
            dfs2(v, v);
        }
    }
}
void pushup(int rt){
    tree[rt].val = max(tree[lson].val, tree[rson].val);
}
void pushdown(int rt){
    if(tree[rt].cnt){
        tree[lson].cnt += tree[rt].cnt;
        tree[rson].cnt += tree[rt].cnt;
        tree[lson].val += (tree[lson].r - tree[lson].l + 1) * tree[rt].cnt;
        tree[rson].val += (tree[rson].r - tree[rson].l + 1) * tree[rt].cnt;
        tree[rt].cnt = 0;
    }
}
void build(int rt, int l, int r){
    tree[rt].l = l; tree[rt].r = r; tree[rt].cnt = 0;
    if(l == r){
        tree[rt].val = a[rak[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int val){
    if(l <= tree[rt].l && tree[rt].r <= r){
        tree[rt].cnt += val;
        tree[rt].val += val * (tree[rt].r - tree[rt].l + 1);
        return;
    }
    pushdown(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l <= mid) update(lson, l, r, val);
    if(r > mid) update(rson, l, r, val);
    pushup(rt);
}
void change(int l, int r, int val){
    while (top[l] != top[r]){
        if(dep[top[l]] < dep[top[r]]) swap(l, r);
        update(1, tid[top[l]], tid[l], val);
        l = f[top[l]];
    }
    if(dep[l] > dep[r]) swap(l, r);

    update(1, tid[l], tid[r], val);
}
int Query(int rt, int pos){
    if(tree[rt].l == tree[rt].r) return tree[rt].val;
    pushdown(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int ret = 0;
    if(pos <= mid) ret += Query(lson, pos);
    else ret += Query(rson, pos);
    pushup(rt);
    return ret;
}

int main()
{
    char q;
    int n, m, p, u, v;
    while(~scanf("%d%d%d", &n, &m, &p)){
        init();
        for(int i = 1; i <= n; ++i){
            a[i] = Scan();
            vec[i].clear();
        }
        vec[0].clear();
        for(int i = 0; i < m; ++i){
            u = Scan(); v = Scan();
            vec[u].PB(v);
            vec[v].PB(u);
        }
        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(1, 1, n);

        int a, b, c;
        for(int i = 0; i < p; ++i){
            scanf(" %c", &q);
            if(q == 'Q'){
                scanf("%d", &a);
                printf("%d\n", Query(1, tid[a]));
            }else{
                scanf("%d%d%d", &a, &b, &c);
                if(q == 'D') c = -c;
                change(a, b, c);
            }
        }
    }
    return 0;
}
