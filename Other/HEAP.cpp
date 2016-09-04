#include <iostream>
using namespace std;
#define lson (j << 1)
#define rson (j << 1 | 1)
typedef struct{
	int *heap;
	int length;
}HEAP;
HEAP init(HEAP a){
	int n;
	cout << "请输入您想要排序的数字的个数：";
	cin >> n;
	a.heap = new int[n + 1];
	a.length = n;
	for(int i = 1; i <= n; ++i){
		cout << "请输入第 " << i << " 个数字：";
		cin >> a.heap[i];
	}

	for(int i = n >> 1; i >= 1; --i){
		int j = i;
		while(j <= n >> 1){
			if(a.heap[j] >= a.heap[lson] && a.heap[j] < a.heap[rson]){
				a.heap[0] = a.heap[j];
				a.heap[j] = a.heap[rson];
				a.heap[rson] = a.heap[0];
				j = rson;
			}else if(a.heap[j] < a.heap[lson] && a.heap[j] >= a.heap[rson]){
				a.heap[0] = a.heap[j];
				a.heap[j] = a.heap[lson];
				a.heap[lson] = a.heap[0];
				j = lson;
			}else if(a.heap[j] < a.heap[lson] && a.heap[j] < a.heap[rson]){
				a.heap[0] = a.heap[j];
				if(a.heap[lson] >= a.heap[rson]){
					a.heap[j] = a.heap[lson];
					a.heap[lson] = a.heap[0];
					j = lson;
				}else{
					a.heap[j] = a.heap[rson];
					a.heap[rson] = a.heap[0];
					j = rson;
				}
			}else break;
		}
	}
	return a;
}
HEAP Heap_sort(HEAP a){
	int n = a.length;
	for(int i = n; i >= 1; --i){
		a.heap[0] = a.heap[i];
		a.heap[i] = a.heap[1];
		a.heap[1] = a.heap[0];

		int j = 2, k = 1;
		int tmp = a.heap[1];
		while(j < i){
			if(j + 1 < i && a.heap[j] < a.heap[j + 1]) ++j;

			if(a.heap[j] <= tmp) break;
			a.heap[k] = a.heap[j];
			k = j;
			j = lson;
		}
		a.heap[k] = tmp;

		for(int j = 1; j <= a.length; ++j){
            if(j != 1) cout << " ";
            cout << a.heap[j];
		}
		cout << endl;
	}

	cout << "排序后数字为：" << endl;
	for(int i = 1; i <= a.length; ++i){
		cout << a.heap[i] << " ";
	}
	cout << endl;
	return a;
}
int main()
{
	HEAP a;
	a.heap = NULL; a.length = 0;
	a = init(a);
	a = Heap_sort(a);
	return 0;
}
