#include<iostream>
#include<conio.h>

using namespace std;
struct Node {
	int info;
	Node* link;
};
typedef Node* node;
node first;
void init();
node createNode(int x);
void output();
node search(int x);
int insertFirst(int x);
int delFirst();
int insertLast(int x);
int delLast();
int delValue(int x);
void arrange();

int main() {
	int choice, x;
	init();
	do {
		system("cls");
		cout << "DANH SACH LIEN KET\n"
			<< "1. Xuat danh sach.\n"
			<< "2. Tim phan tu trong danh sach.\n"
			<< "3. Them phan tu vao dau danh sach.\n"
			<< "4. Xoa phan tu dau danh sach.\n"
			<< "5. Them phan tu vao cuoi danh sach.\n"
			<< "6. Xoa phan tu cuoi danh sach.\n"
			<< "7. Tim va xoa phan tu trong danh sach.\n"
			<< "8. Sap xep danh sach.\n"
			<< "9. Thoat\n"
			<< "Ban chon: "; cin >> choice;
		cout << endl;
		switch (choice) {
		case 1: // Xuat danh sach
			output();
			break;
		case 2: // Tim phan tu trong danh sach
			cout << "Nhap gia tri can tim: "; cin >> x;
			if (search(x) != NULL)
				cout << "Gia tri " << x << " co trong danh sach !" << endl;
			else {
				cout << "Khong ton tai x trong danh sach !" << endl;
			}
			break;
		case 3: // Them phan tu vao dau danh sach
			cout << "Nhap gia tri can them vao dau danh sach: ";
			cin >> x;
			if (insertFirst(x) == 1)
				cout << "Them thanh cong !" << endl;
			else
				cout << "Them khong thanh cong !" << endl;
			break;
		case 4: // Xoa phan tu dau danh sach
			if (delFirst() == 1)
				cout << "Xoa thanh cong !" << endl;
			else {
				cout << "Xoa khong thanh cong !" << endl;
			}
			break;
		case 5: // Them phan tu vao cuoi danh sach
			cout << "Nhap gia tri can them vao cuoi danh sach: ";
			cin >> x;
			if (insertLast(x) == 1)
				cout << "Them thanh cong !" << endl;
			else
				cout << "Them khong thanh cong !" << endl;
			break;
		case 6: // Xoa phan tu cuoi danh sach
			if (delLast() == 1)
				cout << "Xoa thanh cong !" << endl;
			else {
				cout << "Xoa khong thanh cong !" << endl;
			}
			break;
		case 7: // Tim va xoa phan tu trong danh sach
			cout << "Nhap gia tri can xoa trong danh sach: ";
			cin >> x;
			if (delValue(x) == 0) {
				cout << "Xoa khong thanh cong !" << endl;
			}
			else
				cout << "Xoa thanh cong !" << endl;
			break;
		case 8: // Sap xep
			arrange();
			break;
		default:
			return 0;
		}
		_getch();
	} while (true);
}

void arrange() {
	node p = first;
	node p2 = first;
	node q = NULL;
	while (p != NULL) {
		q = p;
		p2 = first;
		while (p2 != NULL) {
			if (q->info > p2->info) {
				int tmp = q->info;
				q->info = p2->info;
				p2->info = tmp;
			}
			p2 = p2->link;
		}
		p = p->link;
	}
}
int delValue(int x) {
	node q = search(x);
	if (q == NULL) return 0;
	if (q == first) delFirst();
	else {
		node p = first;
		while (p->link != q) {
			p = p->link;
		}
		p->link = q->link;
		delete q;
	}
	return 1;
}
int delLast() {
	if (first == NULL) return 0;
	node p = first;
	node f = NULL;
	while (p->link != NULL) {
		f = p;
		p = p->link;
	}
	f->link = NULL;
	delete p;
	return 1;
}
int insertLast(int x) {
	if (first == NULL) insertFirst(x);
	node p = first;
	node q = createNode(x);
	if (!q) return 0;
	while (p->link != NULL) {
		p = p->link;
	}
	p->link = q;
	return 1;
}
int delFirst() {
	if (first == NULL) return 0;
	node p = first;
	first = first->link;
	delete p;
	return 1;
}
int insertFirst(int x) {
	node p = first;
	node q = createNode(x);
	q->link = p;
	first = q;
	return 1;
}
node search(int x) {
	node p = first;
	while (p != NULL && p->info != x) {
		p = p->link;
	}
	return p;
}
void output() {
	if (first == NULL) {
		cout << "Khong co gia tri trong danh sach !" << endl;
		return;
	}
	node p = first;
	while (p != NULL) {
		cout << p->info << "->";
		p = p->link;
	}
	cout << endl;
}
node createNode(int x) {
	node p = new Node;
	p->info = x;
	p->link = NULL;
	return p;
}
void init() {
	first = NULL;
}