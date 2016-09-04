#include <iostream>
using namespace std;
const int maxn = 1000;
typedef char Elemtype;
typedef struct node{
	Elemtype data;
	int parents;
}P;
P p[maxn];
int n, num;
void findBro(P a){
	cout << "The element " << a.data << "'s brothers are following: " << endl;
	for(int i = 0; i < n; ++i){
		if(a.parents == p[i].parents && a.data != p[i].data){
			cout << p[i].data << endl;
		}
	}
}
void findAncestors(P a){
	if(a.parents == -1) return;
	cout << p[a.parents].data << endl;
	findAncestors(p[a.parents]);
}
void findOffspring(P a){
	for(int i = 0; i < n; ++i){
		if(p[p[i].parents].data == a.data){
			cout << p[i].data << endl;
			findOffspring(p[i]);
		}
	}
}
int main()
{
	
	cout << "Please input the number of node: ";
	cin >> n;
	cout << "Please input every node of the binary tree: " << endl;
	for(int i = 0; i < n; ++i){
		int pos;
		cin >> pos;
		cin >> p[pos].data >> p[pos].parents;
	}
	cout << "The relationship between parents and childs are following: " << endl;
	for(int i = 0; i < n; ++i){
		cout << p[i].data << " " << p[i].parents << endl;
	}

	cout << "Please input which node you want to know: ";
	cin >> num;
	findBro(p[num]);
	cout << p[num].data << "'s ancestors are following: " << endl;
	findAncestors(p[num]);
	cout << p[num].data << "'s offspring are following: " << endl;
	findOffspring(p[num]);
	return 0;
}
