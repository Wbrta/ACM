#include <cstdio>
using namespace std;
int p[15] = {0};
int a[] = {503, 87, 512, 61, 908, 170, 897, 275, 653, 426};
void MergeSort(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            p[k++] = a[i++];
        }else{
            p[k++] = a[j++];
        }
    }

    while(i <= mid) p[k++] = a[i++];
    while(j <= r) p[k++] = a[j++];

    for(i = l, j = 0; i <= r; ++i, ++j){
        a[i] = p[j];
    }
}
int main()
{
    MergeSort(0, 9);
    for(int i = 0; i < 10; ++i){
        if(i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
