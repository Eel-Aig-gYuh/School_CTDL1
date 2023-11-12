#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
struct Node {
	int info;
	Node* next;
};
Node* first;
void init();
void output();
Node* cre(int x);
int insertFirst(int x);
int delFirst();
int insertLast(int x);
int delLast();
Node* search(int x);
int findDel(int x);
void clean();

int main() {
	int choice, x;
	bool hadVal = false;
	do {
		system("cls");
		cout << "=== DANH SACH LIEN KET VONG ===\n"
			<< "1, Khoi tao\n"
			<< "2, Xuat danh sach\n"
			<< "3, Them dau\n"
			<< "4, Xoa dau\n"
			<< "5, Them cuoi\n"
			<< "6, Xoa cuoi\n"
			<< "7, Tim va xoa\n"
			<< "8, Thoat\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init();
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // xuat
			if (!hadVal)
				cout << "Danh sach hien trong !" << endl;
			else {
				output();
			}
			break;
		case 3: // them dau
			cout << "Nhap gia tri muon them: "; cin >> x;
			if (insertFirst(x) == 1) {
				cout << "Them thanh cong !" << endl;
				hadVal = true;
			}
			else {
				cout << "Them khong thanh cong !" << endl;
			}
			break;
		case 4: // xoa dau
			if (!hadVal)
				cout << "Danh sach hien dang trong !" << endl;
			else {
				if (delFirst() == 1)
					cout << "Xoa thanh cong !" << endl;
				else
					cout << "Xoa khong thanh cong !" << endl;
			}
			break;
		case 5: // them cuoi
			cout << "Nhap gia tri muon them: "; cin >> x;
			if (insertLast(x) == 1) {
				cout << "Them thanh cong !" << endl;
				hadVal = true;
			}
			else
				cout << "Them khong thanh cong !" << endl;
			break;
		case 6: // xoa cuoi
			if (!hadVal)
				cout << "Danh sach hien dang trong !" << endl;
			else {
				if (delLast() == 1)
					cout << "Xoa thanh cong !" << endl;
				else
					cout << "Xoa khong thanh cong !" << endl;
			}
			break;
		case 7: // tim va xoa
			if (!hadVal)
				cout << "Danh sach hien dang trong !" << endl;
			else {
				cout << "Nhap gia tri can tim va xoa trong danh sach: "; cin >> x;
				if (findDel(x) == 0)
					cout << "Xoa khong thanh cong !" << endl;
				else
					cout << "Xoa thanh cong !" << endl;
			}
			break;
		default:
			cout << "Da thoat chuong trinh !" << endl;
			clean();
			return 0;
			break;
		}
		_getch();
	} while (true);
}

void clean() {
	while (first != NULL) {
		delFirst();
	}
	init();
}
int findDel(int x) {
	if (!first) return 0;
	Node* pos = search(x);
	if (pos == NULL) {
		return 0;
	}
	if (pos == first) {
		delFirst();
		return 1;
	}
	Node* p = first;
	while (p->next != pos) {
		p = p->next;
	}
	p->next = pos->next;
	delete pos;
	return 1;
}
Node* search(int x) {
	Node* p = first;
	bool check = false;
	while (p->next != first && p->info!=x) {
		p = p->next;
	}
	if (p->info == x) {
		check = true;
	}
	if (!check) return NULL;
	return p;
}
int delLast() {
	if (!first) return 0;
	Node* p = first;
	if (p->next == first) {
		delFirst();
		return 1;
	}
	Node* q = NULL;
	while (p->next != first) {
		q = p;
		p = p->next;
	}
	q->next = first;
	delete p;
	return 0;
}
int insertLast(int x) {
	Node* p = first;
	Node* q = cre(x);
	if (!q) return 0;
	if (!first) {
		insertFirst(x);
		return 1;
	}
	while (p->next != first) {
		p = p->next;
	}
	p->next = q;
	q->next = first;
	return 1;
}
int delFirst() {
	if (!first) return 0;
	Node* p = first;
	Node* q = first;
	while (q->next != first) {
		q = q->next;
	}
	if (p != q) {
		first = first->next;
		q->next = first;
	}
	else {
		first = NULL;
	}
	delete p;
	return 1;
}
int insertFirst(int x) {
	Node* p = first;
	Node* q = cre(x);
	if (!q) return 0;
	if (p != NULL) {
		while (p->next != first) {
			p = p->next;
		}
		p->next = q;
	}
	else
		q->next = q;
	first = q;
	return 1;
}
Node* cre(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = first;
	return p;
}
void output() {
	Node* p = first;
	do {
		cout << p->info << " -> ";
		p = p->next;
	} while (p != first);
}
void init() {
	first == NULL;
}