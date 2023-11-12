#include<iostream>
#include<fstream>
#include<conio.h>
#define DISTANCE 10
using namespace std;
struct Tree {
	int info;
	Tree* left, * right;
};
Tree* root;
void init();
void input(Tree *&p, int x);
int inputFromFile(Tree*& p, char s[256]);
int search(Tree* p, int x);
void searchStandFor(Tree*& p, Tree*& q);
int deleteNode(Tree*& p, int x);
void processNLR(Tree* p);
void processLNR(Tree *p);
void processLRN(Tree *p);
int countNode(Tree* p);
int sum(Tree* p);
double ave(Tree* p);
int findMax(Tree* p);
bool checkNT(int x);
int countNT(Tree* p);
int countNodeLV2(Tree* p);
void printNodeLV2(Tree* p);
void deleteBST(Tree*& p);
void drawTree(Tree* p, int space);

int main() {
	bool initBST = false, hadVal = false;
	int choice, x;
	char s[256] = "BTH3_INPUT.txt";
	do {
		system("cls");
		if (!root)
			cout << "Danh sach hien dang trong !" << endl;
		else {
			drawTree(root, 0);
		}
		cout << "\n-----------------------------------------------\n"
			<< "1, Khoi tao BST.\n"
			<< "2, Nhap mot phan tu vao BST.\n"
			<< "3, Nhap phan tu vao BST tu file.\n"
			<< "4, Tim phan tu trong BST.\n"
			<< "5, Xoa mot phan tu trong BST.\n"
			<< "6, Duyet theo NLR.\n"
			<< "7, Duyet theo LNR.\n"
			<< "8, Duyet theo LRN.\n"
			<< "9, Dem so phan tu trong BST.\n"
			<< "10, Tinh trung binh cong tong phan tu trong BST.\n"
			<< "11, Tim gia tri lon nhat trong BST.\n"
			<< "12, Dem so phan tu la so nguyen to trong BST.\n"
			<< "13, Dem so node bac hai trong BST.\n"
			<< "14, Xuat cac node bac hai trong BST.\n"
			<< "16. Thoat chuong trinh.\n"
			<< "Ban chon chuc nang: "; cin >> choice;
		switch (choice) {
		case 1: // khoi tao 
			init();
			initBST = true;
			cout << "Khoi tao thanh cong !" << endl;
			break;
		case 2: // nhap tu ban phim
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				cout << "Nhap gia tri can them: ";
				cin >> x;
				input(root, x);
				cout << "Them thanh cong !" << endl;
				hadVal = true;
			}
			break;
		case 3: // nhap tu file
			if(!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (inputFromFile(root, s) == 0)
					cout << "Them khong thanh cong do khong tim thay file." << endl;
				else {
					cout << "Them thanh cong !" << endl;
					hadVal = true;
				}
			} 
			break;
		case 4: // tim phan tu
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "Nhap gia tri can tim: "; 
					cin >> x;
					if (search(root, x) == 0)
						cout << "Khong ton tai gia tri trong BST." << endl;
					else
						cout << "Ton tai gia tri trong BST." << endl;
				}
			}
			break;
		case 5: // xoa phan tu
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
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
		case 6: // duyet theo NLR
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					processNLR(root);
				}
			}
			break;
		case 7: // duyet theo LNR
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					processLNR(root);
				}
			}
			break;
		case 8: // duyet theo LRN
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					processLRN(root);
				}
			}
			break;
		case 9: // dem so phan tu
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "Tong cac node trong BST: " << countNode(root) << endl;
				}
			}
			break;
		case 10: // tinh trung binh cong tong so phan tu
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "Gia tri trung binh tong phan tu trong BST: " << ave(root) << endl;
				}
			}
			break;
		case 11: // tim gia tri lon nhat
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "Gia tri lon nhat trong BST: " << findMax(root) << endl;
				}
			}
			break;
		case 12: // dem so phan tu la so nguyen to
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "So node la so nguyen to trong BST: " << countNT(root) << endl;
				}
			}
			break;
		case 13: // dem so phan tu la node bac 2
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					cout << "Tong cac node bac hai trong BST: " << countNodeLV2(root) << endl;
				}
			}
			break;
		case 14: // xuat phan tu la node bac 2
			if (!initBST)
				cout << "Vui long khoi tao BST." << endl;
			else {
				if (!hadVal)
					cout << "BST hien dang rong ! Vui long nhap gia tri !" << endl;
				else {
					printNodeLV2(root);
				}
			}
			break;
		default:
			deleteBST(root);
			return 0;
			break;
		}

		_getch();
	} while (true);
}

void drawTree(Tree* p, int space) {
	if (!p) return;
	cout << endl;
	space += DISTANCE;
	drawTree(p->right, space);
	for (int i = DISTANCE; i < space; i++)
		cout << " ";
	cout << p->info;
	drawTree(p->left, space);
	cout << endl;

}
void deleteBST(Tree*& p) {
	if (!p) return;
	deleteBST(p->left);
	deleteBST(p->right);
	delete p;
}
void printNodeLV2(Tree* p) {
	if (p != NULL) {
		printNodeLV2(p->left);
		if (p->left && p->right)
			cout << p->info << "\t";
		printNodeLV2(p->right);
	}
}
int countNodeLV2(Tree* p) {
	if (!p) return 0;
	return (p->left && p->right) ? 1 + countNodeLV2(p->left) + countNodeLV2(p->right) : countNodeLV2(p->left) + countNodeLV2(p->right);
}
int countNT(Tree* p) {
	if (!p) return 0;
	return (checkNT(p->info))? 1 + countNT(p->left) + countNT(p->right) : countNT(p->left) + countNT(p->right);
}
bool checkNT(int x) {
	if (x < 2)
		return false;
	else {
		for (int i = 2; i < x; i++) {
			if (x % i == 0)
				return false;
		}
	}
	return true;
}
int findMax(Tree* p) {
	if (!p->right) return p->info;
	findMax(p->right);
}
double ave(Tree* p) {
	return (sum(p) * 1.00) / (countNode(p) * 1.00);
}
int sum(Tree* p) {
	if (!p) return 0;
	return p->info + countNode(p->left) + countNode(p->right);
}
int countNode(Tree* p) {
	if (!p) return 0;
	return 1 + countNode(p->left) + countNode(p->right);
}
void processLRN(Tree* p) {
	if (p != NULL) {
		processLRN(p->left);
		processLRN(p->right);
		cout << p->info << "\t";
	}
}
void processLNR(Tree* p) {
	if (p != NULL) {
		processLNR(p->left);
		cout << p->info << "\t";
		processLNR(p->right);
	}
}
void processNLR(Tree* p) {
	if (p != NULL) {
		cout << p->info << "\t";
		processNLR(p->left);
		processNLR(p->right);
	}
}
int deleteNode(Tree*& p, int x) {
	if (!p) return 0;
	if (p->info == x) {
		Tree* q = p;
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
void searchStandFor(Tree*& p, Tree*& q) {
	if (p->left == NULL) {
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int search(Tree* p, int x) {
	if (!p) return 0;
	if (p->info == x)
		return 1;
	else {
		if (p->info < x) return search(p->right, x);
		else return search(p->left, x);
	}
}
int inputFromFile(Tree*& p, char s[256]) {
	ifstream in;
	in.open(s, ios::in);
	if (!in.is_open()) return 0;
	int n;
	in >> n;
	for (int i = 0; i < n; i++) {
		int x;
		in >> x;
		input(p, x);
	}
	in.close();
	return 1;
}
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
void init() {
	root = NULL;
}