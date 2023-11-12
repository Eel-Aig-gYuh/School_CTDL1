#include<iostream>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<iomanip>

#define MAXSIZE 100
using namespace std;
void input(int a[], int& n);
void inputFromFile(int a[], int& n, char s[256]);
void output(int a[], int n);
int search(int a[], int n, int x);
int insertLast(int a[], int& n, int x);
int delLast(int a[], int& n);
int delAt(int a[], int& n, int pos);
int insertAt(int a[], int& n, int pos, int x);
int searchDel(int a[], int& n, int x);

int main() {
	int arr[MAXSIZE], n;
	int choice, pos, x;
	bool hadValue = false;
	char fileName[256] = "BT.txt";
	clock_t start, end;

	do {
		system("cls");
		cout << "=== DANH SACH MANG MOT CHIEU ===\n"
			<< "1. Nhap gia tri tu ban phim.\n"
			<< "2. Nhap gia tri tu file.\n"
			<< "3. Xuat danh sach.\n"
			<< "4. Tim phan tu trong danh sach.\n"
			<< "5. Them phan tu o cuoi danh sach.\n"
			<< "6. Xoa phan tu o cuoi danh sach.\n"
			<< "7. Xoa phan tu tai vi tri.\n"
			<< "8. Them phan tu tai vi tri.\n"
			<< "9. Tim va xoa phan tu trong danh sach.\n"
			<< "10. Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: // Nhap gia tri tu ban phim
			input(arr, n);
			hadValue = true;
			break;
		case 2: // Nhap gia tri tu file
			inputFromFile(arr, n, fileName);
			hadValue = true;
			break;
		case 3: // Xuat danh sach
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else
				output(arr, n);
			break;
		case 4: // Tim phan tu trong danh sach
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				cout << "Nhap gia tri can tim: "; cin >> x;
				start = clock();
				pos = search(arr, n, x);
				end = clock();
				if (pos != -1)
					cout << "Co trong danh sach, tai vi tri: " << pos + 1 << endl;
				else {
					cout << "Khong co trong danh sach !" << endl;
				}
				cout << "Do phuc tap cua thuat toan: " << setprecision(4) << fixed << double(end - start) / CLOCKS_PER_SEC << endl;
			}
			break;
		case 5: // Them phan tu o cuoi danh sach
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				cout << "Nhap gia tri muon them cuoi danh sach: "; cin >> x;
				if (insertLast(arr, n, x) != -1) {
					cout << "Them thanh cong !" << endl;
				}
				else
					cout << "Them khong thanh cong !" << endl;
			}
			break;
		case 6: // Xoa phan tu o cuoi danh sach
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				if (delLast(arr, n) != -1)
					cout << "Xoa thanh cong !" << endl;
				else
					cout << "Xoa khong thanh cong !" << endl;
			}
			break;
		case 7: // Xoa phan tu tai vi tri
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				cout << "Nhap vi tri can xoa: "; cin >> pos;
				if (delAt(arr, n, pos) != -1) {
					cout << "Xoa thanh cong !" << endl;
				}
				else {
					cout << "Xoa khong thanh cong !" << endl;
				}
			}
			break;
		case 8: // Them phan tu tai vi tri
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				cout << "Nhap gia tri muon them: "; cin >> x;
				cout << "Nhap vi tri muon them: "; cin >> pos;
				if (insertAt(arr, n, pos, x) != -1) {
					cout << "Them thanh cong !" << endl;
				}
				else {
					cout << "Them khong thanh cong !" << endl;
				}
			}
			break;
		case 9: // Tim va xoa phan tu trong danh sach
			if (!hadValue)
				cout << "Chua co du lieu dau vao !";
			else {
				cout << "Nhap gia tri can xoa: "; cin >> x;
				if (searchDel(arr, n, x) != -1) {
					cout << "Xoa thanh cong !" << endl;
				}
				else {
					cout << "Xoa khong thanh cong !" << endl;
				}
			}
			break;
		default:
			return 0;
		}
		_getch();
	} while (true);
}

int searchDel(int a[], int& n, int x) {
	int pos = search(a, n, x);
	if (pos == -1) return 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n - 1; j++) {
				swap(a[j], a[j + 1]);
			}
			--n;
			--i;
		}
	}
	return 1;
}
int insertAt(int a[], int& n, int pos, int x) {
	if (pos <= 0 || pos > MAXSIZE) return 0;
	--pos;
	for (int i = n; i > pos; i--) {
		swap(a[i], a[i - 1]);
	}
	a[pos] = x;
	++n;
	return 1;
}
int delAt(int a[], int& n, int pos) {
	if (pos<=0 || pos>MAXSIZE) return 0;
	--pos;
	for (int i = pos; i < n - 1; i++) {
		swap(a[i], a[i + 1]);
	}
	--n;
	return 1;
}
int delLast(int a[], int& n) {
	if (n == 1) return 0;
	--n;
	return 1;
}
int insertLast(int a[], int& n, int x) {
	if (n >= MAXSIZE) return 0;
	a[n] = x;
	++n;
	return 1;
}
int search(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) return i;
	}
	return -1;
}
void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void inputFromFile(int a[], int& n, char s[256]) {
	ifstream inFile;
	inFile.open(s, ios::in);
	if (inFile.is_open()) {
		inFile >> n;
		if (n <= 0 || n > MAXSIZE)
			cout << "Tong so phan tu khong thoa dieu kien !" << endl;
		else {
			for (int i = 0; i < n; i++)
				inFile >> a[i];
			cout << "Nhap file thanh cong !" << endl;
		}
	}
	else
		cout << "Khong doc duoc du lieu tu file !" << endl;
	inFile.close();
}
void input(int a[], int& n) {
	do {
		cout << "Nhap tong so phan tu can nhap: ";
		cin >> n;
	} while (n <= 0 || n > MAXSIZE);
	cout << "Nhap " << n << " gia tri trong mang: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}