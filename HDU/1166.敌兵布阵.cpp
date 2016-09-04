#include <cstdio>
#include <cstring>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)

const int maxn = 5e4 + 5;

typedef struct node{
    int l, r;
    int val;
}Tree;

Tree tree[maxn << 2];
void pushUp(int rt){
    tree[rt].val = tree[lson].val + tree[rson].val;
}
void build(int rt, int l, int r){
    tree[rt].l = l; tree[rt].r = r;
    if(l == r){
        scanf("%d", &tree[rt].val);
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushUp(rt);
}
void update(int rt, int pos, int val){
    if(tree[rt].l == pos && tree[rt].r == pos){
        tree[rt].val += val;
        return;
    }

    if(tree[rt].l <= pos && tree[rt].r >= pos){
        int mid = (tree[rt].l + tree[rt].r) >> 1;
        if(pos > mid) update(rson, pos, val);
        else if(pos <= mid) update(lson, pos, val);
        pushUp(rt);
    }
}
int query(int rt, int l, int r){
    if(l == tree[rt].l && tree[rt].r == r){
        return tree[rt].val;
    }
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if(l > mid){
        return query(rson, l, r);
    }else if(r <= mid){
        return query(lson, l, r);
    }else{
        return query(lson, l, mid) + query(rson, mid + 1, r);
    }
}
int main()
{
    int t, n, a, b;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; ++cas){
        scanf("%d", &n);
        build(1, 1, n);

        printf("Case %d:\n", cas);
        while(true){
            char str[6] = {0};
            scanf(" %s", str);
            if(strcmp(str, "Query") == 0){
                scanf("%d%d", &a, &b);
                printf("%d\n", query(1, a, b));
            }else if(strcmp(str, "Add") == 0){
                scanf("%d%d", &a, &b);
                update(1, a, b);
            }else if(strcmp(str, "Sub") == 0){
                scanf("%d%d", &a, &b);
                update(1, a, -b);
            }else if(strcmp(str, "End") == 0) break;
        }
    }
    return 0;
}
