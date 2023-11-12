// THAP HA NOI
#include<iostream>
#include<string>
using namespace std;
struct stack {
	int n;
	char i, j, k;
	stack* next;
};
typedef stack* st;
void init(st& sp);
stack* cre(int x, char a, char b, char c);
void push(st &sp, int x, char a, char b, char c);
void pop(st& sp, int& x, char& a, char& b, char& c);
bool isEmpty(st sp);

int main() {
	int n, l, k = 1;
	st thap; init(thap);
	char a = 'A';
	char b = 'B';
	char c = 'C';
	do {
		cout << "Nhap so dia: "; cin >> n;
	} while (n <= 0);
	
	/*
		char cot[3] = {'A', 'B', 'C'};
		thap Ha Noi bang de quy
		void move(int n, int a, int b, int c){
			if (n==1)
				cout << cot[a] << "->" << cot[c] << endl;
			else{
				move(n-1, a, c, b);
				cout << cot[i] << "->" << cot[k] << endl;
				move(n-1, b, a, c);
			}
		}
	*/

	push(thap, n, a, b, c);
	while (!isEmpty(thap)) {
		pop(thap, n, a, b, c); // gan lai gia tri va xoa 1 node;
		if (n == 1) {
			cout << "Move " << a << " --> " << c << endl;
		}
		else {
			l = n - 1; // bien luu tam de cho phep de quy, nhap lai gia tri n
			push(thap, l, b, a, c); 
			push(thap, k, a, b, c);
			push(thap, l, a, c, b);
		}
	}

	system("pause");
	return 0;
}


bool isEmpty(st sp) {
	return sp == NULL;
}
void pop(st& sp, int &x, char& a, char& b, char& c) {
	if (sp == NULL) return;
	st p = sp;
	x = sp->n;
	a = sp->i;
	b = sp->j;
	c = sp->k;
	sp = sp->next;
	delete p;
}
void push(st &sp, int x, char a, char b, char c) {
	stack* q = cre(x, a, b, c);
	if (!q) return;
	q->next = sp;
	sp = q;
}
stack* cre(int x, char a, char b, char c) {
	stack* p = new stack;
	p->n = x;
	p->i = a;
	p->j = b;
	p->k = c;
	p->next = NULL;
	return p;
}
void init(st &sp) {
	sp = NULL;
}