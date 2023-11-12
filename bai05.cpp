#include<iostream>
#include<conio.h>
using namespace std;
struct Node {
	int info;
	Node* next;
};
Node* first;
void init();
void sort();
Node* create(int x);
int insertFirst(int x);
void output();
Node* search(int x);
void delFirst();
void delLast();
int delValue(int x);
void cleanLinkedList();

int main() {
	int choice, x;
	bool hadVal = false;
	do {
		system("cls");
		cout << "DANH SACH LIEN KET DON CO THU TU\n"
			<< "1. Khoi tao\n"
			<< "2. Xuat danh sach\n"
			<< "3. Them phan tu\n"
			<< "4. Tim phan tu\n"
			<< "5. Tim va xoa phan tu\n"
			<< "6. Thoat chuong trinh\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice){
		case 1: // khoi tao
			init();
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // xuat
			if (hadVal) {
				output();
			}
			else {
				cout << "Chua khoi tao phan tu trong danh sach !" << endl;
			}
			break;
		case 3: // them
			cout << "Nhap phan tu can them: "; cin >> x;
			if (insertFirst(x) == 0) {
				cout << "Them khong thanh cong !" << endl;
			}
			else {
				hadVal = true;
				cout << "Them thanh cong !" << endl;
			}
			break;
		case 4: // tim
			if (hadVal) {
				cout << "Nhap phan tu can tim: "; cin >> x;
				if (search(x) != NULL) {
					cout << "Ton tai phan tu trong danh sach, tai dia chi: " << search(x) << endl;
				}
				else {
					cout << "Khong ton tai trong danh sach !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao phan tu trong danh sach !" << endl;
			}
			break;
		case 5: // tim va xoa
			if (hadVal) {
				cout << "Nhap phan tu can xoa: "; cin >> x;
				if (delValue(x) == 0) {
					cout << "Xoa khong thanh cong !" << endl;
				}
				else {
					cout << "Xoa thanh cong !" << endl;
				}
			}
			else {
				cout << "Chua khoi tao phan tu trong danh sach !" << endl;
			}
			break;
		default:
			cout << "Thoat chuong trinh !" << endl;
			cleanLinkedList();
			return 0;
			break;
		}
		_getch();
	} while (true);
}

void cleanLinkedList() {
	while (first != NULL) {
		delFirst();
	}
	first = NULL;
}
int delValue(int x) {
	Node* pos = search(x);
	if (!pos)
		return 0;
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
void delLast() {
	if (!first) return;
	Node* p = first;
	Node* q = NULL;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}
	q->next = NULL;
	delete p;
}
void delFirst() {
	if (!first) return;
	Node* p = first;
	first = first->next;
	delete p;
}
Node* search(int x) {
	Node* p = first;
	while (p != NULL && p->info != x) {
		p = p->next;
	}
	return p;
}
void output() {
	Node* p = first;
	cout << "Danh sach hien tai la: ";
	while (p != NULL) {
		cout << p->info << "->";
		p = p->next;
	}
	cout << endl;
}
int insertFirst(int x) {
	Node* p = first;
	Node* q = create(x);
	if (!q) return 0;
	q->next = p;
	first = q;
	sort();
	return 1;
}
Node* create(int x) {
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void sort() {
	Node* p = first, *q = NULL;
	while (p->next != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->info > q->info) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
}
void init() {
	first = NULL;
}