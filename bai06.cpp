#include<iostream>
#include<conio.h>

using namespace std;
struct Node {
	int info;
	Node* next, * pre;
};
Node* first, * last;
void init();
void output();
Node* create(int x);
int insertFirst(int x);
int insertLast(int x);
int delFirst();
int delLast();
Node* search(int x);
int delValue(int x);
int insertBefore(int y, int x);
void clean();

int main() {
	int choice, x, y;
	bool hadVal = false;
	do {
		system("cls");
		cout << "DANH SACH LIEN KET KEP\n"
			<< "1. Khoi tao\n"
			<< "2. Xuat\n"
			<< "3. Them phan tu vao dau\n"
			<< "4. Them phan tu vao cuoi\n"
			<< "5. Xoa phan tu dau\n"
			<< "6. Xoa phan tu cuoi\n"
			<< "7. Tim va xoa phan tu\n"
			<< "8. Them phan tu vao truoc phan tu cho truoc\n"
			<< "9. Thoat chuong trinh\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init();
			cout << "Khoi tao danh sach thanh cong !" << endl;
			break;
		case 2: // xuat
			if (hadVal) {
				output();
			}
			else {
				cout << "Chua khoi tao gia tri cho danh sach !" << endl;
			}
			break;
		case 3: // them dau
			cout << "Nhap gia tri muon them: "; cin >> x;
			if (insertFirst(x) == 1) {
				hadVal = true;
				cout << "Them thanh cong !" << endl;
			}
			else {
				cout << "Them khong thanh cong !" << endl;
			}
			break;
		case 4: // them cuoi
			cout << "Nhap gia tri muon them: "; cin >> x;
			if (insertLast(x) == 1) {
				hadVal = true;
				cout << "Them thanh cong !" << endl;
			}
			else {
				cout << "Them khong thanh cong !" << endl;
			}
			break;
		case 5: // xoa dau
			if (hadVal) {
				if (delFirst() == 1) {
					cout << "Xoa thanh cong !" << endl;
				}
				else {
					cout << "Xoa khong thanh cong !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao gia tri cho danh sach !" << endl;
			}
			break;
		case 6: // xoa cuoi
			if (hadVal) {
				if (delLast() == 1) {
					cout << "Xoa thanh cong !" << endl;
				}
				else {
					cout << "Xoa khong thanh cong !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao gia tri cho danh sach !" << endl;
			}
			break;
		case 7: // tim va xoa
			if (hadVal) {
				cout << "Nhap gia tri can tim: "; cin >> x;
				if (delValue(x) == 1) {
					cout << "Xoa thanh cong !" << endl;
				}
				else {
					cout << "Xoa khong thanh cong !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao gia tri cho danh sach !" << endl;
			}
			break;
		case 8: // them truoc
			if (hadVal) {
				cout << "Nhap vao vi tri: (gia tri truoc phan tu can them) "; cin >> y;
				cout << "Nhap vao gia tri muon them: "; cin >> x;
				if (insertBefore(y, x) == 0) {
					cout << "Them khong thanh cong !" << endl;
				}
				else {
					cout << "Them thanh cong !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao gia tri cho danh sach !" << endl;
			}
			break;
			break;
		default: // thoat
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
int insertBefore(int y, int x) {
	Node* pos = search(y);
	if (!pos) {
		if (first == last) {
			insertFirst(x);
			return 1;
		}
		pos = first;
		while (pos != NULL && pos->info < y) {
			pos = pos->next;
		}
	}
	else if (pos == first) {
		insertFirst(x);
		return 1;
	}
	Node* p = create(x);
	if (!p) return 0;
	pos->pre->next = p;
	p->pre = pos->pre;
	p->next = pos;
	pos->pre = p;
	return 1;
}
int delValue(int x) {
	Node* pos = search(x);
	if (!pos) return 0;
	if (pos == first) {
		delFirst();
	}
	else if (pos == last) {
		delLast();
	}
	else {
		pos->pre->next = pos->next;
		pos->next->pre = pos->pre;
		delete pos;
	}
	return 1;
}
Node* search(int x) {
	Node* p = first;
	while (p != NULL && p->info != x) {
		p = p->next;
	}
	return p;
}
int delLast() {
	if (!last) return 0;
	Node* p = last;
	if (last == first) {
		init();
		delete p;
		return 1;
	}
	p->pre->next = NULL;
	last = p->pre;
	delete p;
	return 1;
}
int delFirst() {
	if (!first) return 0;
	Node* p = first;
	if (first == last) {
		init();
		delete p;
		return 1;
	}
	first = first->next;
	first->pre = NULL;
	delete p;
	return 1;
}
int insertLast(int x) {
	Node* p = create(x);
	if (!p) return 0;
	Node* q = last;
	p->pre = last;

	if (!last) {
		first = p;
	}
	else {
		last->next = p;
	}
	last = p;
	return 1;
}
int insertFirst(int x) {
	Node* p = create(x);
	Node* q = first;
	if (!p) return 0;
	p->next = first;
	if (!first) {
		last = p;
	}
	else {
		q->pre = p;
	}
	first = p;
	return 1;
}
Node* create(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	p->pre = NULL;
	return p;
}
void output() {
	Node* p = first;
	cout << "Danh sach hien tai: ";
	while (p != NULL) {
		cout << p->info << "->";
		p = p->next;
	}
	cout << endl;
}
void init() {
	first = NULL;
	last = NULL;
}