#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
struct Node {
	int cap;
	int info;
	Node* next;
};
typedef Node* node;
void init(node& first);
node cre(int x, int i);
void push(node& first, int x, int i);
void pop(node& first);
void top(node first, int& x, int& i);
bool isEmpty(node p);
void input(node& first);
void output(node& first);
void sort(node& tmp);
node search(node x1, int x);
node cong(node &x1, node &x2);
node tru(node &x1, node &x2);
node nhan(node& x1, node& x2);

int main() {
	node x1 = NULL;
	node x2 = NULL;
	node p;
	int choice, x;
	do {
		system("cls");
		cout << "=== DANH SACH LIEN KET QUAN LY DA THUC ===\n"
			<< "1, Khoi tao danh sach.\n"
			<< "2, Nhap hai da thuc.\n"
			<< "3, Xuat hai da thuc.\n"
			<< "4, Cong hai da thuc.\n"
			<< "5, Tru hai da thuc.\n"
			<< "6, Nhan hai da thuc.\n"
			<< "7, Chia hai da thuc.\n"
			<< "8, Thoat chuong trinh.\n"
			<< "Ban chon: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init(x1); init(x2);
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // nhap
			cout << "Nhap da thuc thu nhat: " << endl;
			input(x1);
			cout << "Nhap da thuc thu hai: " << endl;
			input(x2);
			break;
		case 3: // xuat
			if (!isEmpty(x1)) {
				cout << "Da thuc thu nhat: "; output(x1);
				cout << "\nDa thuc thu hai: "; output(x2);
				cout << endl;
			}
			else
				cout << "Chua nhap hai da thuc !" << endl;
			break;
		case 4: // cong
			if (isEmpty(x1))
				cout << "Chua nhap hai da thuc !" << endl;
			else {
				p = NULL;
				p = cong(x1, x2);
				output(p);
				cout << endl;
			}
			break;
		case 5: // tru
			if (isEmpty(x1))
				cout << "Chua nhap hai da thuc !" << endl;
			else {
				p = NULL;
				p = tru(x1, x2);
				output(p);
				cout << endl;
			}
			break;
		case 6: // nhan
			if (isEmpty(x1))
				cout << "Chua nhap hai da thuc !" << endl;
			else {
				p = NULL;
				p = nhan(x1, x2);
				output(p);
				cout << endl;
			}
			break;
		default: 
			return 0;
			break;
		}
		_getch();
	} while (true);
}

node nhan(node& x1, node& x2) {
	node p = x1;
	node daThuc1 = NULL;
	while (p != NULL) {
		push(daThuc1, p->info, p->cap);
		p = p->next;
	}
	node tmp = NULL;
	while (daThuc1 != NULL) {
		node daThuc2 = x2;
		while (daThuc2 != NULL) {
			push(tmp, daThuc1->info * daThuc2->info, daThuc1->cap+daThuc2->cap);
			daThuc2 = daThuc2->next;
		}
		daThuc1 = daThuc1->next;
	}
	node kq = NULL;
	while (tmp != NULL) {
		node pos = search(kq, tmp->cap);
		if (pos == NULL) {
			push(kq, tmp->info, tmp->cap);
		}
		else {
			node k = kq;
			while (k != NULL && k != pos) {
				k = k->next;
			}
			k->info += tmp->info;
		}
		tmp = tmp->next;
	}
	return kq;
}
node tru(node& x1, node& x2) {
	node p = NULL;
	int x, i;
	while (!isEmpty(x1)) {
		top(x1, x, i);
		push(p, x, i);
		pop(x1);
	}
	while (!isEmpty(x2)) {
		top(x2, x, i);
		node pos = search(p, i);
		if (pos != NULL) {
			node q = p;
			while (q != NULL && q != pos) {
				q = q->next;
			}
			q->info -= x;
		}
		else {
			push(p, x, i);
		}
		pop(x2);
	}
	return p;
}
node cong(node &x1, node &x2) {
	node p = NULL;
	int x, i;
	while (!isEmpty(x1)) {
		top(x1, x, i);
		push(p, x, i);
		pop(x1);
	}
	while (!isEmpty(x2)) {
		top(x2, x, i);
		node pos = search(p, i);
		if (pos != NULL) {
			node q = p;
			while (q!=NULL && q != pos) {
				q = q->next;
			}
			q->info += x;
		}
		else {
			push(p, x, i);
		}
		pop(x2);
	}
	return p;
}
node search(node x1, int x) {
	node p = x1;
	while (p != NULL && p->cap != x) {
		p = p->next;
	}
	return p;
}
void sort(node& tmp) {
	node p = tmp;
	while (p->next != NULL) {
		node q = p->next;
		while (q != NULL) {
			if (p->cap < q->cap) {
				swap(p->info, q->info);
				swap(p->cap, q->cap);
			}
		}
		p = p->next;
	}
}
void output(node& first) {
	node p = first;
	while (p != NULL) {
		if (p->info > 0) {
			if (p->cap == 0)
				cout << " + " << p->info;
			else 
				cout << " + " << p->info << "x" << p->cap;
		}
		else {
			if (p->cap == 0)
				cout << p->info;
			else 
				cout << p->info << "x" << p->cap;
		}
		p = p->next;
	}
}
void input(node& first) {
	int n;
	char s[] = { 'a', 'b', 'c', 'd', 'e', 'f', 
		'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 
		'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
		'w', 'y', 'x', 'z' };
	do {
		cout << "Nhap cap cua da thuc: "; cin >> n;
		if (n<0 || n>MAX)
			cout << "Nhap sai, nhap lai !" << endl;
	} while (n < 0 || n>MAX);
	int x;
	cout << "Nhap he so lan luot theo da thuc: ";
	for (int i = n; i >=0; i--) {
		if (i == 0) {
			cout << s[n - i];
		}
		else {
			cout << s[n-i] << "x" << i << " + ";
		}
	}
	cout << endl;
	cout << "Bat dau nhap he so: ";
	for (int i = n; i >= 0; i--) {
		cin >> x;
		push(first, x, i);
	}
	cout << "Nhap thanh cong !" << endl;
}
bool isEmpty(node p) {
	return p == NULL;
}
void top(node first, int &x, int &i) {
	x = first->info;
	i = first->cap;
}
void pop(node& first) {
	if (!first) return;
	node p = first;
	first = first->next;
	delete p;
}
void push(node& first, int x, int i) {
	node q = cre(x, i);
	if (!q) return;
	node p = first;
	q->next = first;
	first = q;
}
node cre(int x, int i) {
	node p = new Node;
	p->info = x;
	p->cap = i;
	p->next = NULL;
	return p;
}
void init(node& first) {
	first = NULL;
}