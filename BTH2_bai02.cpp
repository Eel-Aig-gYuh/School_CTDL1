#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
struct Node {
	int info;
	Node* next;
};
Node* first;
void init();
Node* cre(int x);
void push(int x);
void input(int &n);
int inputFromFile(int& n, char s[256]);
void output();
void delAt(Node* k);
void insertionSort();
void selectionSort();
void interchangeSort();
void bubbleSort();
Node* search(int x);

bool checkSort();

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
			input(n);
			hadValue = true;
			break;
		case 2: // nhap file
			if (inputFromFile(n, s) == 0) {
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
				output();
			}
			break;
		case 4: // insert
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				insertionSort();
				cout << "Sap xep thanh cong !" << endl;
			}
			break;
		case 5: // selection
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				selectionSort();
				cout << "Sap xep thanh cong !" << endl;
			}
			break;
		case 6: // interchange
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				interchangeSort();
				cout << "Sap xep thanh cong !" << endl;
			}
			break;
		case 7: // bubble
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				bubbleSort();
				cout << "Sap xep thanh cong !" << endl;
			}
			break;
		case 8: // merge
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				
			}
			break;
		case 9: // tim tuan tu
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				cout << "Nhap gia tri can tim: "; cin >> x;
				if (!search(x))
					cout << "Khong ton tai trong danh sach !" << endl;
				else
					cout << "Ton tai trong danh sach !" << endl;
			}
			break;
		case 10: // tim nhi phan
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				
			}
			break;
		case 11: // check
			if (!hadValue)
				cout << "Danh sach rong !" << endl;
			else {
				if (!checkSort())
					cout << "Mang chua duoc sap xep !" << endl;
				else
					cout << "Mang da duoc xep tang dan !" << endl;
			}
			break;
		default:
			return 0;
			break;
		}
		_getch();
	} while (true);
}

bool checkSort() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		if (p->info > q->info)
			return false;
		p = p->next;
	}
	return true;
}
Node* search(int x) {
	Node* p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
void bubbleSort() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = first;
		while (q->next != NULL) {
			Node* r = q->next;
			if (r->info < q->info) {
				swap(r->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void interchangeSort() {
	Node* p = first;
	while (p->next != NULL) {
		Node* q = p->next;
		while (q != NULL) {
			if (p->info > q->info) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void selectionSort() {
	Node* p = first;
	while (p->next != NULL) {
		Node* minpos = p;
		Node* q = p->next;
		while (q != NULL) {
			if (minpos->info > q->info)
				minpos = q;
			q = q->next;
		}
		swap(p->info, minpos->info);
		p = p->next;
	}
}
void insertionSort() {
	Node* p = first;
	p = p->next;
	while (p != NULL) {
		int x = p->info;
		Node* q = first;
		while (q->next != p && q->info < x)
			q = q->next;
		Node* r = cre(x);
		r->next = q->next;
		q->next = r;
		swap(q->info, r->info);
		Node* k = p;
		p = p->next;
		delAt(k);
	}
}
void delAt(Node* k) {
	Node* p = first;
	Node* q = k;
	while (p->next != q)
		p = p->next;
	p->next = q->next;
	delete q;
}
void output() {
	Node* p = first;
	while (p != NULL) {
		cout << p->info << " --> ";
		p = p->next;
	}
	cout << endl;
}
int inputFromFile(int& n, char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (!in.is_open()) return 0;
	int m;
	in >> m;
	for (int i = n; i < m + n; i++) {
		int x;
		in >> x;
		push(x);
	}
	n += m;
	in.close();
	return 1;
}
void input(int &n) {
	do {
		cout << "Nhap vao so phan tu muon them: "; 
		cin >> n;
		if (n <= 0)
			cout << "Nhap sai, nhap lai!" << endl;
	} while (n <= 0);
	cout << "Bat dau nhap " << n << " phan tu: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		push(x);
	}
	cout << "Nhap thanh cong !" << endl;
}
void push(int x) {
	Node* p = cre(x);
	p->next = first;
	first = p;
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