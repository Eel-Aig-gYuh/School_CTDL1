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
string calcu(int n, int he);

int main() {
	int n, he;
	init();
	
	do {
		cout << "Nhap gia tri: "; cin >> n;
		cout << "Nhap he: "; cin >> he;
	} while (n <= 0 || he != 2 && he != 8 && he != 16);
	cout << "Sau khi chuyen: " << calcu(n, he) << endl;
	system("pause");
	return 0;
}

string calcu(int n, int he) {
	string s[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };
	while (n != 0) {
		push(n % he);
		n /= he;
	}
	Node* p = first;
	string kq = ""; int x;
	while (!isEmpty()) {
		pop(x);
		kq += s[x];
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