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
		cout << "内存分配失败！请检查后重试！" << endl;
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
		cout << "未找到元素 " << elem << endl;
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
	cout << "输入元素为：" << endl;
	for(int i = 0; i < 10; ++i){
		int tmp = rand() % 100;
		root = insert(root, tmp);
		cout << tmp << " ";
		//system("pause");
	}
	cout << endl << "元素为：" << endl;
	BLinRootSecond(root);
	cout << endl;

	for(int i = 0; i < 5; ++i){
		cout << "请输入您想要删除的元素：" << endl;
		int tmp;
		cin >> tmp;
		deleteNode(root, tmp);
		cout << "删除后元素为：" << endl;
		BLinRootSecond(root);
		cout << endl;
		//system("pause");
	}
	//system("pause");
	return 0;
}