#include <iostream>
using namespace std;

void swap(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}
int Partition(int a[], int p, int r){
	int i = p;
	int j = r + 1;
	int x = a[p];

	while(true){
		while(i < r && a[++i] < x);
		while(a[--j] > x);
		if(i >= j) break;
		swap(a, i, j);
	}
	
	for(int i = p; i < j; ++i){
		swap(a, i, i + 1);
	}
	return j;
}
void QuickSort(int a[], int p, int r){
	if(p < r){
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
int main()
{
	int a[] = {1,4,5,2,3};
	QuickSort(a, 0, 4);
	for(int i = 0; i < 5; ++i){
		cout << a[i] << endl;
	}
	return 0;
}