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
 *1.��ʼ��һ������
 *2.���
 *3.����
 *4.��ȡ����Ԫ��
 *5.�ж϶����Ƿ�Ϊ��
 */
bool isEmpty(HeadNode *hd) {
	return (hd -> front == NULL ? true : false);
}
HeadNode *initQueue() {
	HeadNode *p = new HeadNode;
	if (p == NULL) {
		cout << "�����ڴ�ʧ�ܣ������ԣ�" << endl;
		exit(-1);
	}
	p -> front = NULL;
	p -> end = NULL;
	cout << "��ʼ���ɹ���" << endl;
	return p;
}
void pushQueue(HeadNode *hd, Elemtype e) {
	Queue *p = new Queue;
	if (p == NULL) {
		cout << "�����ڴ�ʧ�ܣ������ԣ�" << endl;
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
	cout << "��ӳɹ���" << endl;
}
void popQueue(HeadNode *hd) {
	if (isEmpty(hd)) {
		cout << "�ö���Ϊ�գ����ܽ��г��Ӳ�����" << endl;
	}
	Queue *q = hd -> front;
	Queue *p = q -> next;
	hd -> front = p;
	delete q;
	cout << "���ӳɹ���" << endl;
}
Elemtype frontQueue(HeadNode *hd) {
	if (isEmpty(hd)) {
		cout << "�ö���Ϊ�գ����ܲ�ѯ����Ԫ��" << endl;
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
		cout << "�� " << i + 1 << " ��Ԫ���� " << data << endl;
	}
	cout << "�ö����Ƿ�Ϊ�գ� " << (isEmpty(hd) ? "True" : "False")  << endl;
	if (!isEmpty(hd)) {
		cout << "�ö���Ԫ��Ϊ�� " << endl;
		for (int i = 0; i < 10; ++i) {
			Elemtype data = frontQueue(hd);
			cout << "�� " << i + 1 << " ��Ԫ���� " << data << endl;
			popQueue(hd);
		}
	}
	system("pause");
    return 0;
}
