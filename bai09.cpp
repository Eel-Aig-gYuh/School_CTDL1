#include<iostream>
#include<string>
using namespace std;
struct Node {
	int info;
	Node* next;
};
Node* first;
void init();
Node* cre(int x);
int push(int x);
void delFirst();
bool isEmpty();
int pop(int& x);
int calcu(int n);

int main() {
	int n;
	init();
	do {
		cout << "Nhap gia tri: "; cin >> n;
	} while (n <= 0);
	cout << "Sau khi chuyen: " << calcu(n) << endl;
	system("pause");
	return 0;
}

int calcu(int n) {
	while (n != 0) {
		push(n % 2);
		n /= 2;
	}
	Node* p = first;
	int kq = 0, x;
	while (!isEmpty()) {
		pop(x);
		kq = kq * 10 + x;
	}
	return kq;
}
int pop(int& x) {
	if (!first) return 0;
	x = first->info;
	delFirst();
	return 1;
}
bool isEmpty() {
	if (first == NULL)
		return true;
	return false;
}
void delFirst() {
	if (!first) return;
	Node* p = first;
	first = first->next;
	delete p;
}
int push(int x) {
	Node* q = cre(x);
	if (!q) return 0;
	q->next = first;
	first = q;
	return 1;
}
Node* cre(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void init() {
	first = NULL;
}