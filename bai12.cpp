#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
int a[MAX];
int front, rear; // front: vi tri lay ra, rear: vi tri them vao
void init();
bool isEmpty();
bool isFull();
int push(int x);
int pop(int& x);
void output();
void clean();

int main() {
	int choice, x;
	do {
		system("cls");
		cout << "=== HANG DOI DANH SAH DAC ===\n"
			<< "1, Khoi tao.\n"
			<< "2, Kiem tra rong.\n"
			<< "3, Kiem tra day.\n"
			<< "4, Them gia tri.\n"
			<< "5, Lay va xoa gia tri.\n"
			<< "6, Xuat.\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init();
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // check rong
			if (isEmpty()) {
				cout << "Hang doi hien dang rong !" << endl;
			}
			else
				cout << "Hang doi dang chua gia tri !" << endl;
			break;
		case 3: // check day
			if (isFull())
				cout << "Hang doi day !" << endl;
			else
				cout << "Hang doi chua day !" << endl;
			break;
		case 4: // them gia tri;
			cout << "Nhap gia tri muon them vao hang doi: "; cin >> x;
			if (push(x) == 1)
				cout << "Them thanh cong !" << endl;
			else
				cout << "Them khong thanh cong !" << endl;
			break;
		case 5: // lay va xoa
			if (isEmpty()) {
				cout << "Hang doi khong ton tai gia tri de lay !" << endl;
			}
			else {
				if (pop(x) == 1) {
					cout << "Lay va xoa thanh cong !" << endl;
					cout << "Gia tri vua lay tu hang doi la: " << x << endl;
				}
				else {
					cout << "Lay va xoa khong thanh cong !" << endl;
				}
			}
			break;
		case 6: // xuat
			if (isEmpty())
				cout << "Hang doi khong ton tai gia tri de lay !" << endl;
			else
				output();
			break;
		default:
			clean();
			return 0;
			break;
		}
		_getch();
	} while (true);

	
}

void clean() {
	int x;
	while (!isEmpty()) {
		pop(x);
	}
}
void output() {
	int x;
	while (!isEmpty()) {
		if (pop(x) == 0)
			break;
		else {
			cout << x << " --> ";
		}
	}
	cout << endl;
}
int pop(int& x) {
	if (front != -1) {
		x = a[front];
		if (front == rear) {
			front = -1;
			rear = -1;
		}
		else {
			front++;
			if (front > MAX - 1)
				front = 0;
		}
		return 1;
	}
	return 0;
}
int push(int x) {
	if (rear - front == MAX - 1 || rear - front == -1)
		return 0;
	else {
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
			rear = -1;
		a[++rear] = x;
		return 1;
	}
}
bool isFull() {
	return rear == MAX - 1;
}
bool isEmpty() {
	return front == -1;
}
void init() {
	front = -1;
	rear = -1;
}