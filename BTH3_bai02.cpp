#include<iostream>
#include<conio.h>
using namespace std;
struct Node {
	int info;
	Node* left, * right;
};
struct Stack {
	Node* info;
	Stack* next;
};
struct Queue {
	Node* info;
	Queue* next;
};
Node* root;
Stack* sp;
Queue* front;
Queue* rear;
void init();
void initStack();
void initQueue();
int insert(Node*&p, int x);
Node* search(Node* p, int x);
int deleteNode(Node*& p, int x);
void searchStandFor(Node*& p, Node*& q);
void push(Node *p);
void pop(Node* &p);
bool isEmpty_Stack();
void processNLR(Node *p);
void processLNR(Node *p);
void processLRN(Node *p);


void input(Node*& p, int x);
int main() {
	int choice, x;
	bool hadInit = false, hadValue = false;
	do {
		system("cls");
		cout << "1, Khoi tao cay rong.\n"
			<< "2, Them mot phan tu vao cay.\n"
			<< "3, Tim mot phan tu trong cay.\n"
			<< "4, Xoa mot nut trong cay.\n"
			<< "5, Duyet Node - Left - Right (NLR).\n"
			<< "6, Duyet Left - Node - Right (LNR).\n"
			<< "7, Duyet Left - Right - Node (LRN).\n"
			<< "8, Thoat chuong trinh.\n"
			<< "Moi ban chon chuc nang: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao
			init();
			hadInit = true;
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // them phan tu
			if (!hadInit)
				cout << "Vui long khoi tao cay !" << endl;
			else {
				cout << "Nhap gia tri ban muon them: "; cin >> x;
				if (insert(root, x) == 1) {
					cout << "Nhap thanh cong !" << endl;
					hadValue = true;
				}
				else
					cout << "Nhap khong thanh cong !" << endl;
			}
			break;
		case 3: // tim
			if (!hadInit)
				cout << "Vui long khoi tao cay !" << endl;
			else {
				if (!hadValue)
					cout << "Cay hien dang rong !" << endl;
				else {
					cout << "Nhap gia tri can tim: "; cin >> x;
					if (search(root, x) != NULL)
						cout << "Ton tai trong cay nhi phan !" << endl;
					else
						cout << "Khong ton tai gia tri trong cay nhi phan !" << endl;
				}
			}
			break;
		case 4: // xoa
			if (!hadInit)
				cout << "Vui long khoi tao cay !" << endl;
			else {
				if (!hadValue)
					cout << "Cay hien dang rong !" << endl;
				else {
					cout << "Nhap gia tri can xoa: ";
					cin >> x;
					if (deleteNode(root, x) == 0)
						cout << "Xoa khong thanh cong !" << endl;
					else
						cout << "Xoa thanh cong !" << endl;
				}
			}
			break;
		case 5: // duyet nlr
			if (!hadInit)
				cout << "Vui long khoi tao cay !" << endl;
			else {
				if (!hadValue)
					cout << "Cay hien dang rong !" << endl;
				else {
					processNLR(root);
				}
			}
			break;
		case 6: // duyet lnr
			if (!hadInit)
				cout << "Vui long khoi tao cay !" << endl;
			else {
				if (!hadValue) 
					cout << "Cay hien dang rong !" << endl;
				else {
					processLNR(root);
				}
			}
			break;
		default:
			return 0;
			break;
		}

		_getch();
	} while (true);
}
void processLRN(Node* p) {
}
void processLNR(Node *p) {
	if (!p) return;
	initStack();
	do {
		while (p != NULL) {
			push(p);
			p = p->left;
		}
		Node* r = NULL;
		pop(r);
		cout << r->info << "\t";
		if (r->right != NULL) {
			p = r->right;
		}
	} while (isEmpty_Stack()!=true || p != NULL);
}
void processNLR(Node* p) {
	if (!p) return;
	initStack();
	do {
		while (p != NULL) {
			cout << p->info << "\t";
			push(p);
			p = p->left;
		}
		Node* r = NULL;
		pop(r);
		if (r->right != NULL) {
			p = r->right;
		}
	} while (isEmpty_Stack() != true || p != NULL);
}
bool isEmpty_Stack() {
	return sp == NULL;
}
void pop(Node* &p) {
	p = sp->info;
	Stack *q = sp;
	sp = sp->next;
	delete q;
}
void push(Node* p) {
	Stack* q = new Stack;
	q->info = p;
	q->next = sp;
	sp = q;
}
int deleteNode(Node*& p, int x) {
	if (!p) return 0;
	if (p->info == x) {
		Node* q = p;
		if (p->left == NULL)
			p = p->right;
		else if (p->right == NULL)
			p = p->left;
		else
			searchStandFor(q, p->right);
		delete q;
		return 1;
	}
	if (p->info < x) return deleteNode(p->right, x);
	if (p->info > x) return deleteNode(p->left, x);
}
void searchStandFor(Node*& p, Node*& q) {
	if (p->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
Node* search(Node* p, int x) {
	if (p) {
		while (p != NULL) {
			if (p->info == x)
				return p;
			else if (p->info < x)
				p = p->right;
			else
				p = p->left;
		}
	}
	return NULL;
}
/*
	void input(Tree *&p, int x) {
		if (!p) {
			p = new Tree;
			p->info = x;
			p->left = p->right = NULL;
		}
		else {
			if (p->info == x) return;
			else if (p->info < x) input(p->right, x);
			else input(p->left, x);
		}
	}
*/
int insert(Node *&p, int x) {
	Node* q = p;
	Node* f = NULL;
	while (q != NULL) {
		f = q;
		if (q->info == x)
			return 0;
		if (q->info < x) {
			q = q->right;
		}
		else {
			q = q->left;
		}
	}
	Node* r = new Node;
	r->info = x;
	r->left = NULL;
	r->right = NULL;
	if (!f) {
		p = r;
	}
	else {
		if (f->info < x) {
			f->right = r;
		}
		else {
			f->left = r;
		}
	}
	return 1;
}
void initQueue() {
	front = rear = NULL;
}
void initStack() {
	sp = NULL;
}
void init() {
	root = NULL;
}