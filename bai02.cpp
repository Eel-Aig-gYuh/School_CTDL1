#include<iostream>
#include<fstream>
#include<conio.h>

#define MAXSIZE 100
using namespace std;

void sort(int a[], int n);
int insert(int a[], int& n);
int insertFile(int a[], int& n, char s[256]);
void output(int a[], int n);
int searchIndex(int a[], int n, int x);
int searchTreeBit(int a[], int n, int x);
int searchDel(int a[], int& n, int x);
void merge(int a[], int b[], int n, int m, int c[], int& size);

int main() {
	int a[MAXSIZE], n = 0, b[MAXSIZE], m = 0, c[MAXSIZE + MAXSIZE], size = 0;
	int choice, x, pos;
	bool hadValue = false;
	char fileName[256] = "BT.txt";
	do {
		system("cls");
		cout << "DANH SACH MANG MOT CHIEU CO THU TU\n"
			<< "1. Nhap tu ban phim.\n"
			<< "2. Nhap tu file.\n"
			<< "3. Xuat mang.\n"
			<< "4. Tim phan tu trong mang (phuong phap tuan tu).\n"
			<< "5. Tim phan tu trong mang (phuong phap cay nhi pham).\n"
			<< "6. Tim va xoa phan tu.\n"
			<< "7. Gop 2 danh sach.\n"
			<< "8. Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: // Nhap tu ban phim
			if (insert(a, n) != 0) {
				hadValue = true;
			}
			else {
				cout << "Them gia tri vao mang khong thanh cong !" << endl;
			}
			break;
		case 2: // Nhap tu file
			if (insertFile(a, n, fileName) != 0) {
				hadValue = true;
			}
			else {
				cout << "Nhap gia tri tu file khong thanh cong !" << endl;
			}
			break;
		case 3: // Xuat mang
			if (!hadValue)
				cout << "Khong co gia tri trong mang !" << endl;
			else {
				output(a, n);
			}
			break;
		case 4: // Tim phan tu trong mang (phuong phap tuan tu)
			if (!hadValue)
				cout << "Khong co gia tri trong mang !" << endl;
			else {
				cout << "Nhap gia tri muon tim kiem trong mang: "; cin >> x;
				pos = searchIndex(a, n, x);
				if (pos == -1)
					cout << "Khong co phan tu " << x << " trong mang !" << endl;
				else {
					cout << "Co phan tu trong mang, tai vi tri " << pos << endl;
				}
			}
			break;
		case 5: // Tim phan tu trong mang (phuong phap cay nhi pham)
			if (!hadValue)
				cout << "Khong co gia tri trong mang !" << endl;
			else {
				cout << "Nhap gia tri muon tim kiem trong mang: "; cin >> x;
				pos = searchTreeBit(a, n, x);
				if (pos == -1)
					cout << "Khong co phan tu " << x << " trong mang !" << endl;
				else {
					cout << "Co phan tu trong mang, tai vi tri " << pos << endl;
				}
			}
			break;
		case 6: // Tim va xoa phan tu
			if (!hadValue)
				cout << "Khong co gia tri trong mang !" << endl;
			else {
				cout << "Nhap gia tri muon tim kiem trong mang: "; cin >> x;
				if (searchDel(a, n, x) == -1) {
					cout << "Xoa khong thanh cong !" << endl;
				}
				else {
					cout << "Xoa thanh cong !" << endl;
				}
			}
			break;
		case 7: // Gop 2 danh sach
			if (!hadValue)
				cout << "Khong co gia tri trong mang !" << endl;
			else {
				do {
					cout << "Nhap tong so phan tu cua mang b: "; cin >> m;
	
				} while (m <= 0 || m > MAXSIZE);
				cout << "Nhap " << m << " phan tu cua b: ";
				for (int i = 0; i < m; i++) {
					cin >> b[i];
				}
				sort(b, m);
				merge(a, b, n, m, c, size);
				cout << "Gop thanh cong !" << endl;
				output(c, size);
			}
			break;
		default: // Thoat chuong trinh
			return 0;
		}
		_getch();
	} while (true);
}

void merge(int a[], int b[], int n, int m, int c[], int& size) {
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			c[size] = a[i];
			++i;
		}
		else {
			c[size] = b[j];
			++j;
		}
		++size;
	}
	while (i < n) {
		c[size] = a[i];
		++size;
		++i;
	}
	while (j < m) {
		c[size] = b[j];
		++size;
		++j;
	}
}
int searchDel(int a[], int& n, int x) {
	int pos = searchTreeBit(a, n, x);
	if (pos == -1) return -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n - 1; j++) {
				swap(a[i], a[j]);
			}
			--n;
			--i;
		}
	}
	return 1;
}
int searchTreeBit(int a[], int n, int x) {
	int left = 0, right = n - 1 , mid = 0;
	if (a[left] > x || a[right] < x) return -1;
	do {
		mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		}
		if (a[mid] > x) {
			right = mid;
		}
		if (a[mid] < x) {
			left = mid;
		}
	} while (right - left != 1);
	if (a[left] == x) {
		return left;
	}
	else if (a[right] == x) {
		return right;
	}
	return -1;
}
int searchIndex(int a[], int n, int x) {
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
int insertFile(int a[], int& n, char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (in.is_open()) {
		in >> n;
		for (int i = 0; i < n; i++) {
			in >> a[i];
		}
		sort(a, n);
		return 1;
	}
	else {
		return 0;
	}
	in.close();
}
int insert(int a[], int& n) {
	if (n > MAXSIZE) return 0;
	cout << "Nhap gia tri muon them: "; int x; cin >> x;
	a[n] = x;
	++n;
	if (a[n] < a[n - 1]) {
		sort(a, n);
	}
	return 1;
}
void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}