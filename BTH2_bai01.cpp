#include<iostream>
#include<fstream>
#include<conio.h>
#define MAX 100
using namespace std;
int a[MAX];
void nhap(int& n);
int nhapFile(int& n, char s[256]);
void output(int n);
void insertionSort(int n);
void selectionSort(int n);
void interchangeSort(int n);
void bubbleSort(int n);
void merge(int l, int m, int r);
void mergeSort(int l, int r);
int find_TT(int n, int x);
int find_NP(int n, int x);
bool checkSort(int n);

int main() {
	int n = 0, x, pos;
	int choice;
	bool hadValue = false;
	char s[256] = "BTH2_bai01.txt";
	do {
		system("cls");
		cout << " 1, Nhap du lieu tu ban phim.\n"
			<< " 2, Nhap du lieu tu file.\n"
			<< " 3, Xuat danh sach.\n"
			<< " 4, Insertion Sort.\n"
			<< " 5, Selection Sort.\n"
			<< " 6, Interchange Sort.\n"
			<< " 7, Bubble Sort.\n"
			<< " 8, Merge Sort.\n"
			<< " 9, Tim bang phuong phap tuan tu.\n"
			<< "10, Tim bang phuong phan nhi phan.\n"
			<< "11, Kiem tra sap xep.\n"
			<< "12, Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // nhap
			nhap(n);
			hadValue = true;
			break;
		case 2: // nhap file
			if (nhapFile(n,s) == 0) {
				cout << "Khong tim thay file !" << endl;
			}
			else {
				cout << "Nhap thanh cong !" << endl;
				hadValue = true;
			}
			break;
		case 3: // xuat
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				output(n);
			}
			break;
		case 4: // insert
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				insertionSort(n);
				output(n);
			}
			break;
		case 5: // selection
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				selectionSort(n);
				output(n);
			}
			break;
		case 6: // interchange
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				interchangeSort(n);
				output(n);
			}
			break;
		case 7: // bubble
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				bubbleSort(n);
				output(n);
			}
			break;
		case 8: // merge
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				int l, r;
				do {
					cout << "Nhap khoang muon sap xep: ";
					cin >> l >> r;
					if (l > r || r <= 0 || r > MAX)
						cout << "Nhap sai, nhap lai !" << endl;
				} while (l > r || r <= 0 || r > MAX);
				mergeSort(l - 1, r  - 1);
				output(n);
			}
			break;
		case 9: // tim tuan tu
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				cout << "Nhap gia tri muon tim: "; cin >> x;
				pos = find_TT(n, x);
				if (pos == -1) {
					cout << "Khong ton tai gia tri trong danh sach !" << endl;
				}
				else
					cout << "Xuat hien tai vi tri: " << pos << endl;
			}
			break;
		case 10: // tim nhi phan
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				cout << "Nhap gia tri muon tim: "; cin >> x;
				pos = find_NP(n, x);
				if (pos == -1) {
					cout << "Khong ton tai gia tri trong danh sach !" << endl;
				}
				else
					cout << "Xuat hien tai vi tri: " << pos << endl;
			}
			break;
		case 11: // check
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				if (checkSort(n))
					cout << "Danh sach da duoc sap xep !" << endl;
				else
					cout << "Danh sach chua duoc sap xep !" << endl;
			}
			break;
		default:
			return 0;
			break;
		}
		_getch();
	} while (true);
}
bool checkSort(int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}
int find_NP(int n, int x) {
	insertionSort(n);
	int l = 0;
	int r = n - 1;
	while (l > r) {
		int mid = (l + r) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	return -1;
}
int find_TT(int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}
void merge(int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[MAX], R[MAX];
	for (i = 0; i < n1; i++) {
		L[i] = a[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = a[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}
void bubbleSort(int n) {
	for (int i = 0; i < n - 1; i++) {
		int j = n - 1;
		while (j > i) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
			j--;
		}
	}
}
void interchangeSort(int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void selectionSort(int n) {
	int minpos;
	for (int i = 0; i < n - 1; i++) {
		minpos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[minpos] > a[j]) {
				minpos = j;
			}
		}
		swap(a[i], a[minpos]);
	}
}
void insertionSort(int n) {
	int i, j, x;
	for (int i = 1; i < n; i++) {
		x = a[i];
		j = i - 1;
		while (j >= 0 && x<a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void output(int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " --> ";
	}
	cout << endl;
}
int nhapFile(int& n, char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (!in.is_open()) return 0;
	int m; 
	in >> m;
	for (int i = n; i < n + m; i++) {
		in >> a[i];
	}
	n += m;
	in.close();
	return 1;
}
void nhap(int& n) {
	do {
		cout << "Nhap tong gia tri: "; cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai, nhap lai!" << endl;
	} while (n <= 0 || n > MAX);
	cout << "Nhap " << n << " gia tri: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Da nhap thanh cong !" << endl;
}