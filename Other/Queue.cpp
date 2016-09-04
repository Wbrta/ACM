#include <cstdlib>
#include <iostream>
using namespace std;

typedef int Elemtype;
typedef struct node{
	Elemtype data;
	node *next;
}Queue;
typedef struct{
	Queue *front, *end;
}HeadNode;
/*
 *1.初始化一个队列
 *2.入队
 *3.出队
 *4.获取队首元素
 *5.判断队列是否为空
 */
bool isEmpty(HeadNode *hd) {
	return (hd -> front == NULL ? true : false);
}
HeadNode *initQueue() {
	HeadNode *p = new HeadNode;
	if (p == NULL) {
		cout << "分配内存失败！请重试！" << endl;
		exit(-1);
	}
	p -> front = NULL;
	p -> end = NULL;
	cout << "初始化成功！" << endl;
	return p;
}
void pushQueue(HeadNode *hd, Elemtype e) {
	Queue *p = new Queue;
	if (p == NULL) {
		cout << "分配内存失败！请重试！" << endl;
		exit(-1);
	}
	p -> next = NULL;
	p -> data = e;
	if(hd -> end != NULL)
        hd -> end -> next = p;
    hd -> end = p;
	if (hd -> front == NULL) {
		hd -> front = p;
	}
	cout << "入队成功！" << endl;
}
void popQueue(HeadNode *hd) {
	if (isEmpty(hd)) {
		cout << "该队列为空！不能进行出队操作！" << endl;
	}
	Queue *q = hd -> front;
	Queue *p = q -> next;
	hd -> front = p;
	delete q;
	cout << "出队成功！" << endl;
}
Elemtype frontQueue(HeadNode *hd) {
	if (isEmpty(hd)) {
		cout << "该队列为空！不能查询队首元素" << endl;
		return -1;
	}
	return hd -> front -> data;
}
int main()
{
	HeadNode *hd = initQueue();
	for (int i = 0; i < 10; ++i) {
		srand(i);
		Elemtype data = rand() % 100;
		pushQueue(hd, data);
		cout << "第 " << i + 1 << " 个元素是 " << data << endl;
	}
	cout << "该队列是否为空？ " << (isEmpty(hd) ? "True" : "False")  << endl;
	if (!isEmpty(hd)) {
		cout << "该队列元素为： " << endl;
		for (int i = 0; i < 10; ++i) {
			Elemtype data = frontQueue(hd);
			cout << "第 " << i + 1 << " 个元素是 " << data << endl;
			popQueue(hd);
		}
	}
	system("pause");
    return 0;
}
