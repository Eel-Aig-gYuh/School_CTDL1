#include<iostream>
#include<conio.h>
#include<iomanip>

#define MAX 100
using namespace std;
int a[MAX];
int sp;
void init();
bool isEmpty();
bool isFull();
int push(int x, int &sp);
int peek(int &x);
int pop();
void output();

int main() {
	int choice, x;
	do {
		system("cls");
		cout << "=== STACK DAC ===\n"
			<< "1, Khoi tao.\n"
			<< "2, Xet stack rong.\n"
			<< "3, Xet stack day.\n"
			<< "4, Them 1 phan tu.\n"
			<< "5, Xoa 1 phan tu.\n"
			<< "6, Xuat.\n"
			<< "7, Thoat\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init();
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // xet rong
			if (isEmpty())
				cout << "Stack rong !" << endl;
			else
				cout << "Stack co gia tri !" << endl;
			break;
		case 3: // xat day
			if (isFull())
				cout << "Stack day !" << endl;
			else
				cout << "Stack chua day !" << endl;
			break;
		case 4: // them phan tu
			cout << "Nhap gia tri can them: "; cin >> x;
			if (push(x,sp) == 1)
				cout << "Them thanh cong !" << endl;
			else
				cout << "Them khong thanh cong !" << endl;
			break;
		case 5: // xoa 1 phan tu
			if (pop() == 1)
				cout << "Xoa thanh cong !" << endl;
			else
				cout << "Xoa khong thanh cong !" << endl;
			break;
		case 6: // xuat
			output();
			break;
		default:
			return 0;
		}
		_getch();
	} while (true);

	//return 0;
}

void output() {
	while (!isEmpty()) {
		int x;
		peek(x);
		cout << x << " ";
		pop();
	}
}
int peek(int &x) {
	if (!isEmpty()) {
		x = a[sp];
		return 1;
	}
	return 0;
}
int pop() {
	if (!isEmpty()) {
		sp--;
		return 1;
	}
	else
		return 0;
}
int push(int x, int &sp) {
	if (!isFull()) {
		a[++sp] = x;
		return 1;
	}
	else
		return 0;
}
bool isFull() {
	if (sp == MAX - 1)
		return true;
	return false;
}
bool isEmpty() {
	if (sp == -1)
		return true;
	return false;
}
void init() {
	sp = -1;
}