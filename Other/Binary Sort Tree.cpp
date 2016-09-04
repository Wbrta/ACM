#include <time.h>
#include <iostream>
using namespace std;
typedef struct node{
	int data;
	node *left, *right;
}SBTnode;
SBTnode* insert(SBTnode *root, int elem){
	SBTnode *q = root;
	SBTnode *p = new SBTnode;
	if(p == NULL) {
		cout << "�ڴ����ʧ�ܣ���������ԣ�" << endl;
		return root;
	}
	p -> data = elem;
	p -> left = p -> right = NULL;

	if(root == NULL){
		root = p;
	}else{
		while(true){
			if(q -> data > elem){
				if(q -> left == NULL){
					q -> left = p;
					break;
				}else
					q = q -> left;
			}else{
				if(q -> right == NULL){
					q -> right = p;
					break;
				}
				else
					q = q -> right;
			}
		}
	}

	return root;
}
void deleteNode(SBTnode *root, int elem){
	SBTnode *q = root, *p;
	while(q && q -> data != elem){
		p = q;
		if(q -> data > elem){
			q = q -> left;
		}else{
			q = q -> right;
		}
	}
	if(q == NULL){
		cout << "δ�ҵ�Ԫ�� " << elem << endl;
		return;
	}else{
		if(q -> left == NULL && q -> right == NULL){
			if(p -> left == q) p -> left = NULL;
			else p -> right = NULL;
			delete q;
		}else if(q -> left != NULL && q -> right == NULL){
			if(p -> left == q){
				p -> left = q -> left;
			}else{
				p -> right = q -> left;
			}
			delete q;
		}else if(q -> left == NULL && q -> right != NULL){
			if(p -> left == q){
				p -> left = q -> right;
			}else{
				p -> right = q -> right;
			}
			delete q;
		}else{
			SBTnode *r = q -> left, *s = q;
			while(r -> right){
				s = r;
				r = r -> right;
			}
			
			int tmp = q -> data;
			q -> data = r -> data;
			r -> data = tmp;

			if(r -> left == NULL){
				s -> right = NULL;
				delete r;
			}else{
				if(s == q){
					s -> left = r -> left;
				}else{
					s -> right = r -> left;
				}
				delete r;
			}
		}
		return;
	}
}
void BLinRootSecond(SBTnode* root){
	if(root == NULL) return;
	BLinRootSecond(root -> left);
	cout << root -> data << " ";
	BLinRootSecond(root -> right);
}
int main()
{
	SBTnode *root = NULL;
	srand((unsigned)time(NULL));
	cout << "����Ԫ��Ϊ��" << endl;
	for(int i = 0; i < 10; ++i){
		int tmp = rand() % 100;
		root = insert(root, tmp);
		cout << tmp << " ";
		//system("pause");
	}
	cout << endl << "Ԫ��Ϊ��" << endl;
	BLinRootSecond(root);
	cout << endl;

	for(int i = 0; i < 5; ++i){
		cout << "����������Ҫɾ����Ԫ�أ�" << endl;
		int tmp;
		cin >> tmp;
		deleteNode(root, tmp);
		cout << "ɾ����Ԫ��Ϊ��" << endl;
		BLinRootSecond(root);
		cout << endl;
		//system("pause");
	}
	//system("pause");
	return 0;
}