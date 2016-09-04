#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)

const int maxn = 2e5 + 5;
typedef struct node{
    int l, r;
    int val;
}TREE;
TREE t[maxn << 2];

void pushUp(int rt){
    t[rt].val = max(t[lson].val, t[rson].val);
}
void build(int rt, int l, int r){
    t[rt].l = l; t[rt].r = r;
    if(l == r){
        scanf("%d", &t[rt].val);
        return;
    }

    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushUp(rt);
}
void update(int rt, int pos, int val){
    if(t[rt].l == pos && t[rt].r == pos){
        t[rt].val = val;
        return;
    }

    if(t[rt].l <= pos && t[rt].r >= pos){
        int mid = (t[rt].l + t[rt].r) >> 1;
        if(pos > mid)
            update(rson, pos, val);
        else if(pos <= mid)
            update(lson, pos, val);
        pushUp(rt);
    }
}
int query(int rt, int l, int r){
    if(t[rt].l == l && t[rt].r == r){
        return t[rt].val;
    }

    int mid = (t[rt].l + t[rt].r) >> 1;
    if(r <= mid){
        return query(lson, l, r);
    }else if(l > mid){
        return query(rson, l, r);
    }else{
        return max(query(lson, l, mid), query(rson, mid + 1, r));
    }
}
int main()
{
    char op;
    int n, m, a, b;
    while(~scanf("%d%d", &n, &m)){
        build(1, 1, n);
        for(int i = 0; i < m; ++i){
            scanf(" %c%d%d", &op, &a, &b);
            if(op == 'Q'){
                printf("%d\n", query(1, a, b));
            }else if(op == 'U'){
                update(1, a, b);
            }
        }
    }
    return 0;
}
