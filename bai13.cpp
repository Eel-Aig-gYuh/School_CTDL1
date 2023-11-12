#include<iostream>
using namespace std;
struct Stack {
	int info;
	Stack* next;
};
Stack* sp;
void init();
bool isEmpty();
Stack* cre(int x);
void push(int x);
void pop(int &x);
int trans(int n);

int main() {
	int n;
	do {
		cout << "Nhap so he thap phan: "; cin >> n;
	} while (n <= 0);
	cout << "Nhi phan cua " << n << " = " << trans(n) << endl;
	system("pause");
	return 0;
}
int trans(int n) {
	while (n != 0) {
		push(n % 2);
		n /= 2;
	}
	int kq = 0;
	while (!isEmpty()) {
		int x;
		pop(x);
		kq = kq * 10 + x;
	}
	return kq;
}
void pop(int &x) {
	Stack* p = sp;
	x = sp->info;
	sp = sp->next;
	delete p;
}
void push(int x) {
	Stack* q = cre(x);
	if (!q) return;
	sp = q;
}
Stack* cre(int x) {
	Stack* p = new Stack;
	p->info = x;
	p->next = sp;
	return p;
}
bool isEmpty() {
	return sp == NULL;
}
void init() {
	sp = NULL;
}