#include <iostream>
using namespace std;
typedef struct node{
	int data; int pos;
	node *l, *r;
}Tree;

void insert(Tree *root, int los, int fat, int num){
	if(root == NULL) return;
	if(fat == 0){
		root -> pos = los;
		root -> data = num;
		root -> l = NULL;
		root -> r = NULL;
		return;
	}else if(root -> pos == fat){
		Tree *p = new Tree;
		p -> data = num;
		p -> pos = los;
		p -> l = NULL;
		p -> r = NULL;
		if(root -> l == NULL){
			root -> l = p;
		}else{
			root -> r = p;
		}
		return;
	}else{
		insert(root -> l, los, fat, num);
		insert(root -> r, los, fat, num);
	}
}
void BLinRootFirst(Tree *root){
	if(root == NULL) return;
	cout << root -> data << " ";
	BLinRootFirst(root -> l);
	BLinRootFirst(root -> r);
}
void BLinRootSecond(Tree *root){
	if(root == NULL) return;
	BLinRootSecond(root -> l);
	cout << root -> data << " ";
	BLinRootSecond(root -> r);
}
void BLinRootFinal(Tree *root){
	if(root == NULL) return;
	BLinRootFinal(root -> l);
	BLinRootFinal(root -> r);
	cout << root -> data << " ";
}
bool isLeaf(Tree *root){
	if(root -> l == NULL && root -> r == NULL) return true;
	else return false;
}
int getLeafNumber(Tree *root){
	if(root == NULL) return 0;
	if(isLeaf(root)) return 1;
	return getLeafNumber(root -> l) + getLeafNumber(root -> r);
}
void swap(Tree *root){
	if(root == NULL) return;
	Tree *temp;
	temp = root -> l;
	root -> l = root -> r;
	root -> r = temp;
	swap(root -> l);
	swap(root -> r);
}
int main()
{
	Tree *root = new Tree;
	int n;
	cout << "Please input the number of Binary Tree: "; cin >> n;
	cout << "Please input " << n << " numbers and its location, its father node: " << endl;
	for(int i = 0; i < n; ++i){
		int num, los, fat;
		cin >> num >> los >> fat;
		insert(root, los, fat, num);
	}
	
	cout << "The element of the Binary Tree visit in root First is: " << endl;
	BLinRootFirst(root);
	cout << endl;
	cout << "The element of the Binary Tree visit in root Second is: " << endl;
	BLinRootSecond(root);
	cout << endl;
	cout << "The element of the Binary Tree visit in root Last is: " << endl;
	BLinRootFinal(root);
	cout << endl;
	
	cout << "The number of Leaf node is " << getLeafNumber(root) << endl;
	
	swap(root);
	cout << "The element of the Binary Tree visit in root First is: " << endl;
	BLinRootFirst(root);
	cout << endl;
	cout << "The element of the Binary Tree visit in root Second is: " << endl;
	BLinRootSecond(root);
	cout << endl;
	cout << "The element of the Binary Tree visit in root Last is: " << endl;
	BLinRootFinal(root);
	cout << endl;
	return 0;
}
