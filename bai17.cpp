// TIM GIAO, HOP, BU TRONG TAP HOP
#include<iostream>
#include<conio.h>
#include<iomanip>
#define MAX 100
using namespace std;
struct Node {
	int info;
	Node* next;
};
typedef Node* node;
void init(node& first);
node cre(int x);
void insert(node& first, int x);
void del(node& first);
void clean(node& first);
void input(node& first, int& n);
void output(node first);
void sort(node& first);
node search(node first, int x);
void laHop(node s1, node s2);
void laGiao(node s1, node s2);
void laBu(node s1, node s2);

node s1, s2;
int main() {
	int n, m, choice;
	bool hadValue = false;
	do {
		system("cls");
		cout << "=== TAP HOP ===\n"
			<< "1, Khoi tao.\n"
			<< "2, Nhap hai tap hop.\n"
			<< "3, Tim hop.\n"
			<< "4, Tim giao.\n"
			<< "5, Tim phan bu.\n"
			<< "6, Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1:// khoi tao
			init(s1); init(s2);
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2:// Nhap 
			cout << "Nhap tap hop thu nhat: " << endl;
			input(s1, n);
			cout << "Nhap tap hop thu hai: " << endl;
			input(s2, m);
			cout << endl << "Da nhap thanh cong !" << endl;
			hadValue = true;
			break;
		case 3:// tim hop
			if (!hadValue)
				cout << "Hai tap hop dau rong !" << endl;
			else {
				cout << "Hop cua hai tap hop: ";
				laHop(s1, s2);
			}
			break;
		case 4:// tim giao
			if (!hadValue)
				cout << "Hai tap hop dau rong !" << endl;
			else {
				cout << "Giao cua hai tap hop: ";
				laGiao(s1, s2);
			}
			break;
		case 5:// tim bu
			if (!hadValue)
				cout << "Hai tap hop dau rong !" << endl;
			else {
				cout << "Phan bu cua hai tap hop: ";
				laBu(s1, s2);
			}
			break;
		default:
			cout << "Da thoat chuong trinh !" << endl;
			clean(s1); clean(s2);
			return 0;
		}
		_getch();
	} while (true);
}

void laBu(node s1, node s2) {
	node tmp = NULL;
	node q = s2;
	while (q != NULL) {
		if (search(s1, q->info) == NULL) {
			insert(tmp, q->info);
		}
		q = q->next;
	}
	q = s1;
	while (q != NULL) {
		if (search(s2, q->info) == NULL) {
			insert(tmp, q->info);
		}
		q = q->next;
	}
	sort(tmp);
}
void laGiao(node s1, node s2) {
	node tmp = NULL;
	node q = s2;
	while (q != NULL) {
		if (search(s1, q->info) != NULL && search(tmp, q->info) == NULL) {
			insert(tmp, q->info);
		}
		q = q->next;
	}
	sort(tmp);
}
void laHop(node s1, node s2) {
	node tmp = NULL;
	node p = s1;
	while (p != NULL) {
		if (search(tmp, p->info) == NULL) {
			insert(tmp, p->info);
		}
		p = p->next;
	}
	node q = s2;
	while (q != NULL) {
		if (search(tmp, q->info) == NULL) {
			insert(tmp, q->info);
		}
		q = q->next;
	}
	sort(tmp);
}
node search(node first, int x) {
	node p = first;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
void sort(node& first) {
	node p = first;
	while (p != NULL) {
		node q = p->next;
		while (q != NULL) {
			if (p->info > q->info) {
				swap(p->info, q->info);
			}
			q = q->next;
		}
		p = p->next;
	}
	output(first);
}
void output(node first) {
	node p = first;
	while (p != NULL) {
		cout << p->info << " -> ";
		p = p->next;
	}
	cout << endl;
}
void input(node& first, int& n) {
	do {
		cout << "Nhap so phan tu: "; cin >> n;

	} while (n <= 0 || n > MAX);
	cout << "Nhap " << n << " gia tri: ";
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		insert(first, x);
	}
}
void clean(node& first) {
	while (first != NULL) {
		del(first);
	}
	init(first);
}
void del(node& first) {
	node p = first;
	if (!first) return;
	first = first->next;
	delete p;
}
void insert(node& first, int x) {
	node q = cre(x);
	if (q == NULL) return;
	q->next = first;
	first = q;
}
node cre(int x) {
	node p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
void init(node& first) {
	first == NULL;
}