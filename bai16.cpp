#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
void input(int a[], int& n);
void output(int a[], int n);
int search(int a[], int n, int x);
void push(int a[], int& n, int x);
void laHop(int a[], int n, int b[], int m);
void laGiao(int a[], int n, int b[], int m);
void laBu(int a[], int n, int b[], int m);

int main() {
	int a[MAX], b[MAX], n, m;
	int choice;
	bool hadValue = false;
	do {
		system("cls");
		cout << "=== TIM HOP, GIAO, BU DANH SACH DAC ===\n"
			<< "1, Nhap hai tap hop.\n"
			<< "2, Xuat hai tap hop.\n"
			<< "3, Tim hop.\n"
			<< "4, Tim giao.\n"
			<< "5, Tim bu.\n"
			<< "6, Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // nhap
			cout << "Tap hop thu nhat: " << endl;
			input(a, n);
			cout << "Tap hop thu hai: " << endl;
			input(b, m);
			cout << "Da nhap thanh cong !" << endl;
			hadValue = true;
			break;
		case 2: // xuat
			if (!hadValue)
				cout << "Chua nhap du lieu !" << endl;
			else {
				cout << "Tap hop thu nhat: " << endl;
				output(a, n);
				cout << "Tap hop thu hai: " << endl;
				output(b, m);
			}
			break;
		case 3: // hop
			if (!hadValue)
				cout << "Chua nhap du lieu !" << endl;
			else {
				laHop(a, n, b, m);
			}
			break;
		case 4: // giao
			if (!hadValue)
				cout << "Chua nhap du lieu !" << endl;
			else {
				laGiao(a, n, b, m);
			}
			break;
		case 5: // bu
			if (!hadValue)
				cout << "Chua nhap du lieu !" << endl;
			else {
				laBu(a, n, b, m);
			}
			break;
		default:
			cout << "Da thoat chuong trinh !" << endl;
			return 0;
			break;
		}
		_getch();
	} while (true);
}

void laBu(int a[], int n, int b[], int m) {
	int c[MAX + MAX], k = 0;
	for (int i = 0; i < n; i++) {
		if (search(b, m, a[i]) == -1)
			push(c, k, a[i]);
	}
	for (int i = 0; i < m; i++) {
		if (search(a, n, b[i]) == -1)
			push(c, k, b[i]);
	}
	output(c, k);
}
void laGiao(int a[], int n, int b[], int m) {
	int c[MAX + MAX], k = 0;
	for (int i = 0; i < n; i++) {
		if (search(b, m, a[i]) != -1 && search(c,k, a[i]) == -1)
			push(c, k, a[i]);
	}
	output(c, k);
}
void laHop(int a[], int n, int b[], int m) {
	int c[MAX + MAX], k = 0;
	for (int i = 0; i < n; i++) {
		if (search(c, k, a[i]) == -1)
			push(c, k, a[i]);
	}
	for (int i = 0; i < m; i++) {
		if (search(c, k, b[i]) == -1)
			push(c, k, b[i]);
	}
	output(c, k);
}
void push(int a[], int& n, int x) {
	if (n < MAX + MAX) {
		a[n++] = x;
	}
	return;
}
int search(int a[], int n, int x) {
	int i = 0; 
	while (i < n && a[i] != x) {
		i++;
	}
	if (i == n) return -1;
	return i;
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " --> ";
	}
	cout << endl;
}
void input(int a[], int& n) {
	do {
		cout << "Nhap tong gia tri phan tu: "; cin >> n;
		if (n<0 || n>MAX)
			cout << "Nhap sai, nhap lai !" << endl;
	} while (n<0 || n>MAX);
	cout << "Nhap gia tri cho tap hop: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}